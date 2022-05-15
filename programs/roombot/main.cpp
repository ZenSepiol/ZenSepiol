#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

#include "app.hpp"
#include "q_learning/q_learning.hpp"
#include "room_bot/room_bot.hpp"

enum class GuiState
{
    learning,
    show_run
};

class Map
{
  public:
    static const int size_x = 6;
    static const int size_y = 6;

    static constexpr std::array<std::array<bool, size_x>, size_y> map = {{{{true, true, true, true, true, true}},
                                                                          {{true, true, true, true, true, true}},
                                                                          {{true, false, false, false, false, false}},
                                                                          {{true, false, true, false, true, true}},
                                                                          {{true, false, true, false, true, true}},
                                                                          {{true, true, true, true, true, true}}}};
};

class MyApp : public App
{
  public:
    MyApp() = default;
    ~MyApp() = default;

    virtual void StartUp() final
    {
    }

    virtual void Update() final
    {
        if (gui_state == GuiState::learning)
        {
            float total_reward = 0.0;
            float clean_tiles = 0.0;

            for (int i = 0; i < number_of_epsiodes; ++i)
            {
                q_learning.Reset();
                while (q_learning.number_of_system_updates < moves)
                {
                    q_learning.Update();
                    total_reward += q_learning.last_reward;
                }

                auto tiles = q_learning.GetState().tiles;
                for (auto& row : tiles)
                {
                    for (auto& tile : row)
                    {
                        if (tile == TileState::clean)
                        {
                            clean_tiles++;
                        }
                    }
                }
            }

            total_reward_per_epsiode.push_back(total_reward / static_cast<float>(number_of_epsiodes));
            clean_tiles_average.push_back(clean_tiles / static_cast<float>(number_of_epsiodes));

            q_learning.Reset();
            q_learning.print = true;
            gui_state = GuiState::show_run;
        }
        else if (gui_state == GuiState::show_run)
        {
            if (q_learning.number_of_system_updates < moves)
            {
                q_learning.Update();
            }
            else
            {
                gui_state = GuiState::learning;
                q_learning.print = false;
            }
        }

        if (ImGui::Begin("Room Bot Statistics"))
        {
            if (ImPlot::BeginSubplots("My Subplot", 2, 1, ImVec2(1600, 400)))
            {
                if (ImPlot::BeginPlot("Average Clean Tiles"))
                {
                    ImPlot::SetupAxis(ImAxis_X1, "Average Clean Tiles", ImPlotAxisFlags_AutoFit);
                    ImPlot::SetupAxis(ImAxis_Y1, "Number of Episodes", ImPlotAxisFlags_AutoFit);

                    std::vector<float> local_samples(clean_tiles_average.size());
                    std::generate(local_samples.begin(), local_samples.end(), [n = 0]() mutable { return 1.0 * n++; });
                    ImPlot::PlotLine("Average clean tiles", local_samples.data(), clean_tiles_average.data(),
                                     clean_tiles_average.size());
                    ImPlot::EndPlot();
                }
                if (ImPlot::BeginPlot("Total Reward"))
                {
                    ImPlot::SetupAxis(ImAxis_X1, "Total Reward", ImPlotAxisFlags_AutoFit);
                    ImPlot::SetupAxis(ImAxis_Y1, "Number of Episodes", ImPlotAxisFlags_AutoFit);

                    std::vector<float> local_samples(total_reward_per_epsiode.size());
                    std::generate(local_samples.begin(), local_samples.end(), [n = 0]() mutable { return 1.0 * n++; });
                    ImPlot::PlotLine("Total Episode Reward", local_samples.data(), total_reward_per_epsiode.data(),
                                     total_reward_per_epsiode.size());
                    ImPlot::EndPlot();
                }
                ImPlot::EndSubplots();
            }
        }
        ImGui::End();

        if (ImGui::Begin("Room Bot Run"))
        {
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
        }
        ImGui::End();
    };

  private:
    QLearning<RoomBot<Map>> q_learning{RoomBot<Map>()};

    GuiState gui_state = GuiState::learning;

    int moves = 29;
    int number_of_epsiodes = 100;

    std::vector<float> total_reward_per_epsiode;
    std::vector<float> clean_tiles_average;
};

int main(int, char**)
{
    MyApp app;
    app.Run();

    return 0;
}
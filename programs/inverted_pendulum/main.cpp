#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

#include "app.hpp"
#include "inverted_pendulum/inverted_pendulum.hpp"
#include "q_learning/q_learning.hpp"
#include "spring/spring.hpp"

template <typename T>
void PopFront(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

class MyApp : public App
{
  public:
    MyApp() = default;
    ~MyApp() = default;

    virtual void StartUp() final
    {
        angle.push_back(0.0);
        position.push_back(0.0);
        samples.push_back(0.0);
    }

    virtual void Update() final
    {
        samples.clear();
        angle.clear();
        angle_dot.clear();
        position.clear();
        reward.clear();
        force.clear();
        total_reward = 0.0;

        while (1)
        {
            q_learning.Update();
            if (q_learning.passed_time > 10.0)
            {
                q_learning.Reset();
                break;
            }

            position.push_back(q_learning.GetState().position);
            angle.push_back(q_learning.GetState().angle);
            angle_dot.push_back(q_learning.GetState().angle_dot);
            samples.push_back(samples.back() + 1.0);
            reward.push_back(q_learning.last_reward);
            force.push_back(q_learning.previous_action->force);
            total_reward += q_learning.last_reward;

            // if (samples.size() > 1000)
            // {
            //     PopFront(samples);
            //     PopFront(angle);
            //     PopFront(position);
            //     PopFront(reward);
            //     PopFront(force);
            // }
        }

        total_reward_per_epsiode.push_back(total_reward);

        ImGui::Begin("Inverted Pendulum!");

        if (ImPlot::BeginSubplots("My Subplot", 5, 1, ImVec2(1200, 800)))
        {
            if (ImPlot::BeginPlot("Plot", "Number of Samples", "Total Reward"))
            {
                ImPlot::SetupAxis(ImAxis_X1, "Label", ImPlotAxisFlags_AutoFit);
                ImPlot::SetupAxis(ImAxis_Y1, "Label", ImPlotAxisFlags_AutoFit);

                std::vector<float> local_samples(total_reward_per_epsiode.size());

                std::generate(local_samples.begin(), local_samples.end(), [n = 0]() mutable { return 1.0 * n++; });

                ImPlot::PlotLine("Total Episode Reward", local_samples.data(), total_reward_per_epsiode.data(),
                                 total_reward_per_epsiode.size());
                ImPlot::EndPlot();
            }
            if (ImPlot::BeginPlot("Plot", "Number of Samples", "Position"))
            {
                ImPlot::SetupAxisLimits(ImAxis_X1, 0, 1000);
                ImPlot::SetupAxisLimits(ImAxis_Y1, -5, 5);
                ImPlot::PlotLine("Position", samples.data(), position.data(), position.size());
                ImPlot::EndPlot();
            }
            if (ImPlot::BeginPlot("Plot", "Number of Samples", "Angle"))
            {
                ImPlot::SetupAxisLimits(ImAxis_X1, 0, 1000);
                ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 2 * M_PI);
                ImPlot::PlotLine("Angle", samples.data(), angle.data(), angle.size());
                ImPlot::EndPlot();
            }
            if (ImPlot::BeginPlot("Plot", "Number of Samples", "Angle Dot"))
            {
                ImPlot::SetupAxisLimits(ImAxis_X1, 0, 1000);
                ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 2 * M_PI);
                ImPlot::PlotLine("Angle Dot", samples.data(), angle_dot.data(), angle_dot.size());
                ImPlot::EndPlot();
            }
            if (ImPlot::BeginPlot("Plot", "Number of Samples", "Reward"))
            {
                ImPlot::SetupAxisLimits(ImAxis_X1, 0, 1000);
                ImPlot::SetupAxisLimits(ImAxis_Y1, -0.1, 0.1);
                ImPlot::PlotLine("Reward", samples.data(), reward.data(), reward.size());
                ImPlot::EndPlot();
            }
            if (ImPlot::BeginPlot("Plot", "Number of Samples", "Force"))
            {
                ImPlot::SetupAxisLimits(ImAxis_X1, 0, 1000);
                ImPlot::SetupAxisLimits(ImAxis_Y1, -5, 5);
                ImPlot::PlotLine("Force", samples.data(), force.data(), force.size());
                ImPlot::EndPlot();
            }
            ImPlot::EndSubplots();
        }

        ImGui::End();
    }

  private:
    QLearning<InvertedPendulum> q_learning{InvertedPendulum(), InvertedPendulumReward, InvertedPendulumActions};
    std::vector<float> position;
    std::vector<float> angle;
    std::vector<float> angle_dot;
    std::vector<float> reward;
    std::vector<float> force;
    std::vector<float> samples;

    std::vector<float> total_reward_per_epsiode;
    float total_reward = 0.0;
};

int main(int, char**)
{
    MyApp app;
    app.Run();

    return 0;
}
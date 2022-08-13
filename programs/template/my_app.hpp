#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "app_base.hpp"

template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.front() = std::move(vec.back());
    vec.pop_back();
}

class MyApp : public AppBase
{
  public:
    MyApp(){
    };
    ~MyApp() = default;

    virtual void StartUp() final
    {
        for (int i = 0; i < 50; ++i)
        {
            frame_times.push_back(0.f);
        }
    }

    virtual void Update() final
    {
        ImGui::Begin("Tool");

        // Edit a color (stored as ~4 floats)
        ImGui::ColorEdit4("Color", my_color);

        // Plot some values
        ImGui::PlotLines("Frame Times", frame_times.data(), frame_times.size(), 0, 0, ImVec2(500, 500));

        ImGui::End();
    };

  private:
    float my_color[4];

    std::vector<float> frame_times;
};
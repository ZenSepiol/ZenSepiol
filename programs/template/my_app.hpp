#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "app_base.hpp"

template <typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.front() = std::move(vec.back());
    vec.pop_back();
}

class MyApp : public AppBase<MyApp>
{
  public:
    MyApp(){};
    virtual ~MyApp() = default;

    void StartUp()
    {
        for (int i = 0; i < 50; ++i)
        {
            frame_times.push_back(0.f);
        }
    }

    void Update()
    {
        ImGui::Begin("Tool");

        // Edit a color (stored as ~4 floats)
        ImGui::ColorEdit4("Color", my_color);

        // Plot some values
        ImGui::PlotLines("Frame Times", frame_times.data(), frame_times.size(), 0, 0, ImVec2(500, 500));

        ImGui::End();
    };

    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        // ONLY forward mouse data to your underlying app/game.
        ImGuiIO& io = ImGui::GetIO();
        if (!io.WantCaptureMouse)
            std::cout << "Button Clicked!: " << button << std::endl;
    }

    static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
    {
        // ONLY forward mouse data to your underlying app/game.
        ImGuiIO& io = ImGui::GetIO();
        if (!io.WantCaptureMouse)
            std::cout << "Cursor moved! x: " << xpos << " y: " << ypos << std::endl;
    }

  private:
    float my_color[4];

    std::vector<float> frame_times;
};
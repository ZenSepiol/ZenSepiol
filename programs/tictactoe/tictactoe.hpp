#include <iostream>
#include <stdio.h>

#include "app_base.hpp"

class TicTacToe : public AppBase<TicTacToe>
{
  public:
    TicTacToe(){};
    ~TicTacToe() = default;

    void StartUp()
    {
    }

    void Update()
    {
        ImGui::Begin("Tool");

        ImGui::End();

        // ImDrawList* draw = ImGui::GetBackgroundDrawList();
    }

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
};

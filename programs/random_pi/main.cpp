#include "app.hpp"
#include <vector>

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
        // Get framerate

        // Calculate next values and store in vector

        // Render vector graph

        ImGui::Begin("Random PI!");
        if (ImPlot::BeginPlot("Plot", "Number of Samples", "Estimated PI")) 
        {
            ImPlot::PlotLine("Test", samples.data(), pi_estimate.data(), pi_estimate.size());
            ImPlot::EndPlot();
        }
        ImGui::End();
    }

    private:
    std::vector<int> samples;
    std::vector<int> pi_estimate;

};

int main(int, char**)
{
    MyApp app;
    app.Run();

    return 0;
}
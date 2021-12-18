#include "app.hpp"
#include "icecream.hpp"
#include "random_pi.hpp"
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
        random_pi.AddSample();

        pi_estimate.push_back(random_pi.GetResult());
        samples.push_back(random_pi.GetSamples());
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
    RandomPi random_pi;
    std::vector<float> samples;
    std::vector<float> pi_estimate;

};

int main(int, char**)
{
    MyApp app;
    app.Run();

    return 0;
}
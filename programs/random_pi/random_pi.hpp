#include <vector>
#include <random>

class RandomPi
{
    public:
    RandomPi()
    {
        rng = std::mt19937(dev());
        dist = std::uniform_int_distribution<std::mt19937::result_type>(1,1000);
    }

    void AddSample()
    {
        float x = GetRandomNumber();
        float y = GetRandomNumber();

        float distance = x * x + y * y;
        if (distance < 1.0)
        {
            samples_inside_circle++;
        }
        samples++;
    }

    float GetResult()
    {
        float result = 4.0 * samples_inside_circle / samples;
        return result;
    }

    int GetSamples()
    {
        return samples;
    }

    private:
    float GetRandomNumber()
    {
        float result = dist(rng) / 1000.0;
        return result;
    }

    int samples = 0;
    int samples_inside_circle = 0;

    std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> dist;
};

#include <algorithm>
#include <cmath>
#include <set>

const float discretization = 1.0;

struct InvertedPendulumAction
{
    float force = 0.0;

    mutable float q_value = 0.0;

    friend bool operator==(const InvertedPendulumAction& e1, const InvertedPendulumAction& e2)
    {
        return (std::floor(e1.force * 10.0) == std::floor(e2.force * 10.0));
    };
};

template <>
struct std::hash<InvertedPendulumAction>
{
    std::size_t operator()(const InvertedPendulumAction& e) const
    {
        std::size_t hash_result = std::floor(e.force * discretization);
        // calculate the hash result

        return hash_result;
    }
};

struct InvertedPendulumState
{
    float position = 0.0;
    float position_dot = 0.0;
    float angle = 0.0;
    float angle_dot = 0.0;

    friend bool operator==(const InvertedPendulumState& e1, const InvertedPendulumState& e2)
    {
        bool equal =
            (std::floor(e1.position * discretization) == std::floor(e2.position * discretization)) &&
            (std::floor(e1.position_dot * discretization) == std::floor(e2.position_dot * discretization)) &&
            (std::floor(e1.angle * discretization) == std::floor(e2.angle * discretization)) &&
            (std::floor(e1.angle_dot * discretization) == std::floor(e2.angle_dot * discretization));
        return equal;
    };
};

template <>
struct std::hash<InvertedPendulumState>
{
    std::size_t operator()(const InvertedPendulumState& e) const
    {
        float prime = 37;

        std::size_t hash_result = std::floor(e.position * discretization);
        hash_result *= prime;
        hash_result += std::floor(e.position_dot * discretization);
        hash_result *= prime;
        hash_result += std::floor(e.angle * discretization);
        hash_result *= prime;
        hash_result += std::floor(e.angle_dot * discretization);

        return hash_result;
    }
};

float InvertedPendulumReward(const InvertedPendulumState& state)
{
    float desired_angle = 0.0;
    float desired_angle_dot = 0.0;
    float desired_position = 0.0;
    float reward = 0.0;

    float angle_diff = std::min((2.0 * M_PI) - std::abs(desired_angle - state.angle), 1.0 * std::abs(desired_angle - state.angle));
    reward += std::max(-20.0, 20.0 - 3.0 * angle_diff) * std::max(-20.0, 20.0 - 3.0 * angle_diff) * std::max(-20.0, 20.0 - 3.0 * angle_diff);
    reward += std::max(-20.0, 0.0 - 10.0 * std::abs(state.position - desired_position));
    reward += std::max(-20.0, 0.0 - 10.0 * std::abs(state.angle_dot - desired_angle_dot));
    // if (state.position > 0.8 || state.position < -0.8)
    // {
    //     reward -= 20.0;
    // }
    return reward;
}

std::unordered_set<InvertedPendulumAction> InvertedPendulumActions(const InvertedPendulumState& state)
{
    std::unordered_set<InvertedPendulumAction> set;

    for (int i = -5; i <= 5; ++i)
    {
        InvertedPendulumAction action;
        action.force = i * 10.0;

        set.insert(action);
    }
    return set;
}

class InvertedPendulum
{
  public:
    using Action = InvertedPendulumAction;
    using State = InvertedPendulumState;

    void Update(double time_step, Action action)
    {
        float cos = std::cos(state.angle);
        float sin = std::sin(state.angle);

        float position_dot_dot = (-mass * g * cos * sin) / (cart_mass + mass * sin * sin);
        position_dot_dot += (mass * length * sin * state.angle_dot * state.angle_dot) / (cart_mass + mass * sin * sin);
        position_dot_dot += (action.force) / (cart_mass + mass * sin * sin);

        float angle_dot_dot = ((mass + cart_mass) * g * sin) / (cart_mass + mass * sin * sin) * length;
        angle_dot_dot += (-mass * sin * cos * state.angle_dot * state.angle_dot) / (cart_mass + mass * sin * sin);
        angle_dot_dot += (-cos * action.force) / (cart_mass + mass * sin * sin) * length;

        state.position += state.position_dot * time_step;
        state.position_dot += position_dot_dot * time_step;
        state.angle += state.angle_dot * time_step;
        state.angle_dot += angle_dot_dot * time_step;

        if (state.angle > 2 * M_PI)
        {
            state.angle -= 2 * M_PI;
        }
        if (state.angle < 0.0)
        {
            state.angle += 2 * M_PI;
        }
    };

    void Reset()
    {
        state = State();
    };

    float mass = 0.2;
    float inertia = 0.006;
    float cart_mass = 0.5;
    float length = 0.3;
    float g = 9.81;

    float friction_constant = 0.1;

    State state;
};
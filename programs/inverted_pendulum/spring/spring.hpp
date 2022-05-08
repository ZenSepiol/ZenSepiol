
#include <algorithm>
#include <cmath>

struct SpringAction
{
    float force = 0.0;

    mutable float q_value = 0.0;

    friend bool operator==(const SpringAction& e1, const SpringAction& e2)
    {
        return (std::floor(e1.force) == std::floor(e2.force));
    };
};

template <>
struct std::hash<SpringAction>
{
    std::size_t operator()(const SpringAction& e) const
    {
        std::size_t hash_result = std::floor(e.force);
        // calculate the hash result

        return hash_result;
    }
};

struct SpringState
{
    float position = 0.0;

    friend bool operator==(const SpringState& e1, const SpringState& e2)
    {
        return (std::floor(e1.position * 10.0) == std::floor(e2.position * 10.0));
    };
};

template <>
struct std::hash<SpringState>
{
    std::size_t operator()(const SpringState& e) const
    {
        std::size_t hash_result = std::floor(e.position * 10.0);
        // calculate the hash result

        return hash_result;
    }
};

float SpringReward(const SpringState& state)
{
    float desired_position = 5.0;
    return std::max(-20.0, 20.0 - std::abs(state.position - desired_position));
}

std::unordered_set<SpringAction> SpringActions(const SpringState& state)
{
    std::unordered_set<SpringAction> set;

    for (float force = -5.0; force <= 5.0; force += 0.5)
    {
        SpringAction action;
        action.force = force;

        set.insert(action);
    }
    return set;
}

class Spring
{
  public:
    using Action = SpringAction;
    using State = SpringState;

    void Update(double time_step, Action action)
    {
        float position_dot = action.force - hook_constant * state.position;
        state.position += position_dot * time_step;
    };

    void Reset()
    {
        state = State();
    };

    float hook_constant = 0.2;

    State state;
};
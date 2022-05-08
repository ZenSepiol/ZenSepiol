#pragma once

#include <chrono>
#include <functional>
#include <icecream.hpp>
#include <random>
#include <unordered_map>
#include <unordered_set>

template <typename System>
class QLearning
{
  public:
    using Action = typename System::Action;
    using State = typename System::State;

    QLearning(const System& system, std::function<float(const State&)> get_reward,
              std::function<std::unordered_set<Action>(const State&)> get_possible_actions)
        : system(system), get_reward(get_reward), get_possible_actions(get_possible_actions)
    {
    }

    void Update()
    {
        Act(system.state);
        controller_calculated++;

        while (passed_time < controller_time_step * controller_calculated)
        {
            system.Update(time_step, *previous_action);
            passed_time += time_step;
        }
        // IC(system.state, action);
    }

    void Reset()
    {
        passed_time = 0.0;
        first_action = true;
        controller_calculated = 0;
        system.Reset();
    }

    void Act(const State& state)
    {
        if (Q.find(state) == Q.end())
        {
            Q[state] = std::unordered_set<Action>();
            for (const auto& action : get_possible_actions(state))
            {
                action.q_value = 1.0 + rand_percent(mt) / 1000.0;
                Q[state].insert(action);
            }
            IC(Q.size());
            // IC(state);
        }

        // IC(state);
        // IC(Q[state]);

        auto& actions = Q[state];
        if (!actions.empty())
        {
            if (is_learning)
            {
                // Update Q Matrix for the last action
                if (!first_action)
                {
                    float reward = get_reward(previous_state) * time_step;
                    last_reward = reward;
                    // IC(reward);

                    float max_q_value = actions.begin()->q_value;
                    for (auto& action : actions)
                    {
                        max_q_value = std::max(max_q_value, action.q_value);
                    }

                    float delta = learning_rate * (reward + discount_rate * max_q_value - previous_action->q_value);
                    previous_action->q_value += delta;
                }
                else
                {
                    IC(actions);
                    first_action = false;
                }

                // Choose action according to epsilon-greedy policy
                if (rand_percent(mt) < static_cast<int>(explore_rate * 100.f))
                {
                    std::vector<Action> out;
                    std::sample(actions.begin(), actions.end(), std::back_inserter(out), 1, mt);
                    previous_action = &out.back();
                }
                else
                {
                    previous_action = &(*actions.begin());
                    for (const auto& action : actions)
                    {
                        if (action.q_value > previous_action->q_value)
                        {
                            previous_action = &action;
                        }
                    }
                }
            }
            // Not learning: Exploit the current Q Matrix and choose the action with highest Q-Value
            else
            {
                for (const auto& action : actions)
                {
                    if (action->q_value > previous_action->q_value)
                    {
                        previous_action = &action;
                    }
                }
            }
        }

        previous_state = state;
    };

    typename System::State GetState()
    {
        return system.state;
    }

    float last_reward = 0.0;
    Action* previous_action;
    float passed_time = 0.0;

    float explore_rate = 0.2;

  private:
    System system;

    const float time_step = 0.001;
    const float controller_time_step = 0.01;
    int controller_calculated = 0;

    float learning_rate = 0.1;
    float discount_rate = 0.95;
    
    bool is_learning = true;

    std::unordered_map<State, std::unordered_set<Action>> Q;

    std::mt19937 mt = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> rand_percent{0, 99};

    State previous_state;

    bool first_action = true;

    std::function<float(const State&)> get_reward;
    std::function<std::unordered_set<Action>(const State&)> get_possible_actions;
};

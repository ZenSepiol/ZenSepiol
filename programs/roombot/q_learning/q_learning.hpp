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

    QLearning(const System& system) : system(system)
    {
    }

    void Update()
    {
        Act(system.state);

        while (number_of_system_updates < number_of_controller_updates * controller_system_update_ratio)
        {
            system.Update(time_step, previous_action);
            passed_time += time_step;
            number_of_system_updates++;
        }
        if (print)
        {
            std::cout << std::endl;
            std::cout << "*****NEW STATE*****" << std::endl;
            system.state.print();
        }
    }

    void Reset()
    {
        number_of_system_updates = 0;
        number_of_controller_updates = 0;
        first_action = true;
        system.Reset();
    }

    void Act(const State& state)
    {
        if (Q.find(state) == Q.end())
        {
            Q[state] = std::unordered_set<Action>();
            for (const auto& action : state.GetActions())
            {
                action.q_value = 0.0 + rand_percent(mt) / 1000.0;
                Q[state].insert(action);
            }
        }

        if (print)
        {
            std::cout << "********ACT********" << std::endl;
            state.print();
            for (auto& action : Q[state])
            {
                action.print();
            }
            IC(explore_rate);
        }

        auto& actions = Q[state];
        if (!actions.empty())
        {
            if (is_learning)
            {
                // Update Q Matrix for the last action
                if (!first_action)
                {
                    float reward = state.GetReward(previous_state) * time_step;
                    last_reward = reward;
                    if (print)
                    {
                        IC(reward);
                    }

                    float max_q_value = actions.begin()->q_value;
                    for (auto& action : actions)
                    {
                        max_q_value = std::max(max_q_value, action.q_value);
                    }

                    float delta = learning_rate * (reward + discount_rate * max_q_value - previous_action.q_value);
                    Q[previous_state].find(previous_action)->q_value += delta;
                }
                else
                {
                    first_action = false;
                }

                // Choose action according to epsilon-greedy policy
                if (rand_percent(mt) < static_cast<int>(explore_rate * 100.f))
                {
                    std::vector<Action> out;
                    std::sample(actions.begin(), actions.end(), std::back_inserter(out), 1, mt);
                    previous_action = out.back();
                }
                else
                {
                    previous_action = *actions.begin();
                    for (const auto& action : actions)
                    {
                        if (action.q_value > previous_action.q_value)
                        {
                            previous_action = action;
                        }
                    }
                }
            }
            // Not learning: Exploit the current Q Matrix and choose the action with highest Q-Value
            else
            {
                for (const auto& action : actions)
                {
                    if (action.q_value > previous_action.q_value)
                    {
                        previous_action = action;
                    }
                }
            }
        }

        previous_state = state;
        explore_rate *= explore_rate_decay;
        number_of_controller_updates++;
    };

    typename System::State GetState()
    {
        return system.state;
    }

    float last_reward = 0.0;
    Action previous_action;
    float passed_time = 0.0;
    int number_of_controller_updates = 0;
    int number_of_system_updates = 0;

    double explore_rate = 1.0;
    double explore_rate_decay = 0.999999;
    bool print = false;

  private:
    System system;

    const float time_step = 1.0;
    const int controller_system_update_ratio = 1;

    float learning_rate = 0.9;
    float discount_rate = 0.9;

    bool is_learning = true;

    std::unordered_map<State, std::unordered_set<Action>> Q;

    std::mt19937 mt = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> rand_percent{0, 99};

    State previous_state;

    bool first_action = true;
};

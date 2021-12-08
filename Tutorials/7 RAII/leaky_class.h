#pragma once

#include <string>
#include <mutex>

class LeakyClass
{
    public:
    LeakyClass(){};

    void OutputText(const std::string& string)
    {
        mutex.lock();

        if (IsStringTooLong(string))
            return;

        std::cout << string << std::endl;

        mutex.unlock();
    };

    private:
    bool IsStringTooLong(const std::string& string)
    {
        return (string.length() >= 25);
    };

    std::mutex mutex;
};
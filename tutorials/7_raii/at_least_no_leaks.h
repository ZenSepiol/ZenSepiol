#pragma once

#include <string>
#include <mutex>

class NotLeakyClass
{
    public:
    NotLeakyClass()
    {
        mutex.lock();
    };

    ~NotLeakyClass()
    {
        mutex.unlock();
    }

    void OutputText(const std::string& string)
    {
        if (IsStringTooLong(string))
            return;

        std::cout << string << std::endl;
    };

    private:
    bool IsStringTooLong(const std::string& string)
    {
        return (string.length() >= 25);
    };

    std::mutex mutex;
};
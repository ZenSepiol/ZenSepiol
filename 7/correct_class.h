#pragma once

#include <string>
#include <mutex>

class MutexHandler
{
    public:
    MutexHandler(std::mutex& mutex) : mutex(mutex)
    {
        mutex.lock();
    };

    ~MutexHandler()
    {
        mutex.unlock();
    };

    std::mutex& mutex;
};

class CorrectClass
{
    public:
    CorrectClass(){};

    void OutputText(const std::string& string)
    {
        MutexHandler mutex_handler(mutex);

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
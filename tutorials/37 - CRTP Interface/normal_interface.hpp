#include <icecream.hpp>
#include <stdint.h>

class NormalInterface
{
  public:
    virtual void Count(uint64_t n) = 0;
    virtual uint64_t GetValue() = 0;
};

class NormalImplemented : public NormalInterface
{
  public:
    NormalImplemented() : counter(0)
    {
    }

    virtual void Count(uint64_t n)
    {
        counter += n;
    }

    virtual uint64_t GetValue()
    {
        return counter;
    }

  private:
    uint64_t counter;
};

void RunNormal(NormalInterface* obj)
{
    const unsigned N = 40000;
    for (unsigned i = 0; i < N; ++i)
    {
        for (unsigned j = 0; j < i; ++j)
        {
            obj->Count(j);
        }
    }
    IC(obj->GetValue());
};

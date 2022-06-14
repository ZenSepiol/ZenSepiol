// Curiously recurring template pattern

template <typename Derived>
class Base
{
  public:
    Base() = default;

    void DoSomething()
    {
        Derived& derived = static_cast<Derived&>(*this);
        // use derived...
    }
};


class Derived : public Base<Derived>
{
  public:
    Derived() = default;
};

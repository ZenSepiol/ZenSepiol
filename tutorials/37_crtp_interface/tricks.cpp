
template <typename Derived>
class Base
{
    void DoSomething()
    {
        Derived& derived = static_cast<Derived&>(*this);
        // use derived...
    }

  private:
  Base() = default;
  friend Derived;
};


class Derived1 : public Base<Derived1>
{
  public:
    Derived1() = default;
};


class Derived2 : public Base<Derived1>
{
  public:
    Derived2() = default;
};


int main()
{
    Derived1 obj;
    Derived2 obj2;

    return 0;
}
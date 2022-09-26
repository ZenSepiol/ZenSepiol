class Limiter
{
  public:
  Limiter(int limit);

  void SetNumber(int input);
  int GetNumber();

  private:
  int number = 0;
  int limit = 0;
};
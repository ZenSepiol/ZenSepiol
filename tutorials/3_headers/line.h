class line_t
{
    public:
    line_t(float begin, float end);

    float GetLength();

    private:
    float begin;
    float end;
};
#include "line.h"

Line::Line(float begin, float end) : begin(begin), end(end)
{}

float Line::GetLength()
{
    return end - begin;
};
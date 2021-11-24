#include "line.h"

line_t::line_t(float begin, float end) : begin(begin), end(end)
{}

float line_t::GetLength()
{
    return end - begin;
};
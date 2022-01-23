#include "line.h"

Line_t::Line_t(float begin, float end) : begin(begin), end(end)
{}

float Line_t::GetLength()
{
    return end - begin; 
};
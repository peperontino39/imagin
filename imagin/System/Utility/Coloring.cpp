
#include "Coloring.h"

::Color Coloring::html(const std::string& str)
{
    if (str[0] != '#') return ::Color::white;
    if (str.size() != 7) return ::Color::white;

    ::Color col = ::Color::white;
    col.r() = std::stof("0X" + str.substr(1, 2)) / 256.0f;
    col.g() = std::stof("0X" + str.substr(3, 2)) / 256.0f;
    col.b() = std::stof("0X" + str.substr(5, 2)) / 256.0f;

    return col;
}
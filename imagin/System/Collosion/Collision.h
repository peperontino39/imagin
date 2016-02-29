#pragma once
#include "../../Top/Top.h"

class Colli
{
public:
    static bool rect_Point(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos);
    static bool rect_Rect(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos, const Vec2f& other_Size);
    static bool rect_Circle(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos, const float& other_Size);
    static bool circle_Point(const Vec2f& pos, const float& size, const Vec2f& other_Pos);
    static bool circle_Circle(const Vec2f& pos, const float& size, const Vec2f& other_Pos, const float& other_Size);
    static bool ellipse_Point(const Vec2f& pos, const Vec2f& size, const float& angle, const Vec2f& other_Pos);
private:
    Colli() {}
    ~Colli() {}
};
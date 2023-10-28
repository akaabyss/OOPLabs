#include "Circle_and_Ring.hpp"

Circle::Circle(const float &_r)
{
    r = _r;
}
float Circle::Square() const
{
    return PI * r * r;
}
void Circle::increase(const float &_delta)
{
    r *= _delta;
}
ostream &operator<<(ostream &stream, const Circle &object)
{
    stream << "R = " + to_string(object.r) + ", Square = " + to_string(object.Square()) + "\n\n";
    return stream;
}
istream &operator>>(istream &stream, Circle &object)
{
    stream >> object.r;
    return stream;
}

Ring ::Ring(const float &_r, const float &_rin) : Circle(_r)
{
    rin = _rin;
}
float Ring ::Square() const
{
    return PI * (r * r - rin * rin);
}
void Ring ::increase(const float &_delta)
{
    r *= _delta;
    rin *= _delta;
}
ostream &operator<<(ostream &stream, const Ring &object)
{
    stream << "R = " + to_string(object.r) + ", r = " + to_string(object.rin) + ", Square = " + to_string(object.Square()) + "\n\n";
    return stream;
}
istream &operator>>(istream &stream, Ring &object)
{
    // Внешний, потом внутренний радиус
    stream >> object.r >> object.rin;
    return stream;
}
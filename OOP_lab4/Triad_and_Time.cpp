#include "Triad_and_Time.hpp"

Triad::Triad(short _a, short _b, short _c)
{
    a = _a;
    b = _b;
    c = _c;
}
void Triad::plusA(short _delta)
{
    a += _delta;
}
void Triad::plusB(short _delta)
{
    b += _delta;
}
void Triad::plusC(short _delta)
{
    c += _delta;
}
void Triad::setA(short _A)
{
    a = _A;
}
void Triad::setB(short _B)
{
    b = _B;
}
void Triad::setC(short _C)
{
    c = _C;
}

short Triad::getA()
{
    return a;
}
short Triad::getB()
{
    return b;
}
short Triad::getC()
{
    return c;
}


void Time ::plusHour(const short &_hours)
{
    a += _hours;
}
void Time ::plusMin(const short &_minutes)
{
    b += _minutes;
    if (b >= 60)
    {
        b -= 60;
        a += 1;
    }
}
void Time ::plusSec(const short &_seconds)
{
    c += _seconds;
    if (c >= 60)
    {
        c -= 60;
        b += 1;
        if (b >= 60)
        {
            b -= 60;
            a += 1;
        }
    }
}

// void Time::plusTime(short _minutes, short _seconds)
// {
//     b += _minutes;
//     c += _seconds;
// }

void Time::setHour(short _h)
{
    a = _h;
}
void Time::setMin(short _m)
{
    b = _m;
    if (b >= 60)
    {
        b -= 60;
        a += 1;
    }
}
void Time::setSec(short _s)
{
    c = _s;
    if (c >= 60)
    {
        c -= 60;
        b += 1;
        if (b >= 60)
        {
            b -= 60;
            a += 1;
        }
    }
}

short Time::getHour()
{
    return a;
}
short Time::getMin()
{
    return b;
}
short Time::getSec()
{
    return c;
}
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

short Triad::getA() const
{
    return a;
}
short Triad::getB() const
{
    return b;
}
short Triad::getC() const
{
    return c;
}

void Time ::plusHour(const short &_delta)
{
    hours += _delta;
}
void Time ::plusMin(const short &_delta)
{
    minutes += _delta;
    if (minutes >= 60)
    {
        minutes -= 60;
        hours += 1;
    }
}
void Time ::plusSec(const short &_delta)
{
    seconds += _delta;
    if (seconds >= 60)
    {
        seconds -= 60;
        minutes += 1;
        if (minutes >= 60)
        {
            minutes -= 60;
            hours += 1;
        }
    }
}
void Time::setHour(short _h)
{
    hours = _h;
}
void Time::setMin(short _m)
{
    minutes = _m;
    normalize();
}

void Time::setSec(short _s)
{
    seconds = _s;
    normalize();
}
void Time::normalize()
{
    if (seconds >= 60)
    {
        seconds -= 60;
        minutes += 1;
    }
    if (minutes >= 60)
    {
        minutes -= 60;
        hours += 1;
    }
}
short Time::getHour() const
{
    return hours;
}
short Time::getMin() const
{
    return minutes;
}
short Time::getSec() const
{
    return seconds;
}
ostream &operator<<(ostream &stream, const Triad &object)
{
    stream << object.a << " "
           << object.b << " "
           << object.c << " ";
    return stream;
}
istream &operator>>(istream &stream, Triad &object)
{
    stream >> object.a >> object.b >> object.c;
    return stream;
}
ostream &operator<<(ostream &stream, const Time &object)
{
    stream << object.hours << " "
           << object.minutes << " "
           << object.seconds << " ";
    return stream;
}
istream &operator>>(istream &stream, Time &object)
{
    stream >> object.hours >> object.minutes >> object.seconds;
    object.normalize();
    return stream;
}
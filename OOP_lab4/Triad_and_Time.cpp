#include "Triad_and_Time.hpp"

Triad::Triad(short _a, short _b, short _c)
{
    a = _a;
    b = _b;
    c = _c;
}
Triad Triad::plusA(const short &_delta)
{
    a += _delta;
    return *this;
}
Triad Triad::plusB(const short &_delta)
{
    b += _delta;
    return *this;
}
Triad Triad::plusC(const short &_delta)
{
    c += _delta;
    return *this;
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
// здесь должна вызываться plus от базового класса
Time Time ::plusHour(const short &_delta)
{
    hours += _delta;
    Triad p = plusA(_delta);
    Time time = Time(p.getA(), p.getB(), p.getC());
    time.normalize();
    return time;
}
Time Time ::plusMin(const short &_delta)
{
    minutes += _delta;
    Triad p = plusB(_delta);
    Time time = Time(p.getA(), p.getB(), p.getC());
    time.normalize();
    return time;
}
// Time* plusSec везде
Time Time ::plusSec(const short &_delta)
{
    seconds += _delta;
    Triad p = plusC(_delta);
    Time time = Time(p.getA(), p.getB(), p.getC());
    time.normalize();
    return time;
}
void Time::setHour(short _h)
{
    setA(_h);
}
void Time::setMin(short _m)
{
    setB(_m);
    normalize();
}

void Time::setSec(short _s)
{
    setC(_s);
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
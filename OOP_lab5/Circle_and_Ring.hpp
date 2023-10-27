#include <iostream>
#include <cmath>
#include <string>
const float PI = acos(-1);
using namespace std;

class Circle
{
protected:
    float r;

public:
    Circle(const float &_r = 0)
    {
        r = _r;
    }
    virtual float Square() const
    {
        return PI * r * r;
    }
    virtual void increase(const float &_delta)
    {
        r *= _delta;
    }
    friend ostream &operator<<(ostream &stream, const Circle &object)
    {
        stream << "R = " + to_string(object.r) + ", Square = " + to_string(object.Square()) + "\n\n";
        return stream;
    }
};

class Ring : Circle
{
    float rin;

public:
    Ring(const float &_r, const float &_rin) : Circle(_r)
    {
        rin = _rin;
    }
    float Square() const 
    {
        return PI * (r * r - rin * rin);
    }
    void increase(const float &_delta)
    {
        r *= _delta;
        rin *= _delta;
    }
    friend ostream &operator<<(ostream &stream, const Ring &object)
    {
        stream << "R = " + to_string(object.r) + ", r = " + to_string(object.rin) + ", Square = " + to_string(object.Square()) + "\n\n";
        return stream;
    }
};
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
    Circle(const float &_r = 1)
    {
        r = _r;
    }
    Circle(const Circle &object)
    {
        r = object.r;
    }

    virtual float Square() const
    {
        return PI * r * r;
    }
    virtual void increase(const float &_delta)
    {
        r *= _delta;
    }
    virtual Circle &operator+(const float &delta)
    {
        r += delta;
        return *this;
    }

    friend ostream &operator<<(ostream &stream, const Circle &object)
    {
        stream << "R = " + to_string(object.r) + ", Square = " + to_string(object.Square()) + "\n\n";
        return stream;
    }
    friend istream &operator>>(istream &stream, Circle &object)
    {
        stream >> object.r;
        return stream;
    }
    Circle operator=(const Circle &object)
    {
        return Circle(object.r);
    }
};

class Ring : public Circle
{
    float rin;

public:
    // Внешний, потом внутренний
    Ring(const float &_r, const float &_rin) : Circle(_r), rin(_rin) {}

    float Square() const
    {
        return Circle::Square() - PI * rin * rin;
    }
    void increase(const float &_delta = 1)
    {
        Circle::increase(_delta);
        rin *= _delta;
    }

    Ring &operator+(const float &delta)
    {
        // r += delta;
        *this = *this + 5; // Circle::operator+
        rin += delta;
        return *this;
    }
    friend ostream &operator<<(ostream &stream, const Ring &object)
    {
        stream << "R = " + to_string(object.r) + ", r = " + to_string(object.rin) + ", Square = " + to_string(object.Square()) + "\n\n";
        return stream;
    }
    friend istream &operator>>(istream &stream, Ring &object)
    {
        // Внешний, потом внутренний радиус
        stream >> object.r >> object.rin;
        return stream;
    }
    Ring operator=(const Ring &object)
    {
        return Ring(object.r, object.rin);
    }
};
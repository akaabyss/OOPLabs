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
    Circle(const float &_r = 1);
    Circle(const Circle &object);
    // virtual
    float Square() const
    {
        return PI * r * r;
    }

    void increase(const float &_delta);
    // virtual
    Circle &operator+(const float &delta)
    {
        r += delta;
        return *this;
    }
    friend ostream &operator<<(ostream &stream, const Circle &object);
    friend istream &operator>>(istream &stream, Circle &object);
};

class Ring : public Circle
{
    float rin;

public:
    // Внешний, потом внутренний
    Ring(const float &_r, const float &_rin);

    float Square() const;

    void increase(const float &_delta = 1);
    Ring &operator+(const float &delta)
    {
        r += delta;
        rin += delta;
        return *this;
    }
    friend ostream &operator<<(ostream &stream, const Ring &object);
    friend istream &operator>>(istream &stream, Ring &object);
};
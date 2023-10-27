#include <iostream>
using namespace std;

class Triad
{
protected:
    short a, b, c;

public:
    Triad(short _a = 0, short _b = 0, short _c = 0);
    void setA(short _A);
    void setB(short _B);
    void setC(short _C);

    short getA();
    short getB();
    short getC();

    void plusA(short _delta = 1);
    void plusB(short _delta = 1);
    void plusC(short _delta = 1);
};

class Time : Triad
{

public:
    Time(short _hours = 0, short _minutes = 0, short _seconds = 0) : Triad(_hours, _minutes, _seconds) {}

    void setHour(short _s);
    void setMin(short _m);
    void setSec(short _h);

    short getHour();
    short getMin();
    short getSec();

    void plusHour(const short &_hours = 1);
    void plusMin(const short &_minutes = 1);
    void plusSec(const short &_seconds = 1);
    // void plusTime(short _minutes = 0, short _seconds = 0);
};
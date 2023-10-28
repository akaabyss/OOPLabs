#include "Circle_and_Ring.hpp"

int main()
{
    float delta = 1.5;
    Circle circle(5);
    Ring ring(5, 3); //внешний, внутренний
    cout << circle;
    cout << ring;

    circle.increase(delta);
    ring.increase(delta);

    cout << circle;
    cout << ring;
    system("pause");
}
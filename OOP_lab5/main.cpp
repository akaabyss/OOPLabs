#include "Circle_and_Ring.hpp"
// ввод: внешний, внутренний
int main()
{
    float delta = 1.5;

    Circle circle(5);
    Ring ring(5, 3);
    cout << ring
         << '\n'
         << circle;

    ring.increase(delta);
    circle.increase(delta);

    cout << "\n\n"
         << ring
         << '\n'
         << circle;

    system("pause");
}
#include "Circle_and_Ring.hpp"
// ввод: внешний, внутренний
int main()
{
    // float delta = 1.5;

    Circle circle(5);
    Circle *d_circle = &circle;
    cout<<d_circle->Square();

    Ring ring(5, 3);

    d_circle = &ring;
    cout<<d_circle->Square();


    // Circle circle(5);
    // cout << "Enter a circle(R)->";
    // cin >> circle;
    // Ring ring(5, 3); // внешний, внутренний
    // cout << circle;
    // cout << "\nEnter a ring(R, rin)->";
    // cin >> ring;
    // cout << ring;

    // // circle.increase(delta);
    // // ring.increase(delta);
    // circle = circle + delta;
    // ring = ring + delta;

    // cout << "circle after delta " << circle;
    // cout << "ring after delta" << ring;
    system("pause");
}
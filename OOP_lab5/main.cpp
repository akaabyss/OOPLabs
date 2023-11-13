#include "PointCircleRing.hpp"

int main()
{
    Point x(5);

    Point *y = &x;

    cout << *y;

    Circle z(5);

    Point *d = &z;

    cout << "\n"
         << *d;

    Ring f(5, 4);

    Circle *s = &f;

    cout << "\n"
         << f;

    system("pause");
    return 0;
}

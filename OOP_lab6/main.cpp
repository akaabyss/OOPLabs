#include "class.hpp"

int main()
{
    MyVector<int> x;
    MyVector<int> y;
    y.addElements({1, 2, 3});
    x.addElements({5, 6, 7, 8, 9, 1, 2, 3, 4, 5});
    // x.addElements({3, 4, 5, 6, 7, 8, 9});
    // x.replace(3, 10);
    x.removeGroup(y.begin(), y.end());
    cout << x;

    system("pause");
}
#include <iostream>
using namespace std;
#include "2D_shapes.h"
using namespace TwoDShapes;

int main()
{
    Square s;
    s.setSide(5);
    cout << "Perimeter of square: " << s.perimeter() << endl;
    cout << "Area of square: " << s.area() << endl;
    return 0;
}
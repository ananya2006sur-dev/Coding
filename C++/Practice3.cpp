#include <iostream>
using namespace std;
#include "3D_shapes.h"
using namespace ThreeDShapes;

int main()
{
    Cuboid c;
    c.setLength(5);
    c.setWidth(3);
    c.setHeight(2);
    cout << "Surface area of cuboid: " << c.surfaceArea() << endl;
    cout << "Lateral surface area of cuboid: " << c.LsurfaceArea() << endl;
    cout << "Volume of cuboid: " << c.volume() << endl;
    return 0;
}
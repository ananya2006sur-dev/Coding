#include "Cube.h"
using namespace iuic;

Cube* CreateUnitCube()
{
    Cube cube; 
    cube.setLength(15);
    return &cube;
}

int main()
{
    Cube* c = CreateUnitCube();
    double a = c->getSurfaceArea();
    double v = c->getVolume();
    return 0;

}


#pragma once

namespace iuic
{
    class Cube
    {   
        private:
        double side_;

        Cube(); // default constructor
        Cube(double side_); // parameterized constructor

        public:
        double surfaceArea();
        double volume();
    };
}

double iuic::Cube::surfaceArea()
{
    return 6 * side_ * side_;
}

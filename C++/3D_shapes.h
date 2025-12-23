#pragma once
#define PI 3.14159 
#include <cmath>
using std::sqrt;

namespace ThreeDShapes
{
    class Cuboid
    {
        public:
        double surfaceArea();
        double LsurfaceArea();
        double volume();
        void setLength(double length);
        void setWidth(double width);
        void setHeight(double height);

        private:
        double length_;
        double width_;
        double height_;
    };

    class Cube
    {
        public:
        double surfaceArea();
        double LsurfaceArea();
        double volume();
        void setSide(double side);

        private:
        double side_;
    };

    class Sphere
    {
        public:
        double surfaceArea();
        double volume();
        void setRadius(double radius);

        private:
        double radius_;
    };

    class Cone
    {
        public:
        double surfaceArea();
        double LsurfaceArea();
        double volume();
        void setRadius(double radius);
        void setHeight(double height);

        private:
        double radius_;
        double height_;
    };

    class Hemisphere
    {
        public:
        double surfaceArea();
        double LsurfaceArea();
        double volume();
        void setRadius(double radius);

        private:
        double radius_;
    };
    
};

double ThreeDShapes::Cuboid::surfaceArea()
{
    return 2 * (length_ * width_ + width_ * height_ + height_ * length_);
}

double ThreeDShapes::Cuboid::LsurfaceArea()
{
    return 2 * (width_ * height_ + height_ * length_);
}

double ThreeDShapes::Cuboid::volume()
{
    return length_ * width_ * height_;
}

double ThreeDShapes::Cube::surfaceArea()
{
    return 6 * side_ * side_;
}

double ThreeDShapes::Cube::LsurfaceArea()
{
    return 4 * side_ * side_;
}

double ThreeDShapes::Cube::volume()
{
    return side_ * side_ * side_;
}

double ThreeDShapes::Sphere::surfaceArea()
{
    return 4 * PI * radius_ * radius_;
}

double ThreeDShapes::Sphere::volume()
{
    return (4.0/3.0) * PI * radius_ * radius_ * radius_;
}

double ThreeDShapes::Cone::surfaceArea()
{
    return PI * radius_ * (radius_ + sqrt(height_ * height_ + radius_ * radius_));
}

double ThreeDShapes::Cone::LsurfaceArea()
{
    return PI * radius_ * sqrt(height_ * height_ + radius_ * radius_);
}

double ThreeDShapes::Cone::volume()
{
    return (1.0/3.0) * PI * radius_ * radius_ * height_;
}

double ThreeDShapes::Hemisphere::surfaceArea()
{
    return 3 * PI * radius_ * radius_;
}

double ThreeDShapes::Hemisphere::LsurfaceArea()
{
    return 2 * PI * radius_ * radius_;
}

double ThreeDShapes::Hemisphere::volume()
{
    return (2.0/3.0) * PI * radius_ * radius_ * radius_;
}

void ThreeDShapes::Cuboid::setLength(double length)
{
    length_ = length;
}

void ThreeDShapes::Cuboid::setWidth(double width)
{
    width_ = width;
}

void ThreeDShapes::Cuboid::setHeight(double height)
{
    height_ = height;
}

void ThreeDShapes::Cube::setSide(double side)
{
    side_ = side;
}

void ThreeDShapes::Sphere::setRadius(double radius)
{
    radius_ = radius;
}

void ThreeDShapes::Cone::setRadius(double radius)
{
    radius_ = radius;
}

void ThreeDShapes::Cone::setHeight(double height)
{
    height_ = height;
}

void ThreeDShapes::Hemisphere::setRadius(double radius)
{
    radius_ = radius;
}


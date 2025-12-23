#pragma once
#include <cmath>
using std::sqrt;
#define PI 3.14159 

namespace TwoDShapes
{
    class Square
    {
        public:
        double perimeter();
        double area();
        void setSide(double side);

        private:
        double side_;
    };

    class Rectangle
    {
        public:
        double perimeter();
        double area();
        void setLength(double length);
        void setWidth(double width);

        private:
        double length_;
        double width_;
    };

    class Circle
    {
        public:
        double circumference();
        double area();
        void setRadius(double radius);

        private:
        double radius_;
    };

    class Triangle
    {
        public:
        double perimeter();
        double area();
        void setSide1(double side1);
        void setSide2(double side2);
        void setSide3(double side3);

        private:
        double side1_;
        double side2_;
        double side3_;
    };
};

double TwoDShapes::Square::perimeter()
{
    return 4 * side_;
}

double TwoDShapes::Square::area()
{
    return side_ * side_;
}

void TwoDShapes::Square::setSide(double side)
{
    side_ = side;
}

double TwoDShapes::Rectangle::perimeter()
{
    return 2 * (length_ + width_);
}

double TwoDShapes::Rectangle::area()
{
    return length_ * width_;
}

void TwoDShapes::Rectangle::setLength(double length)
{
    length_ = length;
}

void TwoDShapes::Rectangle::setWidth(double width)
{
    width_ = width;
}

double TwoDShapes::Circle::circumference()
{
    return 2 * PI * radius_;
}

double TwoDShapes::Circle::area()
{
    return PI * radius_ * radius_;
}

void TwoDShapes::Circle::setRadius(double radius)
{
    radius_ = radius;
}

double TwoDShapes::Triangle::perimeter()
{
    return side1_ + side2_ + side3_;
}

double TwoDShapes::Triangle::area()
{
    double s = (side1_ + side2_ + side3_)/2;
    return sqrt(s * (s - side1_) * (s - side2_) * (s - side3_));
}
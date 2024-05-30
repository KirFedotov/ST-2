// Copyright 2024 Fedotov Kirill
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
#include <cmath>
#define M_PI 3.14159265358979323846

class Circle {
 private:
    double area;
    double ference;
    double radius;

 public:
    explicit Circle(double radius = 0.0);

    void setArea(double area);
    void setFerence(double ference);
    void setRadius(double radius);

    double getArea() const;
    double getFerence() const;
    double getRadius() const;
};

#endif  // INCLUDE_CIRCLE_H_

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <cmath>

struct Point {
    double X, Y;

    double DistanceTo(Point Other) const;
};

struct Triangle {
    Point A, B, C;

    double GetArea(Point A, Point B, Point C) const;
    double GetArea() const;

    bool IsDegenerate() const;

    double GetCrossProduct(Point P1, Point P2, Point P) const;

    std::string GetCrossPointLocation(Point P) const;
    std::string GetPointLocationHeron(Point P) const;
};

// Для трикутника з площею 0
bool IsPointOnSegment(Point A, Point B, Point P);

#endif
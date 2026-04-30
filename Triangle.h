#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

struct Point {
    double X, Y;
};

struct Triangle {
    Point A, B, C;

    double GetArea(Point A, Point B, Point C) const;
    double GetArea() const;

    bool IsDegenerate() const;
    bool IsDegeneratePrint() const;

    double GetCrossProduct(Point P1, Point P2, Point P) const;

    std::string GetCrossPointLocation(Point P) const;
    std::string GetPointLocationHeron(Point P) const;
};

bool IsPointOnSegment(Point A, Point B, Point P);

#endif
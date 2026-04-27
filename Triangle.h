#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <cmath>
#include <algorithm>

struct Point {
    double X, Y;

    double DistanceTo(const Point& Other) const;
};

struct Triangle {
    Point A, B, C;

    double GetArea(const Point& A, const Point& B, const Point& C) const;
    double GetArea() const;

    bool IsDegenerate() const;

    double Cross(const Point& P1, const Point& P2, const Point& P) const;

    std::string GetCrossPointLocation(const Point& P) const;
    std::string GetPointLocationHeron(const Point& P) const;
};

bool IsPointOnSegment(const Point& A, const Point& B, const Point& P);

#endif
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <string>

struct Point {
    double x, y;
};

enum class Location { Inside, OnEdge, Outside };

double CrossProduct(Point a, Point b, Point p);

bool isDegenerate(Point a, Point b, Point c);

Location CheckPointInTriangle(Point a, Point b, Point c, Point p);

std::string LocationToString(Location loc);

#endif
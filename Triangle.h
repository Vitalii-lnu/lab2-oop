#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <vector>

struct Point {
    double X;
    double Y;
};

struct Triangle {
    Point A, B, C;
};

// Перевірка на виродженість
bool IsTriangleDegenerate(Triangle T);

// Обчислення векторного добутку
double GetCrossProduct(Point P1, Point P2, Point P3);

// Визначення позиції точки
std::string GetPointLocation(Triangle T, Point P);

#endif
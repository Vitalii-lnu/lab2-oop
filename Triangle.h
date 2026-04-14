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

    // Обчислення площі за формулою герона
    double GetArea(Point A, Point B, Point C) const;

    double GetArea() const;

    // Перевірка на виродженість
    bool IsDegenerate() const;

    // Векторний добуток для перевірки точки
    double GetCrossProduct(Point P1, Point P2, Point P) const;

    // Методом герона для перевірки точки
    std::string GetPointLocationHeron(Point P) const;


    std::string GetCrossPointLocation(Point P) const;
};




#endif
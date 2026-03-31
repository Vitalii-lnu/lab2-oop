#include "Triangle.h"

// Реалізація методів Point
double Point::DistanceTo(Point Other) const {
    return std::sqrt(std::pow(Other.X - X, 2) + std::pow(Other.Y - Y, 2));
}

// Реалізація методів Triangle
double Triangle::GetArea() const {
    double a = A.DistanceTo(B);
    double b = B.DistanceTo(C);
    double c = C.DistanceTo(A);
    double s = (a + b + c) / 2.0; // Півпериметр
    
    // Формула Герона
    double areaSq = s * (s - a) * (s - b) * (s - c);
    return std::sqrt(std::max(0.0, areaSq)); 
}

bool Triangle::IsDegenerate() const {
    // Трикутник вироджений, якщо площа рівна 0
    return GetArea() < 1e-9;
}

double Triangle::GetCrossProduct(Point P1, Point P2, Point P) const {
    return (P2.X - P1.X) * (P.Y - P1.Y) - (P2.Y - P1.Y) * (P.X - P1.X);
}

std::string Triangle::GetPointLocation(Point P) const {
    double CP1 = GetCrossProduct(A, B, P);
    double CP2 = GetCrossProduct(B, C, P);
    double CP3 = GetCrossProduct(C, A, P);

    bool HasNeg = (CP1 < -1e-9) || (CP2 < -1e-9) || (CP3 < -1e-9);
    bool HasPos = (CP1 > 1e-9) || (CP2 > 1e-9) || (CP3 > 1e-9);

    if (HasNeg && HasPos) return "Зовні";
    
    if (std::abs(CP1) < 1e-9 || std::abs(CP2) < 1e-9 || std::abs(CP3) < 1e-9) 
        return "На межі";

    return "Всередині";
}
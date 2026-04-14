#include "Triangle.h"

double Point::DistanceTo(Point Other) const {
    return std::sqrt(std::pow(Other.X - X, 2) + std::pow(Other.Y - Y, 2));
}


double Triangle::GetArea(Point A, Point B, Point C) const {
    double a = A.DistanceTo(B);
    double b = B.DistanceTo(C);
    double c = C.DistanceTo(A);
    double s = (a + b + c) / 2.0; // Півпериметр
    
    // Формула Герона
    double areaSq = s * (s - a) * (s - b) * (s - c);
    return std::sqrt(std::max(0.0, areaSq)); 
}

double Triangle::GetArea() const{
    return GetArea(A, B, C);
}

bool Triangle::IsDegenerate() const {
    // Трикутник вироджений, якщо площа рівна 0
    return GetArea(A, B, C) < 1e-9f;
}

double Triangle::GetCrossProduct(Point P1, Point P2, Point P) const {
    return (P2.X - P1.X) * (P.Y - P1.Y) - (P2.Y - P1.Y) * (P.X - P1.X);
}

std::string Triangle::GetCrossPointLocation(Point P) const {
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

std::string Triangle::GetPointLocationHeron(Point P) const {
    double area1 = GetArea(P, A, B);
    double area2 = GetArea(P, A, C);
    double area3 = GetArea(P, B, C);

    double totalArea = GetArea(A, B, C);

    const double EPSILON = 1e-9;

    if (area1 < EPSILON || area2 < EPSILON || area3 < EPSILON) {
        if (std::abs((area1 + area2 + area3) - totalArea) < EPSILON) {
            return "На межі";
        }
    }


    if (std::abs((area1 + area2 + area3) - totalArea) < EPSILON) {
        return "Всередині";
    }

    return "Зовні";
}
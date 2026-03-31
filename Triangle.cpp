#include "Triangle.h"
#include <cmath>

double GetCrossProduct(Point P1, Point P2, Point P3) {
    return (P2.X - P1.X) * (P3.Y - P1.Y) - (P2.Y - P1.Y) * (P3.X - P1.X);
}

bool IsTriangleDegenerate(Triangle T) {
    // Якщо векторний добуток сторін дорівнює 0, точки лежать на одній лінії
    return std::abs(GetCrossProduct(T.A, T.B, T.C)) < 1e-9;
}

std::string GetPointLocation(Triangle T, Point P) {
    double CP1 = GetCrossProduct(T.A, T.B, P);
    double CP2 = GetCrossProduct(T.B, T.C, P);
    double CP3 = GetCrossProduct(T.C, T.A, P);

    bool HasNegative = (CP1 < -1e-9) || (CP2 < -1e-9) || (CP3 < -1e-9);
    bool HasPositive = (CP1 > 1e-9) || (CP2 > 1e-9) || (CP3 > 1e-9);

    // Якщо є вектори різних знаків - точка зовні
    if (HasNegative && HasPositive) {
        return "Зовні";
    }

    // Якщо хоча б один добуток нульовий - на межі
    if (std::abs(CP1) < 1e-9 || std::abs(CP2) < 1e-9 || std::abs(CP3) < 1e-9) {
        return "На межі";
    }

    return "Всередині";
}
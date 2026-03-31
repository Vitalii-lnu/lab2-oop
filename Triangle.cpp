#include "Triangle.h"
#include <cmath>

double CrossProduct(Point a, Point b, Point p) {
    
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

bool isDegenerate(Point a, Point b, Point c) {
    return std::abs(CrossProduct(a, b, c)) < 1e-9;
}

Location CheckPointInTriangle(Point a, Point b, Point c, Point p) {
    double cp1 = CrossProduct(a, b, p);
    double cp2 = CrossProduct(b, c, p);
    double cp3 = CrossProduct(c, a, p);

    bool has_neg = (cp1 < -1e-9) || (cp2 < -1e-9) || (cp3 < -1e-9);
    bool has_pos = (cp1 > 1e-9) || (cp2 > 1e-9) || (cp3 > 1e-9);

    // Якщо є і позитивні і негативні значення - точка зовні
    if (has_neg && has_pos) {
        return Location::Outside;
    }

    // Якщо хоча б один добуток нульовий
    if (std::abs(cp1) < 1e-9 || std::abs(cp2) < 1e-9 || std::abs(cp3) < 1e-9) {
        return Location::OnEdge;
    }

    return Location::Inside;
}

std::string LocationToString(Location loc) {
    switch (loc) {
        case Location::Inside: return "Всередині";
        case Location::OnEdge: return "На межі";
        case Location::Outside: return "Зовні";
        default: return "Undefined";
    }
}
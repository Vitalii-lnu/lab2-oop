#include "Triangle.h"


double Point::DistanceTo(Point Other) const {
    return std::sqrt(std::pow(Other.X - X, 2) + std::pow(Other.Y - Y, 2));
}


double Triangle::GetArea(Point A, Point B, Point C) const {
    double a = A.DistanceTo(B);
    double b = B.DistanceTo(C);
    double c = C.DistanceTo(A);

    double s = (a + b + c) / 2.0;

    double areaSq = s * (s - a) * (s - b) * (s - c);
    return std::sqrt(std::max(0.0, areaSq));
}

double Triangle::GetArea() const {
    return GetArea(A, B, C);
}

bool Triangle::IsDegenerate() const {
    return GetArea() < 1e-9;
}

double Triangle::GetCrossProduct(Point P1, Point P2, Point P) const {
    return (P2.X - P1.X) * (P.Y - P1.Y) -
           (P2.Y - P1.Y) * (P.X - P1.X);
}


bool IsPointOnSegment(Point A, Point B, Point P) {
    const double EPS = 1e-9;

    if (std::abs(A.X - B.X) < EPS && std::abs(A.Y - B.Y) < EPS) {
        return (std::abs(P.X - A.X) < EPS && std::abs(P.Y - A.Y) < EPS);
    }

    // Перевірка колінеарність
    double cross = (B.X - A.X) * (P.Y - A.Y) -
                   (B.Y - A.Y) * (P.X - A.X);
    if (std::abs(cross) > EPS) return false;

    // Перевірка проєкції
    double dot = (P.X - A.X) * (B.X - A.X) +
                 (P.Y - A.Y) * (B.Y - A.Y);
    if (dot < 0) return false;

    double lenSq = (B.X - A.X) * (B.X - A.X) +
                   (B.Y - A.Y) * (B.Y - A.Y);
    if (dot > lenSq) return false;

    return true;
}


std::string Triangle::GetCrossPointLocation(Point P) const {
    const double EPS = 1e-9;

    if (IsDegenerate()) {
        if (IsPointOnSegment(A, B, P) ||
            IsPointOnSegment(B, C, P) ||
            IsPointOnSegment(C, A, P)) {
            return "On line (degenerate)";
        }
        return "Outside";
    }

    double CP1 = GetCrossProduct(A, B, P);
    double CP2 = GetCrossProduct(B, C, P);
    double CP3 = GetCrossProduct(C, A, P);

    bool hasNeg = (CP1 < -EPS) || (CP2 < -EPS) || (CP3 < -EPS);
    bool hasPos = (CP1 > EPS) || (CP2 > EPS) || (CP3 > EPS);

    if (hasNeg && hasPos) return "Outside";

    if (std::abs(CP1) < EPS ||
        std::abs(CP2) < EPS ||
        std::abs(CP3) < EPS)
        return "On edge";

    return "Inside";
}

std::string Triangle::GetPointLocationHeron(Point P) const {
    const double EPS = 1e-10;

    if (IsDegenerate()) {
        if (IsPointOnSegment(A, B, P) ||
            IsPointOnSegment(B, C, P) ||
            IsPointOnSegment(C, A, P)) {
            return "On line (degenerate)";
        }
        return "Outside";
    }

    double area1 = GetArea(P, A, B);
    double area2 = GetArea(P, A, C);
    double area3 = GetArea(P, B, C);

    double totalArea = GetArea();

    if (std::abs((area1 + area2 + area3) - totalArea) < EPS) {
        if (area1 < EPS || area2 < EPS || area3 < EPS)
            return "On edge";
        return "Inside";
    }

    return "Outside";
}
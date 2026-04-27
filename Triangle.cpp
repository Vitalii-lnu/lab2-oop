#include "Triangle.h"

static const double BASE_EPS = 1e-9;

static double AdaptiveEPS(const Triangle& t) {
    auto maxCoord = [](double a, double b, double c) {
        return std::max({std::abs(a), std::abs(b), std::abs(c)});
    };

    double scale = maxCoord(t.A.X, t.B.X, t.C.X);
    scale = std::max(scale, maxCoord(t.A.Y, t.B.Y, t.C.Y));

    return BASE_EPS * std::max(1.0, scale);
}


double Point::DistanceTo(const Point& Other) const {
    double dx = Other.X - X;
    double dy = Other.Y - Y;
    return std::sqrt(dx * dx + dy * dy);
}


double Triangle::GetArea(const Point& A, const Point& B, const Point& C) const {
    double a = A.DistanceTo(B);
    double b = B.DistanceTo(C);
    double c = C.DistanceTo(A);

    double s = (a + b + c) * 0.5;

    double val = s * (s - a) * (s - b) * (s - c);

    if (val < 0 && val > -1e-12)
        val = 0;

    return std::sqrt(std::max(0.0, val));
}

double Triangle::GetArea() const {
    return GetArea(A, B, C);
}


bool Triangle::IsDegenerate() const {
    double area = GetArea();
    return area < 1e-12;
}


double Triangle::Cross(const Point& P1, const Point& P2, const Point& P) const {
    return (P2.X - P1.X) * (P.Y - P1.Y) -
           (P2.Y - P1.Y) * (P.X - P1.X);
}


bool IsPointOnSegment(const Point& A, const Point& B, const Point& P) {
    const double EPS = 1e-9;

    double cross = (B.X - A.X) * (P.Y - A.Y) -
                   (B.Y - A.Y) * (P.X - A.X);

    if (std::abs(cross) > EPS) return false;

    double dot = (P.X - A.X) * (B.X - A.X) +
                 (P.Y - A.Y) * (B.Y - A.Y);

    if (dot < 0) return false;

    double len = (B.X - A.X) * (B.X - A.X) +
                 (B.Y - A.Y) * (B.Y - A.Y);

    return dot <= len + EPS;
}


std::string Triangle::GetCrossPointLocation(const Point& P) const {
    double eps = AdaptiveEPS(*this);

    if (IsDegenerate()) {
        if (IsPointOnSegment(A, B, P) ||
            IsPointOnSegment(B, C, P) ||
            IsPointOnSegment(C, A, P))
            return "On line (degenerate)";
        return "Outside";
    }

    double c1 = Cross(A, B, P);
    double c2 = Cross(B, C, P);
    double c3 = Cross(C, A, P);

    bool hasNeg = (c1 < -eps) || (c2 < -eps) || (c3 < -eps);
    bool hasPos = (c1 > eps) || (c2 > eps) || (c3 > eps);

    if (hasNeg && hasPos)
        return "Outside";

    if (std::abs(c1) <= eps ||
        std::abs(c2) <= eps ||
        std::abs(c3) <= eps)
        return "On edge";

    return "Inside";
}


std::string Triangle::GetPointLocationHeron(const Point& P) const {
    double eps = AdaptiveEPS(*this);

    if (IsDegenerate()) {
        if (IsPointOnSegment(A, B, P) ||
            IsPointOnSegment(B, C, P) ||
            IsPointOnSegment(C, A, P))
            return "On line (degenerate)";
        return "Outside";
    }

    double a1 = GetArea(P, A, B);
    double a2 = GetArea(P, A, C);
    double a3 = GetArea(P, B, C);

    double total = GetArea();

    double sum = a1 + a2 + a3;

    if (std::abs(sum - total) <= eps * std::max(1.0, total)) {
        if (a1 <= eps || a2 <= eps || a3 <= eps)
            return "On edge";
        return "Inside";
    }

    return "Outside";
}
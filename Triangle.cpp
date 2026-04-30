#include "Triangle.h"
#include <cmath>
#include <algorithm>

using namespace std;


static const double EPS = 1e-9;



double Triangle::GetArea(Point A, Point B, Point C) const {
    return fabs(
        A.X * (B.Y - C.Y) +
        B.X * (C.Y - A.Y) +
        C.X * (A.Y - B.Y)
    ) / 2.0;
}

double Triangle::GetArea() const {
    return GetArea(A, B, C);
}

double Triangle::GetCrossProduct(Point P1, Point P2, Point P) const {
    return (P2.X - P1.X) * (P.Y - P1.Y) -
           (P2.Y - P1.Y) * (P.X - P1.X);
}




bool Triangle::IsDegenerate() const {

    double a = hypot(A.X - B.X, A.Y - B.Y);
    double b = hypot(B.X - C.X, B.Y - C.Y);
    double c = hypot(C.X - A.X, C.Y - A.Y);

    double maxSide = max({a, b, c});

    if (maxSide < EPS) return true;

    double height = (2.0 * GetArea()) / maxSide;

    
    return height < 1e-7;
}

bool Triangle::IsDegeneratePrint() const{
    return GetArea() < 1e-9;
}



bool IsPointOnSegment(Point A, Point B, Point P) {

    double cross = (B.X - A.X) * (P.Y - A.Y) -
                   (B.Y - A.Y) * (P.X - A.X);

    if (fabs(cross) > EPS) return false;

    if (P.X < min(A.X, B.X) - EPS || P.X > max(A.X, B.X) + EPS)
        return false;

    if (P.Y < min(A.Y, B.Y) - EPS || P.Y > max(A.Y, B.Y) + EPS)
        return false;

    return true;
}


bool OnDegenerateTriangle(const Triangle& T, Point P) {

    double dAB = hypot(T.A.X - T.B.X, T.A.Y - T.B.Y);
    double dBC = hypot(T.B.X - T.C.X, T.B.Y - T.C.Y);
    double dCA = hypot(T.C.X - T.A.X, T.C.Y - T.A.Y);

    Point S = T.A, E = T.B;
    double maxD = dAB;

    if (dBC > maxD) { S = T.B; E = T.C; maxD = dBC; }
    if (dCA > maxD) { S = T.C; E = T.A; }

    return IsPointOnSegment(S, E, P);
}



string Triangle::GetCrossPointLocation(Point P) const {

    if (IsDegenerate()) {
        if (OnDegenerateTriangle(*this, P))
            return "Inside";
        return "Outside";
    }

    double cp1 = GetCrossProduct(A, B, P);
    double cp2 = GetCrossProduct(B, C, P);
    double cp3 = GetCrossProduct(C, A, P);

    bool hasNeg = (cp1 < -EPS) || (cp2 < -EPS) || (cp3 < -EPS);
    bool hasPos = (cp1 > EPS) || (cp2 > EPS) || (cp3 > EPS);

    if (hasNeg && hasPos) return "Outside";

    if (fabs(cp1) < EPS || fabs(cp2) < EPS || fabs(cp3) < EPS)
        return "On edge";

    return "Inside";
}



string Triangle::GetPointLocationHeron(Point P) const {

    if (IsDegenerate()) {
        if (OnDegenerateTriangle(*this, P))
            return "Inside";
        return "Outside";
    }

    double a1 = GetArea(P, A, B);
    double a2 = GetArea(P, B, C);
    double a3 = GetArea(P, C, A);

    double total = GetArea();

    if (fabs((a1 + a2 + a3) - total) < EPS) {
        if (a1 < EPS || a2 < EPS || a3 < EPS)
            return "On edge";
        return "Inside";
    }

    return "Outside";
}
#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {
    Triangle T;

    cout << "--- Triangle coordinates input ---\n";
    cout << "A (x y): "; cin >> T.A.X >> T.A.Y;
    cout << "B (x y): "; cin >> T.B.X >> T.B.Y;
    cout << "C (x y): "; cin >> T.C.X >> T.C.Y;

    if (T.IsDegeneratePrint()) {
        cout << "Triangle is degenerate (Area = " << (double)T.GetArea() << ")\n";
    } else {
        cout << "Area: " << (double)T.GetArea() << "\n";
    }

    int n;
    cout << "\nNumber of points to check: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Point P;
        cout << "Point " << i + 1 << " (x y): ";
        cin >> P.X >> P.Y;

        string r1 = T.GetCrossPointLocation(P);
        string r2 = T.GetPointLocationHeron(P);

        cout << "Cross product: " << r1 << "\n";
        cout << "Heron method: " << r2 << "\n";
    }

    return 0;
}
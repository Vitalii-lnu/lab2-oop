#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {

    setlocale(0, ".1251");

    Triangle T;
    cout << "--- Triangle coordinates input ---" << endl;
    cout << "A (x y): "; cin >> T.A.X >> T.A.Y;
    cout << "B (x y): "; cin >> T.B.X >> T.B.Y;
    cout << "C (x y): "; cin >> T.C.X >> T.C.Y;

    bool isDegenerate = T.IsDegenerate();

    if (isDegenerate) {
        cout << "Triangle is degenerate (Area = " << T.GetArea() << ")" << endl;
    } else {
        cout << "Area: " << T.GetArea() << endl;
    }

    int n;
    cout << "\nNumber of points to check: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Point P;
        cout << "Point " << i + 1 << " (x y): ";
        cin >> P.X >> P.Y;

        string resultVector = T.GetCrossPointLocation(P);
        string resultHeron = T.GetPointLocationHeron(P);

        cout << "Cross product method (" << P.X << ", " << P.Y << "): " << resultVector << endl;
        cout << "Heron method (" << P.X << ", " << P.Y << "): " << resultHeron << endl;
    }

    return 0;
}
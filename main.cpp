#include <iostream>
#include "Triangle.h"

#include <string>
#include <sstream>

using namespace std;

bool ReadDouble(double& out) {
    std::string s;
    std::cin >> s;

    std::stringstream ss(s);
    double value;
    char extra;

    if (!(ss >> value) || (ss >> extra)) {
        return false;
    }

    out = value;
    return true;
}

bool ReadInt(int& out) {
    std::string s;
    std::cin >> s;

    std::stringstream ss(s);
    int value;
    char extra;

    if (!(ss >> value) || (ss >> extra)) {
        return false;
    }

    out = value;
    return true;
}


int main() {

    setlocale(0, ".1251");

    Triangle T;

    cout << "--- Triangle coordinates input ---" << endl;

    cout << "A (x y): ";
    while (!ReadDouble(T.A.X) || !ReadDouble(T.A.Y)) {
        cout << "Invalid input. Try again A (x y): ";
        cin.clear();
    }

    cout << "B (x y): ";
    while (!ReadDouble(T.B.X) || !ReadDouble(T.B.Y)) {
        cout << "Invalid input. Try again B (x y): ";
        cin.clear();
    }

    cout << "C (x y): ";
    while (!ReadDouble(T.C.X) || !ReadDouble(T.C.Y)) {
        cout << "Invalid input. Try again C (x y): ";
        cin.clear();
    }

    bool isDegenerate = T.IsDegenerate();

    if (isDegenerate) {
        cout << "Triangle is degenerate (Area = " << T.GetArea() << ")" << endl;
    } else {
        cout << "Area: " << T.GetArea() << endl;
    }

    int n;
    cout << "\nNumber of points to check: ";

    while (!ReadInt(n) || n < 0) {
        cout << "Invalid input. Enter positive integer: ";
        cin.clear();
    }

    for (int i = 0; i < n; ++i) {
        Point P;

        cout << "Point " << i + 1 << " (x y): ";

        while (!ReadDouble(P.X) || !ReadDouble(P.Y)) {
            cout << "Invalid input. Try again (x y): ";
            cin.clear();
        }

        string resultVector = T.GetCrossPointLocation(P);
        string resultHeron = T.GetPointLocationHeron(P);

        cout << "Cross product method (" << P.X << ", " << P.Y << "): " << resultVector << endl;
        cout << "Heron method (" << P.X << ", " << P.Y << "): " << resultHeron << endl;
    }

    return 0;
}
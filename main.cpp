#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {
    setlocale(0, ".1251");

    Triangle T;
    cout << "--- Введення координат трикутника ---" << endl;
    cout << "A (x y): "; cin >> T.A.X >> T.A.Y;
    cout << "B (x y): "; cin >> T.B.X >> T.B.Y;
    cout << "C (x y): "; cin >> T.C.X >> T.C.Y;

    if (T.IsDegenerate()) {
        cout << "Трикутник вироджений (Площа за Героном = " << T.GetArea() << ")" << endl;
        return 1;
    }

    cout << "Площа: " << T.GetArea() << endl;

    int n;
    cout << "\nКількість точок для перевірки: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Point P;
        cout << "Точка " << i + 1 << " (x y): ";
        cin >> P.X >> P.Y;

        // Виклик методу через об'єкт трикутника
        string ResultVector = T.GetCrossPointLocation(P);
        string ResultHeron = T.GetPointLocationHeron(P); 
        cout << "Результат для точки методом векторного добутку(" << P.X << ", " << P.Y << "): " << ResultVector << endl;

        cout << "Результат для точки методом Герона добутку(" << P.X << ", " << P.Y << "): " << ResultHeron << endl;
    }

    return 0;
}
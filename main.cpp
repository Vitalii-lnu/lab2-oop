#include <iostream>
#include <clocale> // Необхідно для setlocale
#include "Triangle.h"

using namespace std;

int main() {
    setlocale(0, ".1251");

    Triangle CurrentTriangle;

    cout << "--- Введення координат трикутника ---" << endl;
    cout << "Вершина A (x y): "; 
    if (!(cin >> CurrentTriangle.A.X >> CurrentTriangle.A.Y)) return 1;
    
    cout << "Вершина B (x y): "; 
    if (!(cin >> CurrentTriangle.B.X >> CurrentTriangle.B.Y)) return 1;
    
    cout << "Вершина C (x y): "; 
    if (!(cin >> CurrentTriangle.C.X >> CurrentTriangle.C.Y)) return 1;

    // Перевірка на виродженість
    if (IsTriangleDegenerate(CurrentTriangle)) {
        cout << "Помилка: Трикутник вироджений (точки лежать на одній прямій)" << endl;
        return 1;
    }

    int PointsCount;
    cout << "\nСкільки точок ви хочете перевірити? ";
    cin >> PointsCount;

    for (int i = 0; i < PointsCount; ++i) {
        Point TargetPoint;
        cout << "Точка " << i + 1 << " (x y): ";
        cin >> TargetPoint.X >> TargetPoint.Y;

        string Result = GetPointLocation(CurrentTriangle, TargetPoint);
        cout << "Результат: " << Result << endl;
    }

    cout << "\nПрограму завершено." << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include "Triangle.h"

int main() {
    setlocale(0, ".1251");

    Point a, b, c;
    
    std::cout << "--- Введення координат трикутника ---\n";
    std::cout << "Вершина A (x y): "; std::cin >> a.x >> a.y;
    std::cout << "Вершина B (x y): "; std::cin >> b.x >> b.y;
    std::cout << "Вершина C (x y): "; std::cin >> c.x >> c.y;

    if (isDegenerate(a, b, c)) {
        std::cerr << "Помилка: Трикутник вироджений (площа = 0). Перевірка неможлива.\n";
        return 1;
    }

    int n;
    std::cout << "\nСкільки точок ви хочете перевірити? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Point p;
        std::cout << "Точка " << i + 1 << " (x y): ";
        std::cin >> p.x >> p.y;

        Location result = CheckPointInTriangle(a, b, c, p);
        std::cout << "Результат: " << LocationToString(result) << "\n";
    }

    std::cout << "\nРоботу завершено.\n";
    return 0;
}
// Колосов Егор
// Kolosov Egor
// M8o-212BV-24
// 10 10 2025
// LABA 3

#include <iostream>
#include <vector>
#include <cmath>

// Главный класс для всех фигур
class Figure {
public:
    // Виртуальный деструктор чтобы все работало
    virtual ~Figure() = default;

    // Чисто виртуальные функции которые должны быть в дочерних классах
    virtual std::pair<double, double> center() const = 0; // Центр фигуры
    virtual operator double() const = 0; // Площадь фигуры
    virtual bool operator==(const Figure& other) const = 0; // Сравнение фигур
    virtual Figure* clone() const = 0; // Копирование фигуры
};

// Просто пустой оператор вывода для фигуры
std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    return os;
}

// Класс для пятиугольника
class Pentagon : public Figure {
private:
    double x[5], y[5]; // Массивы для координат 5 вершин
public:
    // Конструктор по умолчанию - все вершины в нуле
    Pentagon() {
        for (int i = 0; i < 5; ++i) {
            x[i] = 0.0;
            y[i] = 0.0;
        }
    }

    // Находим центр пятиугольника
    std::pair<double, double> center() const override {
        double cx = 0, cy = 0; // Суммы координат
        for (int i = 0; i < 5; ++i) {
            cx += x[i];
            cy += y[i];
        }
        return {cx / 5.0, cy / 5.0}; // Среднее арифметическое
    }

    // Вычисляем площадь пятиугольника
    operator double() const override {
        double r = sqrt(x[0]*x[0] + y[0]*y[0]); // Радиус описанной окружности
        return 5.0 / 4.0 * r * r * tan(M_PI / 5.0); // Формула площади
    }

    // Сравниваем два пятиугольника
    bool operator==(const Figure& other) const override {
        auto* o = dynamic_cast<const Pentagon*>(&other); // Проверяем тип
        if (!o) return false; // Если не пятиугольник - не равны
        // Сравниваем все вершины
        for (int i = 0; i < 5; ++i) {
            if (x[i] != o->x[i] || y[i] != o->y[i]) return false;
        }
        return true;
    }

    // Создаем копию пятиугольника
    Figure* clone() const override {
        return new Pentagon(*this); // Просто копируем
    }

    // Выводим координаты вершин
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& p) {
        for (int i = 0; i < 5; ++i) {
            os << "(" << p.x[i] << ", " << p.y[i] << ") ";
        }
        return os;
    }

    // Вводим координаты вершин
    friend std::istream& operator>>(std::istream& is, Pentagon& p) {
        for (int i = 0; i < 5; ++i) {
            is >> p.x[i] >> p.y[i]; // Читаем x и y для каждой вершины
        }
        return is;
    }
};

// Класс для шестиугольника
class Hexagon : public Figure {
private:
    double x[6], y[6]; // Массивы для координат 6 вершин
public:
    // Конструктор по умолчанию
    Hexagon() {
        for (int i = 0; i < 6; ++i) {
            x[i] = 0.0;
            y[i] = 0.0;
        }
    }

    // Находим центр шестиугольника
    std::pair<double, double> center() const override {
        double cx = 0, cy = 0;
        for (int i = 0; i < 6; ++i) {
            cx += x[i];
            cy += y[i];
        }
        return {cx / 6.0, cy / 6.0}; // Среднее арифметическое
    }

    // Вычисляем площадь шестиугольника
    operator double() const override {
        double r = sqrt(x[0]*x[0] + y[0]*y[0]); // Радиус
        return 3.0 * sqrt(3.0) / 2.0 * r * r; // Формула площади
    }

    // Сравниваем два шестиугольника
    bool operator==(const Figure& other) const override {
        auto* o = dynamic_cast<const Hexagon*>(&other);
        if (!o) return false;
        for (int i = 0; i < 6; ++i) {
            if (x[i] != o->x[i] || y[i] != o->y[i]) return false;
        }
        return true;
    }

    // Создаем копию шестиугольника
    Figure* clone() const override {
        return new Hexagon(*this);
    }

    // Выводим координаты вершин
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& h) {
        for (int i = 0; i < 6; ++i) {
            os << "(" << h.x[i] << ", " << h.y[i] << ") ";
        }
        return os;
    }

    // Вводим координаты вершин
    friend std::istream& operator>>(std::istream& is, Hexagon& h) {
        for (int i = 0; i < 6; ++i) {
            is >> h.x[i] >> h.y[i];
        }
        return is;
    }
};

// Класс для восьмиугольника
class Octagon : public Figure {
private:
    double x[8], y[8]; // Массивы для координат 8 вершин
public:
    // Конструктор по умолчанию
    Octagon() {
        for (int i = 0; i < 8; ++i) {
            x[i] = 0.0;
            y[i] = 0.0;
        }
    }

    // Находим центр восьмиугольника
    std::pair<double, double> center() const override {
        double cx = 0, cy = 0;
        for (int i = 0; i < 8; ++i) {
            cx += x[i];
            cy += y[i];
        }
        return {cx / 8.0, cy / 8.0}; // Среднее арифметическое
    }

    // Вычисляем площадь восьмиугольника
    operator double() const override {
        double r = sqrt(x[0]*x[0] + y[0]*y[0]); // Радиус
        return 2.0 * (1 + sqrt(2.0)) * r * r; // Формула площади
    }

    // Сравниваем два восьмиугольника
    bool operator==(const Figure& other) const override {
        auto* o = dynamic_cast<const Octagon*>(&other);
        if (!o) return false;
        for (int i = 0; i < 8; ++i) {
            if (x[i] != o->x[i] || y[i] != o->y[i]) return false;
        }
        return true;
    }

    // Создаем копию восьмиугольника
    Figure* clone() const override {
        return new Octagon(*this);
    }

    // Выводим координаты вершин
    friend std::ostream& operator<<(std::ostream& os, const Octagon& o) {
        for (int i = 0; i < 8; ++i) {
            os << "(" << o.x[i] << ", " << o.y[i] << ") ";
        }
        return os;
    }

    // Вводим координаты вершин
    friend std::istream& operator>>(std::istream& is, Octagon& o) {
        for (int i = 0; i < 8; ++i) {
            is >> o.x[i] >> o.y[i];
        }
        return is;
    }
};

// Оператор ввода для указателя на фигуру
std::istream& operator>>(std::istream& is, Figure*& fig) {
    int type;
    is >> type; // Читаем тип фигуры

    // Создаем фигуру в зависимости от типа
    if (type == 5) {
        auto* pentagon = new Pentagon(); // Создаем пятиугольник
        is >> *pentagon; // Читаем его данные
        fig = pentagon; // Записываем в указатель
    } else if (type == 6) {
        auto* hexagon = new Hexagon(); // Создаем шестиугольник
        is >> *hexagon; // Читаем его данные
        fig = hexagon; // Записываем в указатель
    } else if (type == 8) {
        auto* octagon = new Octagon(); // Создаем восьмиугольник
        is >> *octagon; // Читаем его данные
        fig = octagon; // Записываем в указатель
    } else {
        fig = nullptr; // Неизвестный тип - nullptr
    }

    return is;
}

int main() {
    std::vector<Figure*> figures; // Вектор для хранения фигур
    int n;
    std::cout << "введите количество фигур: ";
    std::cin >> n;

    // Читаем все фигуры
    for (int i = 0; i < n; ++i) {
        Figure* fig = nullptr;
        std::cin >> fig; // Читаем фигуру
        if (fig) {
            figures.push_back(fig); // Добавляем в вектор если не nullptr
        }
    }

    // Выводим центр и площадь для каждой фигуры
    for (auto* f : figures) {
        std::cout << "центр: " << f->center().first << ", " << f->center().second << std::endl;
        std::cout << "площадь: " << static_cast<double>(*f) << std::endl;
    }

    // Считаем общую площадь всех фигур
    double total_area = 0;
    for (auto* f : figures) {
        total_area += static_cast<double>(*f); // Суммируем площади
    }
    std::cout << "итоговая площадь: " << total_area << std::endl;

    // Удаляем фигуру по индексу
    int idx;
    std::cout << "введите индекс для удаления: ";
    std::cin >> idx;
    if (idx >= 0 && idx < figures.size()) {
        delete figures[idx]; // Освобождаем память
        figures.erase(figures.begin() + idx); // Удаляем из вектора
    }

    // Очищаем всю оставшуюся память
    for (auto* f : figures) {
        delete f; // Удаляем каждую фигуру
    }

    return 0; // Конец программы
}
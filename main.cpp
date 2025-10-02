// Колосов Егор
// Kolosov Egor
// M8o-212BV-24
// 10 10 2025
// LABA 3

#include <iostream>
#include <vector>
#include <cmath>

class Figure { // создаем класс
public:
    virtual ~Figure() = default;
    virtual std::pair<double, double> center() const = 0;
    virtual operator double() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure* clone() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    return os;
}

// пятиугольник класс
class Pentagon : public Figure {
private:
    double x[5], y[5];
public:
    Pentagon() {
        for (int i = 0; i < 5; ++i) {
            x[i] = 0.0;
            y[i] = 0.0;
        }
    }

    std::pair<double, double> center() const override {
        double cx = 0, cy = 0;
        for (int i = 0; i < 5; ++i) {
            cx += x[i];
            cy += y[i];
        }
        return {cx / 5.0, cy / 5.0};
    }

    operator double() const override {
        double r = sqrt(x[0]*x[0] + y[0]*y[0]);
        return 5.0 / 4.0 * r * r * tan(M_PI / 5.0);
    }

    bool operator==(const Figure& other) const override {
        auto* o = dynamic_cast<const Pentagon*>(&other);
        if (!o) return false;
        for (int i = 0; i < 5; ++i) {
            if (x[i] != o->x[i] || y[i] != o->y[i]) return false;
        }
        return true;
    }

    Figure* clone() const override {
        return new Pentagon(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Pentagon& p) {
        for (int i = 0; i < 5; ++i) {
            os << "(" << p.x[i] << ", " << p.y[i] << ") ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Pentagon& p) {
        for (int i = 0; i < 5; ++i) {
            is >> p.x[i] >> p.y[i];
        }
        return is;
    }
};

// шестиугольник класс
class Hexagon : public Figure {
private:
    double x[6], y[6];
public:
    Hexagon() {
        for (int i = 0; i < 6; ++i) {
            x[i] = 0.0;
            y[i] = 0.0;
        }
    }

    std::pair<double, double> center() const override {
        double cx = 0, cy = 0;
        for (int i = 0; i < 6; ++i) {
            cx += x[i];
            cy += y[i];
        }
        return {cx / 6.0, cy / 6.0};
    }

    operator double() const override {
        double r = sqrt(x[0]*x[0] + y[0]*y[0]);
        return 3.0 * sqrt(3.0) / 2.0 * r * r;
    }

    bool operator==(const Figure& other) const override {
        auto* o = dynamic_cast<const Hexagon*>(&other);
        if (!o) return false;
        for (int i = 0; i < 6; ++i) {
            if (x[i] != o->x[i] || y[i] != o->y[i]) return false;
        }
        return true;
    }

    Figure* clone() const override {
        return new Hexagon(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Hexagon& h) {
        for (int i = 0; i < 6; ++i) {
            os << "(" << h.x[i] << ", " << h.y[i] << ") ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Hexagon& h) {
        for (int i = 0; i < 6; ++i) {
            is >> h.x[i] >> h.y[i];
        }
        return is;
    }
};

// восьмиугольник класс
class Octagon : public Figure {
private:
    double x[8], y[8];
public:
    Octagon() {
        for (int i = 0; i < 8; ++i) {
            x[i] = 0.0;
            y[i] = 0.0;
        }
    }

    std::pair<double, double> center() const override {
        double cx = 0, cy = 0;
        for (int i = 0; i < 8; ++i) {
            cx += x[i];
            cy += y[i];
        }
        return {cx / 8.0, cy / 8.0};
    }

    operator double() const override {
        double r = sqrt(x[0]*x[0] + y[0]*y[0]);
        return 2.0 * (1 + sqrt(2.0)) * r * r;
    }

    bool operator==(const Figure& other) const override {
        auto* o = dynamic_cast<const Octagon*>(&other);
        if (!o) return false;
        for (int i = 0; i < 8; ++i) {
            if (x[i] != o->x[i] || y[i] != o->y[i]) return false;
        }
        return true;
    }

    Figure* clone() const override {
        return new Octagon(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Octagon& o) {
        for (int i = 0; i < 8; ++i) {
            os << "(" << o.x[i] << ", " << o.y[i] << ") ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Octagon& o) {
        for (int i = 0; i < 8; ++i) {
            is >> o.x[i] >> o.y[i];
        }
        return is;
    }
};

// оператор будет здесь
std::istream& operator>>(std::istream& is, Figure*& fig) {
    int type;
    is >> type;

    if (type == 5) {
        auto* pentagon = new Pentagon();
        is >> *pentagon;
        fig = pentagon;
    } else if (type == 6) {
        auto* hexagon = new Hexagon();
        is >> *hexagon;
        fig = hexagon;
    } else if (type == 8) {
        auto* octagon = new Octagon();
        is >> *octagon;
        fig = octagon;
    } else {
        fig = nullptr;
    }

    return is;
}

int main() {
    std::vector<Figure*> figures;
    int n;
    std::cout << "Enter number of figures: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Figure* fig = nullptr;
        std::cin >> fig;
        if (fig) {
            figures.push_back(fig);
        }
    }
// 2132314
    // мы выведем центр и площади ниже
    for (auto* f : figures) {
        std::cout << "Center: " << f->center().first << ", " << f->center().second << std::endl;
        std::cout << "Area: " << static_cast<double>(*f) << std::endl;
    }

    // алощадь
    double total_area = 0;
    for (auto* f : figures) {
        total_area += static_cast<double>(*f);
    }
    std::cout << "Total area: " << total_area << std::endl;

    // удалим
    int idx;
    std::cout << "Enter index to remove: ";
    std::cin >> idx;
    if (idx >= 0 && idx < figures.size()) {
        delete figures[idx];
        figures.erase(figures.begin() + idx);
    }

    // делитаем чтобы фришнуть память
    for (auto* f : figures) {
        delete f;
    }

    return 0;
}
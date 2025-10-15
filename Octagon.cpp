#include "Octagon.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>

// конструктор
Octagon::Octagon() {
    // инициализируем массив нулями
    for(int i = 0; i < 8; i++) {
        x[i] = 0;
        y[i] = 0;
    }
}

// деструктор
Octagon::~Octagon() {
    // ничего особенного не делаем
}

// получаем x координату центра
double Octagon::getCenterX() {
    double sum = 0;
    for(int i = 0; i < 8; i++) {
        sum += x[i];
    }
    return sum / 8.0;  // делим на количество вершин
}

// получаем y координату центра
double Octagon::getCenterY() {
    double sum = 0;
    for(int i = 0; i < 8; i++) {
        sum += y[i];
    }
    return sum / 8.0;
}

// вычисляем площадь по формуле
double Octagon::getArea() {
    double area = 0;
    // используем формулу площади многоугольника
    for(int i = 0; i < 8; i++) {
        int j = (i + 1) % 8;  // следующая вершина
        area += x[i] * y[j];
        area -= x[j] * y[i];
    }
    return abs(area) / 2.0;  // берем модуль и делим на 2
}

// выводим вершины
void Octagon::printVertices() {
    std::cout << "Octagon vertices:" << std::endl;
    for(int i = 0; i < 8; i++) {
        std::cout << "  Vertex " << (i+1) << ": (" 
                  << std::fixed << std::setprecision(2) 
                  << x[i] << ", " << y[i] << ")" << std::endl;
    }
}

// вводим вершины
void Octagon::inputVertices() {
    std::cout << "Enter 8 vertices for Octagon (x y format):" << std::endl;
    for(int i = 0; i < 8; i++) {
        std::cout << "Vertex " << (i+1) << ": ";
        std::cin >> x[i] >> y[i];
    }
}

// оператор присваивания
Octagon& Octagon::operator=(const Octagon& other) {
    if(this != &other) {
        for(int i = 0; i < 8; i++) {
            x[i] = other.x[i];
            y[i] = other.y[i];
        }
    }
    return *this;
}

// оператор перемещения
Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if(this != &other) {
        for(int i = 0; i < 8; i++) {
            x[i] = std::move(other.x[i]);
            y[i] = std::move(other.y[i]);
        }
    }
    return *this;
}

// оператор сравнения
bool Octagon::operator==(const Octagon& other) {
    for(int i = 0; i < 8; i++) {
        if(x[i] != other.x[i] || y[i] != other.y[i]) {
            return false;
        }
    }
    return true;
}

// оператор вывода
std::ostream& Octagon::operator<<(std::ostream& os) const {
    os << "Octagon vertices: ";
    for(int i = 0; i < 8; i++) {
        os << "(" << std::fixed << std::setprecision(2) 
           << x[i] << ", " << y[i] << ")";
        if(i < 7) os << " ";
    }
    return os;
}

// оператор ввода
std::istream& Octagon::operator>>(std::istream& is) {
    std::cout << "Enter 8 vertices for Octagon (x y format):" << std::endl;
    for(int i = 0; i < 8; i++) {
        std::cout << "Vertex " << (i+1) << ": ";
        is >> x[i] >> y[i];
    }
    return is;
}

// создаем правильный восьмиугольник
void Octagon::createRegularOctagon(double centerX, double centerY, double radius) {
    // угол между вершинами
    double angleStep = 2 * 3.14159 / 8;  // 2*pi/8
    
    for(int i = 0; i < 8; i++) {
        double angle = i * angleStep - 3.14159/2;  // начинаем сверху
        x[i] = centerX + radius * cos(angle);
        y[i] = centerY + radius * sin(angle);
    }
}
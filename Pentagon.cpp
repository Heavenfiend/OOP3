#include "Pentagon.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>

// конструктор
Pentagon::Pentagon() {
    // инициализируем массив нулями
    for(int i = 0; i < 5; i++) {
        x[i] = 0;
        y[i] = 0;
    }
}

// деструктор
Pentagon::~Pentagon() {
    // ничего особенного не делаем
}

// получаем x координату центра
double Pentagon::getCenterX() {
    double sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += x[i];
    }
    return sum / 5.0;  // делим на количество вершин
}

// получаем y координату центра
double Pentagon::getCenterY() {
    double sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += y[i];
    }
    return sum / 5.0;
}

// вычисляем площадь по формуле
double Pentagon::getArea() {
    double area = 0;
    // используем формулу площади многоугольника
    for(int i = 0; i < 5; i++) {
        int j = (i + 1) % 5;  // следующая вершина
        area += x[i] * y[j];
        area -= x[j] * y[i];
    }
    return abs(area) / 2.0;  // берем модуль и делим на 2
}

// выводим вершины
void Pentagon::printVertices() {
    std::cout << "Pentagon vertices:" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cout << "  Vertex " << (i+1) << ": (" 
                  << std::fixed << std::setprecision(2) 
                  << x[i] << ", " << y[i] << ")" << std::endl;
    }
}

// вводим вершины
void Pentagon::inputVertices() {
    std::cout << "Enter 5 vertices for Pentagon (x y format):" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cout << "Vertex " << (i+1) << ": ";
        std::cin >> x[i] >> y[i];
    }
}

// оператор присваивания
Pentagon& Pentagon::operator=(const Pentagon& other) {
    if(this != &other) {
        for(int i = 0; i < 5; i++) {
            x[i] = other.x[i];
            y[i] = other.y[i];
        }
    }
    return *this;
}

// оператор перемещения
Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if(this != &other) {
        for(int i = 0; i < 5; i++) {
            x[i] = std::move(other.x[i]);
            y[i] = std::move(other.y[i]);
        }
    }
    return *this;
}

// оператор сравнения
bool Pentagon::operator==(const Pentagon& other) {
    for(int i = 0; i < 5; i++) {
        if(x[i] != other.x[i] || y[i] != other.y[i]) {
            return false;
        }
    }
    return true;
}

// оператор вывода
std::ostream& Pentagon::operator<<(std::ostream& os) const {
    os << "Pentagon vertices: ";
    for(int i = 0; i < 5; i++) {
        os << "(" << std::fixed << std::setprecision(2) 
           << x[i] << ", " << y[i] << ")";
        if(i < 4) os << " ";
    }
    return os;
}

// оператор ввода
std::istream& Pentagon::operator>>(std::istream& is) {
    std::cout << "Enter 5 vertices for Pentagon (x y format):" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cout << "Vertex " << (i+1) << ": ";
        is >> x[i] >> y[i];
    }
    return is;
}

// создаем правильный пятиугольник
void Pentagon::createRegularPentagon(double centerX, double centerY, double radius) {
    // угол между вершинами
    double angleStep = 2 * 3.14159 / 5;  // 2*pi/5
    
    for(int i = 0; i < 5; i++) {
        double angle = i * angleStep - 3.14159/2;  // начинаем сверху
        x[i] = centerX + radius * cos(angle);
        y[i] = centerY + radius * sin(angle);
    }
}
#include "Hexagon.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// конструктор
Hexagon::Hexagon() {
    // инициализируем массив нулями
    for(int i = 0; i < 6; i++) {
        x[i] = 0;
        y[i] = 0;
    }
}

// деструктор
Hexagon::~Hexagon() {
    // ничего особенного не делаем
}

// получаем x координату центра
double Hexagon::getCenterX() {
    double sum = 0;
    for(int i = 0; i < 6; i++) {
        sum += x[i];
    }
    return sum / 6.0;  // делим на количество вершин
}

// получаем y координату центра
double Hexagon::getCenterY() {
    double sum = 0;
    for(int i = 0; i < 6; i++) {
        sum += y[i];
    }
    return sum / 6.0;
}

// вычисляем площадь по формуле
double Hexagon::getArea() {
    double area = 0;
    // используем формулу площади многоугольника
    for(int i = 0; i < 6; i++) {
        int j = (i + 1) % 6;  // следующая вершина
        area += x[i] * y[j];
        area -= x[j] * y[i];
    }
    return abs(area) / 2.0;  // берем модуль и делим на 2
}

// выводим вершины
void Hexagon::printVertices() {
    std::cout << "Hexagon vertices:" << std::endl;
    for(int i = 0; i < 6; i++) {
        std::cout << "  Vertex " << (i+1) << ": (" 
                  << std::fixed << std::setprecision(2) 
                  << x[i] << ", " << y[i] << ")" << std::endl;
    }
}

// вводим вершины
void Hexagon::inputVertices() {
    std::cout << "Enter 6 vertices for Hexagon (x y format):" << std::endl;
    for(int i = 0; i < 6; i++) {
        std::cout << "Vertex " << (i+1) << ": ";
        std::cin >> x[i] >> y[i];
    }
}

// оператор присваивания
Hexagon& Hexagon::operator=(const Hexagon& other) {
    if(this != &other) {
        for(int i = 0; i < 6; i++) {
            x[i] = other.x[i];
            y[i] = other.y[i];
        }
    }
    return *this;
}

// оператор сравнения
bool Hexagon::operator==(const Hexagon& other) {
    for(int i = 0; i < 6; i++) {
        if(x[i] != other.x[i] || y[i] != other.y[i]) {
            return false;
        }
    }
    return true;
}

// создаем правильный шестиугольник
void Hexagon::createRegularHexagon(double centerX, double centerY, double radius) {
    // угол между вершинами
    double angleStep = 2 * 3.14159 / 6;  // 2*pi/6
    
    for(int i = 0; i < 6; i++) {
        double angle = i * angleStep - 3.14159/2;  // начинаем сверху
        x[i] = centerX + radius * cos(angle);
        y[i] = centerY + radius * sin(angle);
    }
}
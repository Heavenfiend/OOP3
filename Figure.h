#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>

// класс для фигур
class Figure {
public:
    // конструктор и деструктор
    Figure() {}
    virtual ~Figure() {}
    
    // чисто виртуальные функции которые нужно переопределить
    virtual double getCenterX() = 0;
    virtual double getCenterY() = 0;
    virtual double getArea() = 0;
    
    // функция для вывода вершин
    virtual void printVertices() = 0;
    
    // функция для ввода вершин
    virtual void inputVertices() = 0;
    
    // операторы
    virtual Figure& operator=(const Figure& other) { return *this; }
    virtual bool operator==(const Figure& other) { return false; }
    
    // приведение к double
    virtual operator double() { return getArea(); }
};

#endif
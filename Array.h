#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"

// класс для хранения массива фигур
class Array {
private:
    Figure** figures;  // массив указателей на фигуры
    int size;          // текущий размер
    int capacity;      // максимальный размер
    
public:
    Array();
    ~Array();
    
    // основные функции
    void addFigure(Figure* figure);
    void removeFigure(int index);
    int getSize();
    Figure* getFigure(int index);
    
    // функции для работы с фигурами
    void printAllInfo();
    void printAllVertices();
    double calculateTotalArea();
    
    // оператор доступа
    Figure* operator[](int index);
};

#endif
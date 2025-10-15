#include "Array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <iostream>
#include <iomanip>

// конструктор
Array::Array() {
    capacity = 10;  // начальная вместимость
    size = 0;
    figures = new Figure*[capacity];  // выделяем память
}

// деструктор
Array::~Array() {
    // освобождаем память для каждой фигуры
    for(int i = 0; i < size; i++) {
        delete figures[i];
    }
    // освобождаем память для массива
    delete[] figures;
}

// добавляем фигуру
void Array::addFigure(Figure* figure) {
    if(size < capacity) {
        figures[size] = figure;
        size++;
    } else {
        // если места нет, увеличиваем массив
        capacity *= 2;
        Figure** newFigures = new Figure*[capacity];
        for(int i = 0; i < size; i++) {
            newFigures[i] = figures[i];
        }
        delete[] figures;
        figures = newFigures;
        figures[size] = figure;
        size++;
    }
}

// удаляем фигуру по индексу
void Array::removeFigure(int index) {
    if(index >= 0 && index < size) {
        delete figures[index];  // освобождаем память
        
        // сдвигаем элементы
        for(int i = index; i < size - 1; i++) {
            figures[i] = figures[i + 1];
        }
        size--;
    }
}

// получаем размер
int Array::getSize() {
    return size;
}

// получаем фигуру по индексу
Figure* Array::getFigure(int index) {
    if(index >= 0 && index < size) {
        return figures[index];
    }
    return nullptr;
}

// выводим информацию о всех фигурах
void Array::printAllInfo() {
    std::cout << "\n=== All Figures Information ===" << std::endl;
    
    for(int i = 0; i < size; i++) {
        std::cout << "\nFigure " << (i + 1) << ":" << std::endl;
        
        // определяем тип фигуры
        if(dynamic_cast<Pentagon*>(figures[i])) {
            std::cout << "  Type: Pentagon" << std::endl;
        } else if(dynamic_cast<Hexagon*>(figures[i])) {
            std::cout << "  Type: Hexagon" << std::endl;
        } else if(dynamic_cast<Octagon*>(figures[i])) {
            std::cout << "  Type: Octagon" << std::endl;
        }
        
        // выводим центр и площадь
        std::cout << "  Center: (" << std::fixed << std::setprecision(2) 
                  << figures[i]->getCenterX() << ", " 
                  << figures[i]->getCenterY() << ")" << std::endl;
        std::cout << "  Area: " << std::fixed << std::setprecision(2) 
                  << figures[i]->getArea() << std::endl;
    }
}

// выводим вершины всех фигур
void Array::printAllVertices() {
    std::cout << "\n=== All Figures Vertices ===" << std::endl;
    
    for(int i = 0; i < size; i++) {
        std::cout << "\nFigure " << (i + 1) << ":" << std::endl;
        figures[i]->printVertices();
    }
}

// вычисляем общую площадь
double Array::calculateTotalArea() {
    double total = 0;
    for(int i = 0; i < size; i++) {
        total += figures[i]->getArea();
    }
    return total;
}

// оператор доступа
Figure* Array::operator[](int index) {
    return getFigure(index);
}
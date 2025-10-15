#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"

class Hexagon : public Figure {
private:
    // массив для хранения координат вершин
    double x[6];  // x координаты
    double y[6];  // y координаты
    
public:
    Hexagon();
    ~Hexagon();
    
    // переопределяем функции из базового класса
    double getCenterX() override;
    double getCenterY() override;
    double getArea() override;
    
    void printVertices() override;
    void inputVertices() override;
    
    // операторы
    Hexagon& operator=(const Hexagon& other);
    bool operator==(const Hexagon& other);
    
    // дополнительная функция для создания правильного шестиугольника
    void createRegularHexagon(double centerX, double centerY, double radius);
};

#endif
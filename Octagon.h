#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"

class Octagon : public Figure {
private:
    // массив для хранения координат вершин
    double x[8];  // x координаты
    double y[8];  // y координаты
    
public:
    Octagon();
    ~Octagon();
    
    // переопределяем функции из базового класса
    double getCenterX() override;
    double getCenterY() override;
    double getArea() override;
    
    void printVertices() override;
    void inputVertices() override;
    
    // операторы
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    bool operator==(const Octagon& other);
    
    // операторы ввода/вывода
    std::ostream& operator<<(std::ostream& os) const;
    std::istream& operator>>(std::istream& is);
    
    // дополнительная функция для создания правильного восьмиугольника
    void createRegularOctagon(double centerX, double centerY, double radius);
};

#endif
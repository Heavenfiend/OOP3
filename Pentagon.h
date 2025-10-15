#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure {
private:
    // массив для хранения координат вершин
    double x[5];  // x координаты
    double y[5];  // y координаты
    
public:
    Pentagon();
    ~Pentagon();
    
    // переопределяем функции из базового класса
    double getCenterX() override;
    double getCenterY() override;
    double getArea() override;
    
    void printVertices() override;
    void inputVertices() override;
    
    // операторы
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    bool operator==(const Pentagon& other);
    
    // операторы ввода/вывода
    std::ostream& operator<<(std::ostream& os) const;
    std::istream& operator>>(std::istream& is);
    
    // дополнительная функция для создания правильного пятиугольника
    void createRegularPentagon(double centerX, double centerY, double radius);
};

#endif
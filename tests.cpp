#include <gtest/gtest.h>
#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Array.h"

// пентагон
class PentagonTest : public ::testing::Test {
protected:
    void SetUp() override {
        // создаем тестовый пятиугольник
        pentagon = new Pentagon();
        pentagon->createRegularPentagon(0, 0, 5);  // центр в (0,0), радиус 5
    }
    
    void TearDown() override {
        delete pentagon;
    }
    
    Pentagon* pentagon;
};

// центр треугольника
TEST_F(PentagonTest, TestCenter) {
    EXPECT_NEAR(pentagon->getCenterX(), 0.0, 0.01);
    EXPECT_NEAR(pentagon->getCenterY(), 0.0, 0.01);
}

// алощадь пятиугольника
TEST_F(PentagonTest, TestArea) {
    double area = pentagon->getArea();
    EXPECT_GT(area, 0);  // площадь должна быть больше 0
    EXPECT_NEAR(area, 59.44, 1.0);  // примерная площадь правильного 5-угольника
}

// оператор присваивания
TEST_F(PentagonTest, TestAssignment) {
    Pentagon pentagon2;
    pentagon2 = *pentagon;
    
    // проверяем что координаты совпадают
    EXPECT_NEAR(pentagon->getCenterX(), pentagon2.getCenterX(), 0.01);
    EXPECT_NEAR(pentagon->getCenterY(), pentagon2.getCenterY(), 0.01);
}

// оператор сравнения
TEST_F(PentagonTest, TestEquality) {
    Pentagon pentagon2;
    pentagon2.createRegularPentagon(0, 0, 5);
    
    EXPECT_TRUE(*pentagon == pentagon2);
}

// приведение к double
TEST_F(PentagonTest, TestDoubleConversion) {
    double area = (double)(*pentagon);
    EXPECT_GT(area, 0);
}

// Hexagon
class HexagonTest : public ::testing::Test {
protected:
    void SetUp() override {
        hexagon = new Hexagon();
        hexagon->createRegularHexagon(0, 0, 3);  // центр в (0,0), радиус 3
    }
    
    void TearDown() override {
        delete hexagon;
    }
    
    Hexagon* hexagon;
};

// центр шестиугольника
TEST_F(HexagonTest, TestCenter) {
    EXPECT_NEAR(hexagon->getCenterX(), 0.0, 0.01);
    EXPECT_NEAR(hexagon->getCenterY(), 0.0, 0.01);
}

// площадь шестиугольника
TEST_F(HexagonTest, TestArea) {
    double area = hexagon->getArea();
    EXPECT_GT(area, 0);
    EXPECT_NEAR(area, 23.38, 1.0);  // примерная площадь правильного 6-угольника
}

// Octagon
class OctagonTest : public ::testing::Test {
protected:
    void SetUp() override {
        octagon = new Octagon();
        octagon->createRegularOctagon(0, 0, 4);  // центр в (0,0), радиус 4
    }
    
    void TearDown() override {
        delete octagon;
    }
    
    Octagon* octagon;
};

// центр восьмиугольника
TEST_F(OctagonTest, TestCenter) {
    EXPECT_NEAR(octagon->getCenterX(), 0.0, 0.01);
    EXPECT_NEAR(octagon->getCenterY(), 0.0, 0.01);
}

// площадь восьмиугольника
TEST_F(OctagonTest, TestArea) {
    double area = octagon->getArea();
    EXPECT_GT(area, 0);
    EXPECT_NEAR(area, 45.25, 1.0);  // примерная площадь правильного 8-угольника
}

// класс Array
class ArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        array = new Array();
    }
    
    void TearDown() override {
        delete array;
    }
    
    Array* array;
};

// добавление фигур
TEST_F(ArrayTest, TestAddFigures) {
    Pentagon* pentagon = new Pentagon();
    pentagon->createRegularPentagon(0, 0, 5);
    
    Hexagon* hexagon = new Hexagon();
    hexagon->createRegularHexagon(2, 2, 3);
    
    array->addFigure(pentagon);
    array->addFigure(hexagon);
    
    EXPECT_EQ(array->getSize(), 2);
}

// удаление фигур
TEST_F(ArrayTest, TestRemoveFigure) {
    Pentagon* pentagon = new Pentagon();
    pentagon->createRegularPentagon(0, 0, 5);
    
    array->addFigure(pentagon);
    EXPECT_EQ(array->getSize(), 1);
    
    array->removeFigure(0);
    EXPECT_EQ(array->getSize(), 0);
}

// вся площадь
TEST_F(ArrayTest, TestTotalArea) {
    Pentagon* pentagon = new Pentagon();
    pentagon->createRegularPentagon(0, 0, 5);
    
    Hexagon* hexagon = new Hexagon();
    hexagon->createRegularHexagon(0, 0, 3);
    
    array->addFigure(pentagon);
    array->addFigure(hexagon);
    
    double totalArea = array->calculateTotalArea();
    EXPECT_GT(totalArea, 0);
}

// оператор доступа
TEST_F(ArrayTest, TestOperatorAccess) {
    Pentagon* pentagon = new Pentagon();
    pentagon->createRegularPentagon(0, 0, 5);
    
    array->addFigure(pentagon);
    
    Figure* figure = (*array)[0];
    EXPECT_NE(figure, nullptr);
    EXPECT_GT(figure->getArea(), 0);
}

// пустой массив
TEST_F(ArrayTest, TestEmptyArray) {
    EXPECT_EQ(array->getSize(), 0);
    
    double totalArea = array->calculateTotalArea();
    EXPECT_EQ(totalArea, 0);
}

// создание фигур
TEST(PolygonCreationTest, TestDifferentPositions) {
    Pentagon pentagon1, pentagon2;
    
    // создаем два пятиугольника в разных местах
    pentagon1.createRegularPentagon(0, 0, 5);
    pentagon2.createRegularPentagon(10, 10, 3);
    
    // центры должны быть разными
    EXPECT_NE(pentagon1.getCenterX(), pentagon2.getCenterX());
    EXPECT_NE(pentagon1.getCenterY(), pentagon2.getCenterY());
    
    // площади должны быть разными
    EXPECT_NE(pentagon1.getArea(), pentagon2.getArea());
}

// разные типы фигур
TEST(PolygonComparisonTest, TestDifferentTypes) {
    Pentagon pentagon;
    Hexagon hexagon;
    
    pentagon.createRegularPentagon(0, 0, 5);
    hexagon.createRegularHexagon(0, 0, 5);
    
    // разные типы фигур не должны быть равны
    EXPECT_FALSE(pentagon == hexagon);
}

// ну и главная функция
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

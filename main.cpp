#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

// функция для вывода меню
void showMenu() {
    std::cout << "\n=== Figure Management System ===" << std::endl;
    std::cout << "1. Add Pentagon" << std::endl;
    std::cout << "2. Add Hexagon" << std::endl;
    std::cout << "3. Add Octagon" << std::endl;
    std::cout << "4. Remove figure by index" << std::endl;
    std::cout << "5. Print all centers and areas" << std::endl;
    std::cout << "6. Print all vertices" << std::endl;
    std::cout << "7. Calculate total area" << std::endl;
    std::cout << "8. Show menu" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

// функция для добавления пятиугольника
void addPentagon(Array& arr) {
    std::cout << "\nAdding Pentagon:" << std::endl;
    Pentagon* pentagon = new Pentagon();  // создаем новый пятиугольник
    
    int choice;
    std::cout << "1. Enter vertices manually" << std::endl;
    std::cout << "2. Generate regular pentagon" << std::endl;
    std::cout << "Choose option: ";
    std::cin >> choice;
    
    if(choice == 1) {
        pentagon->inputVertices();  // вводим вершины вручную
    } else if(choice == 2) {
        double centerX, centerY, radius;
        std::cout << "Enter center coordinates (x y): ";
        std::cin >> centerX >> centerY;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        
        pentagon->createRegularPentagon(centerX, centerY, radius);
    }
    
    arr.addFigure(pentagon);
    std::cout << "Pentagon added successfully!" << std::endl;
}

// функция для добавления шестиугольника
void addHexagon(Array& arr) {
    std::cout << "\nAdding Hexagon:" << std::endl;
    Hexagon* hexagon = new Hexagon();  // создаем новый шестиугольник
    
    int choice;
    std::cout << "1. Enter vertices manually" << std::endl;
    std::cout << "2. Generate regular hexagon" << std::endl;
    std::cout << "Choose option: ";
    std::cin >> choice;
    
    if(choice == 1) {
        hexagon->inputVertices();  // вводим вершины вручную
    } else if(choice == 2) {
        double centerX, centerY, radius;
        std::cout << "Enter center coordinates (x y): ";
        std::cin >> centerX >> centerY;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        
        hexagon->createRegularHexagon(centerX, centerY, radius);
    }
    
    arr.addFigure(hexagon);
    std::cout << "Hexagon added successfully!" << std::endl;
}

// функция для добавления восьмиугольника
void addOctagon(Array& arr) {
    std::cout << "\nAdding Octagon:" << std::endl;
    Octagon* octagon = new Octagon();  // создаем новый восьмиугольник
    
    int choice;
    std::cout << "1. Enter vertices manually" << std::endl;
    std::cout << "2. Generate regular octagon" << std::endl;
    std::cout << "Choose option: ";
    std::cin >> choice;
    
    if(choice == 1) {
        octagon->inputVertices();  // вводим вершины вручную
    } else if(choice == 2) {
        double centerX, centerY, radius;
        std::cout << "Enter center coordinates (x y): ";
        std::cin >> centerX >> centerY;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        
        octagon->createRegularOctagon(centerX, centerY, radius);
    }
    
    arr.addFigure(octagon);
    std::cout << "Octagon added successfully!" << std::endl;
}

// функция для удаления фигуры
void removeFigure(Array& arr) {
    if(arr.getSize() == 0) {
        std::cout << "No figures to remove!" << std::endl;
        return;
    }
    
    std::cout << "\nCurrent figures count: " << arr.getSize() << std::endl;
    std::cout << "Enter index to remove (0-based): ";
    
    int index;
    std::cin >> index;
    
    if(index >= 0 && index < arr.getSize()) {
        arr.removeFigure(index);
        std::cout << "Figure removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}

int main() {
    system("chcp 65001");  // для корректного отображения русских символов
    
    Array figuresArray;  // создаем массив фигур
    int choice;
    
    std::cout << "Welcome to Figure Management System!" << std::endl;
    showMenu();
    
    // основной цикл программы
    while(true) {
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                addPentagon(figuresArray);
                break;
                
            case 2:
                addHexagon(figuresArray);
                break;
                
            case 3:
                addOctagon(figuresArray);
                break;
                
            case 4:
                removeFigure(figuresArray);
                break;
                
            case 5:
                if(figuresArray.getSize() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    figuresArray.printAllInfo();
                }
                break;
                
            case 6:
                if(figuresArray.getSize() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    figuresArray.printAllVertices();
                }
                break;
                
            case 7:
                if(figuresArray.getSize() == 0) {
                    std::cout << "No figures to calculate area for!" << std::endl;
                } else {
                    double totalArea = figuresArray.calculateTotalArea();
                    std::cout << "\nTotal area of all figures: " 
                              << std::fixed << std::setprecision(2) 
                              << totalArea << std::endl;
                }
                break;
                
            case 8:
                showMenu();
                break;
                
            case 0:
                std::cout << "Goodbye!" << std::endl;
                return 0;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
        
        // пауза перед следующим шагом
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
        showMenu();
    }
    
    return 0;
}
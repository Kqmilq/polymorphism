#include <iostream>
#include <cmath> // Dla stałej M_PI
#include "math.h"
// Abstrakcyjna klasa Figure
class Figure {
public:
    // Czysta wirtualna metoda area()
    virtual double area() const = 0;

    virtual double permiter() const = 0;

    // Czysta wirtualna metoda show()
    virtual void show() const = 0;

    // Wirtualny destruktor
    virtual ~Figure() = default;
};

// Klasa Circle dziedzicząca po Figure
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementacja metody area()
    double area() const override {
        return M_PI * radius * radius;
    }
    double permiter() const override{
        return radius * M_PI * 2;
    }

    // Implementacja metody show()
    void show() const override {
        std::cout << "Circle with radius: " << radius << " and area: " << area() << " and permiter: " << permiter()
        <<std::endl;
    }
};
class Triangle : public Figure {
private:
    double boka, bokb;

public:
    Triangle(double a, double b) : boka(a), bokb(b) {}
    double area() const override {
        return boka * bokb /2;
    }
    double permiter() const override{
        return boka + bokb + sqrt((boka*boka)+(bokb*bokb));
    }

    void show() const override {
        std::cout << "Triangle with first side: " << boka << ", second side: " << bokb << " and area: " << area() << " and permiter: " << permiter()
                  << std::endl;
    }

};

// Klasa Rectangle dziedzicząca po Figure
class Rectangle : public Figure {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementacja metody area()
    double area() const override {
        return width * height;
    }
    double permiter() const override{
        return (width + height) * 2;
    }

    // Implementacja metody show()
    void show() const override {
        std::cout << "Rectangle with width: " << width << ", height: " << height << " and area: " << area() << " and permiter: " << permiter()
                  << std::endl;
    }
};

int main() {
    // Tablica wskaźników na obiekty klasy Figure
    Figure *figures[4];

    // Tworzenie obiektów i przypisywanie wskaźników do tablicy
    figures[0] = new Circle(5.0);
    figures[1] = new Rectangle(4.0, 6.0);
    figures[2] = new Triangle(2.5, 5.5);

    // Iteracja przez tablicę i wyświetlanie informacji o obiektach
    for (int i = 0; i < 3; ++i) {
        figures[i]->show();
    }

    // Zwolnienie pamięci
    for (int i = 0; i < 3; ++i) {
        delete figures[i];
    }

    return 0;
}
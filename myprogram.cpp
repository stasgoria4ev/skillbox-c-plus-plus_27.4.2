#include <iostream>
#include <cmath>
#include <string>

class Figure {                          //общая родительская фигура
public:
    enum Color { None, Red, Green, Blue };
    float x = 0;
    float y = 0;

    std::string getColor(int color) {
        std::string temp;
        if (color == None) temp = "None";
        else if (color == Red) temp = "Red";
        else if (color == Green) temp = "Green";
        else if (color == Blue) temp = "Blue";
        return temp;
    }
};

class Circle:public Figure {            //круг
public:
    std::string color () {
        return getColor(Red);
    }
    float radius = 0;

    float area() {
        return atan(1) * 4 * radius;
    }

    void rectangleOutline() {
        radius += 0.5;
        std::cout << '(' << x - radius << ',' << y + radius<< ")(" << x + radius << ',' << y - radius << ")\n";
    }
};

class Square:public Figure {            //квадрат
public:
    std::string color () {
        return getColor(Green);
    }
    float lengthEdge = 0;

    float area() {
        return lengthEdge * lengthEdge;
    }

    void rectangleOutline() {
        lengthEdge = (lengthEdge / 2) + 0.5;
        std::cout << '(' << x - lengthEdge << ',' << y + lengthEdge<< ")(" << x + lengthEdge << ',' << y - lengthEdge << ")\n";
    }
};

class Triangle:public Figure {         //равносторонний!!! треугольник
public:
    std::string color () {
        return getColor(Blue);
    }
    float lengthEdge = 0;

    float area() {
        return lengthEdge * lengthEdge * std::sqrt(3);
    }

    void rectangleOutline() {
        float a = lengthEdge / 2;
        float h = std::sqrt((lengthEdge * lengthEdge) - (a * a)); //высота треугольника
        h = (h / 2) + 0.5;
        a += 0.5;
        std::cout << '(' << x - a << ',' << y + h << ")(" << x + a << ',' << y - h << ")\n";
    }
};

class Rectangle:public Figure {         //прямоугольник
public:
    std::string color () {
        return getColor(None);
    }
    float width = 0;
    float height = 0;

    float area() {
        return  width * height;
    }

    void rectangleOutline() {
        width = (width / 2) + 0.5;
        height = (height / 2) + 0.5;
        std::cout << '(' << x - width << ',' << y + height << ")(" << x + width << ',' << y - height << ")\n";
    }
};

int main() { 
    std::string command;
    do {
        std::cout << "Enter one of the commands:\n";
        std::cout << "1 = circle\n";
        std::cout << "2 = square\n";
        std::cout << "3 = triangle\n";
        std::cout << "4 = rectangle\n";
        std::cout << ": ";
        std::cin >> command;
        if (command == "1") {
            Circle* circle = new Circle;
            std::cout << "Enter the coordinates of the center of the circle separated by a space(x y): ";
            std::cin >> circle->x >> circle->y;
            std::cout << "Enter the radius of the circle: ";
            std::cin >> circle->radius;
            std::cout << "Circle color = " << circle->color() << '\n';
            std::cout << "Area of ​​a circle = " << circle->area() << '\n';
            std::cout << "Enclosing rectangle coordinates = "; circle->rectangleOutline();
            delete circle; circle = nullptr;
        }
        else if (command == "2") {
            Square* square = new Square;
            std::cout << "Enter the coordinates of the center of the square separated by a space(x y): ";
            std::cin >> square->x >> square->y;
            std::cout << "Enter the length of the edge of the square: ";
            std::cin >> square->lengthEdge;
            std::cout << "Square color = " << square->color() << '\n';
            std::cout << "square area = " << square->area() << '\n';
            std::cout << "Enclosing rectangle coordinates = "; square->rectangleOutline();
            delete square; square = nullptr;
        }
        else if (command == "3") {
            Triangle* triangle = new Triangle;
            std::cout << "Enter the coordinates of the center of the triangle separated by a space(x y): ";
            std::cin >> triangle->x >> triangle->y;
            std::cout << "Enter the length of the edge of an equilateral triangle: ";
            std::cin >> triangle->lengthEdge ;
            std::cout << "Triangle Color = " << triangle->color() << '\n';
            std::cout << "Area of ​​a triangle = " << triangle->area() << '\n';
            std::cout << "Enclosing rectangle coordinates = "; triangle->rectangleOutline();
            delete triangle; triangle = nullptr;
        }
        else if (command == "4") {
            Rectangle* rectangle = new Rectangle;
            std::cout << "Enter the coordinates of the center of the rectangle separated by a space(x y): ";
            std::cin >> rectangle->x >> rectangle->y;
            std::cout << "Enter the length and width of the rectangle: ";
            std::cout << "Width: ";
            std::cin >> rectangle->width;
            std::cout << "Height: ";
            std::cin >> rectangle->height;
            std::cout << "Rectangle color = " << rectangle->color() << '\n';
            std::cout << "Rectangle area = " << rectangle->area() << '\n';
            std::cout << "Enclosing rectangle coordinates = "; rectangle->rectangleOutline();
            delete rectangle; rectangle = nullptr;
        }
        if (command != "1" && command != "2" && command != "3" && command != "4")
            std::cout << "Invalid command, please try again.\n";
    } while (command != "1" && command != "2" && command != "3" && command != "4");
} 
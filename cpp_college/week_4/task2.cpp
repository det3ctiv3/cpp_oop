#include <iostream>
#include <string>

class Shape {

    protected:
    std::string color;
    public:
    Shape(std::string c) : color(c) {}
    void display(){
        std::cout << "A: " << color << std::endl;
    }

    virtual double area(){
        return 0.0;
    }
};


class Rectangle : public Shape {
    private:
    double width;
    double height;

    public:
    Rectangle(std::string c, double w, double h) : Shape(c), width(w), height(h) {}

    double area() {
        return width * height;
    }
    void display() {
        Shape::display(); // Call base class display to show color
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};


int main(){
    Rectangle rect("Red", 5.0, 3.0);
    rect.display();
    return 0;
}

/*
 * OOP Midterm Practice Problems
 * Topics: Constructors, Destructors, Copy Constructor, Assignment Operator,
 *         Inheritance, Polymorphism, Virtual Functions
 */

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================================
// PROBLEM 1: String Class with Dynamic Memory
// Practice: Rule of Three, Deep Copy, Dynamic Memory Management
// ============================================================================

class MyString {
private:
    char* data;
    int length;

public:
    // Default Constructor
    MyString() : data(nullptr), length(0) {
        cout << "Default constructor called" << endl;
    }

    // Parameterized Constructor
    MyString(const char* str) {
        cout << "Parameterized constructor called" << endl;
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Copy Constructor (Deep Copy)
    MyString(const MyString& other) {
        cout << "Copy constructor called" << endl;
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    // Assignment Operator (Deep Copy)
    MyString& operator=(const MyString& other) {
        cout << "Assignment operator called" << endl;
        
        // Check for self-assignment
        if (this == &other) {
            return *this;
        }

        // Delete old data
        delete[] data;

        // Copy new data
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }

        return *this;
    }

    // Destructor
    ~MyString() {
        cout << "Destructor called for: " << (data ? data : "empty") << endl;
        delete[] data;
    }

    // Display
    void display() const {
        if (data) {
            cout << "String: " << data << " (length: " << length << ")" << endl;
        } else {
            cout << "String: empty" << endl;
        }
    }
};

// ============================================================================
// PROBLEM 2: Inheritance and Constructor Chaining
// Practice: Base/Derived class constructors, Inheritance
// ============================================================================

class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle() : brand("Unknown"), year(0) {
        cout << "Vehicle default constructor" << endl;
    }

    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle parameterized constructor: " << brand << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor: " << brand << endl;
    }

    virtual void displayInfo() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car() : Vehicle(), doors(4) {
        cout << "Car default constructor" << endl;
    }

    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {
        cout << "Car parameterized constructor" << endl;
    }

    ~Car() {
        cout << "Car destructor" << endl;
    }

    void displayInfo() const override {
        cout << "Car - ";
        Vehicle::displayInfo();
        cout << "Doors: " << doors << endl;
    }
};

// ============================================================================
// PROBLEM 3: Polymorphism with Virtual Functions
// Practice: Virtual functions, Runtime polymorphism
// ============================================================================

class Shape {
protected:
    string color;

public:
    Shape(string c = "White") : color(c) {
        cout << "Shape constructor: " << color << endl;
    }

    virtual ~Shape() {
        cout << "Shape destructor" << endl;
    }

    // Pure virtual function - makes Shape abstract
    virtual double area() const = 0;
    
    // Virtual function with implementation
    virtual void display() const {
        cout << "Shape color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, string c = "Red") : Shape(c), radius(r) {
        cout << "Circle constructor" << endl;
    }

    ~Circle() {
        cout << "Circle destructor" << endl;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        Shape::display();
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h, string c = "Blue") 
        : Shape(c), width(w), height(h) {
        cout << "Rectangle constructor" << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
    }

    double area() const override {
        return width * height;
    }

    void display() const override {
        Shape::display();
        cout << "Rectangle " << width << "x" << height << endl;
        cout << "Area: " << area() << endl;
    }
};

// ============================================================================
// PROBLEM 4: Array Class with Dynamic Memory
// Practice: Operator overloading, Dynamic arrays, Rule of Three
// ============================================================================

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray(int s = 10) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        cout << "DynamicArray constructor: size " << size << endl;
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        cout << "DynamicArray copy constructor" << endl;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;

        delete[] arr;
        
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        
        cout << "DynamicArray assignment operator" << endl;
        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
        cout << "DynamicArray destructor" << endl;
    }

    // Overload [] operator
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            exit(1);
        }
        return arr[index];
    }

    void display() const {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize() const { return size; }
};

// ============================================================================
// MAIN FUNCTION - Test Cases
// ============================================================================

void testMyString() {
    cout << "\n========== TEST 1: MyString Class ==========" << endl;
    
    MyString s1("Hello");
    s1.display();
    
    MyString s2 = s1;  // Copy constructor
    s2.display();
    
    MyString s3;
    s3 = s1;  // Assignment operator
    s3.display();
}

void testInheritance() {
    cout << "\n========== TEST 2: Inheritance ==========" << endl;
    
    Car car1("Toyota", 2020, 4);
    car1.displayInfo();
    
    cout << "\n--- Testing polymorphism with pointers ---" << endl;
    Vehicle* vPtr = new Car("Honda", 2022, 2);
    vPtr->displayInfo();
    delete vPtr;  // Calls Car destructor then Vehicle destructor
}

void testPolymorphism() {
    cout << "\n========== TEST 3: Polymorphism ==========" << endl;
    
    // Cannot instantiate Shape (abstract class)
    // Shape s;  // ERROR!
    
    Circle c(5.0);
    c.display();
    
    cout << endl;
    Rectangle r(4.0, 6.0);
    r.display();
    
    cout << "\n--- Array of Shape pointers ---" << endl;
    Shape* shapes[3];
    shapes[0] = new Circle(3.0, "Yellow");
    shapes[1] = new Rectangle(5.0, 7.0, "Green");
    shapes[2] = new Circle(2.5, "Purple");
    
    cout << "\nDisplaying all shapes:" << endl;
    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << endl;
    }
    
    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
}

void testDynamicArray() {
    cout << "\n========== TEST 4: DynamicArray ==========" << endl;
    
    DynamicArray arr1(5);
    for (int i = 0; i < arr1.getSize(); i++) {
        arr1[i] = i * 10;
    }
    arr1.display();
    
    DynamicArray arr2 = arr1;  // Copy constructor
    arr2.display();
    
    DynamicArray arr3(3);
    arr3 = arr1;  // Assignment operator
    arr3.display();
}

int main() {
    cout << "OOP Practice Problems - Test Suite\n";
    cout << "====================================\n";
    
    testMyString();
    testInheritance();
    testPolymorphism();
    testDynamicArray();
    
    cout << "\n========== All tests completed ==========" << endl;
    
    return 0;
}

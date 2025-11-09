/*
 * OOP Midterm Practice Problems
 * Based on Dr. Sejuti Rahman's Lectures 1-5
 * 
 * Topics Covered:
 * 1. Classes, Constructors, Copy Constructors
 * 2. Access Modifiers
 * 3. Inheritance (public, protected, private)
 * 4. Constructor Chaining
 * 5. Function Overriding
 * 6. Multiple Inheritance and Diamond Problem
 * 7. Aggregation vs Composition
 */

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================================
// PROBLEM 1: Counter Class with Constructors
// Practice: Default constructor, constructor initialization
// ============================================================================

class Counter {
private:
    unsigned int count;
    
public:
    // Default constructor with initialization list
    Counter() : count(0) {
        cout << "Counter created with count = 0" << endl;
    }
    
    // Parameterized constructor
    Counter(unsigned int initial) : count(initial) {
        cout << "Counter created with count = " << initial << endl;
    }
    
    void inc_count() {
        count++;
    }
    
    unsigned int get_count() {
        return count;
    }
};

void test_counter() {
    cout << "\n========== TEST 1: Counter Class ==========" << endl;
    
    Counter c1;  // Uses default constructor
    Counter c2;
    
    cout << "c1 = " << c1.get_count() << endl;  // 0
    cout << "c2 = " << c2.get_count() << endl;  // 0
    
    c1.inc_count();
    c2.inc_count();
    c2.inc_count();
    
    cout << "After incrementing:" << endl;
    cout << "c1 = " << c1.get_count() << endl;  // 1
    cout << "c2 = " << c2.get_count() << endl;  // 2
}

// ============================================================================
// PROBLEM 2: Point and Vector Classes
// Practice: Nested classes, methods
// ============================================================================

class Point {
public:
    double x, y;
    
    Point() : x(0.0), y(0.0) {}
    
    Point(double nx, double ny) : x(nx), y(ny) {}
    
    void offset(double offsetX, double offsetY) {
        x += offsetX;
        y += offsetY;
    }
    
    void print() const {
        cout << "(" << x << "," << y << ")";
    }
};

class Vector {
public:
    Point start, end;
    
    Vector() {}
    
    Vector(double x1, double y1, double x2, double y2) 
        : start(x1, y1), end(x2, y2) {}
    
    void offset(double offsetX, double offsetY) {
        start.offset(offsetX, offsetY);
        end.offset(offsetX, offsetY);
    }
    
    void print() const {
        start.print();
        cout << " -> ";
        end.print();
        cout << endl;
    }
};

void test_point_vector() {
    cout << "\n========== TEST 2: Point and Vector ==========" << endl;
    
    Vector vec(1.2, 0.4, 2.0, 1.6);
    cout << "Original vector: ";
    vec.print();
    
    vec.offset(1.0, 1.5);
    cout << "After offset: ";
    vec.print();
}

// ============================================================================
// PROBLEM 3: Copy Constructor (Deep Copy Example)
// Practice: Custom copy constructor
// ============================================================================

class Student {
private:
    int studentID;
    char* name;
    
public:
    Student() : studentID(0) {
        name = new char[1];
        name[0] = '\0';
    }
    
    Student(int id, const char* n) : studentID(id) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    
    // Copy constructor (deep copy)
    Student(const Student& other) {
        cout << "Copy constructor called" << endl;
        studentID = other.studentID;
        name = new char[strlen(other.name) + 1];  // Allocate new memory
        strcpy(name, other.name);
    }
    
    ~Student() {
        delete[] name;
    }
    
    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    
    void display() const {
        cout << "Student ID: " << studentID << ", Name: " << name << endl;
    }
};

void test_copy_constructor() {
    cout << "\n========== TEST 3: Copy Constructor ==========" << endl;
    
    Student s1(123, "Alice");
    cout << "s1: ";
    s1.display();
    
    Student s2 = s1;  // Copy constructor
    cout << "s2 (copy of s1): ";
    s2.display();
    
    s2.setName("Bob");
    cout << "\nAfter changing s2's name:" << endl;
    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();
    
    cout << "Note: s1's name unchanged (deep copy worked!)" << endl;
}

// ============================================================================
// PROBLEM 4: Basic Inheritance
// Practice: Public inheritance, protected members
// ============================================================================

class Employee {
protected:
    string name;
    int number;
    
public:
    Employee() : name(""), number(0) {
        cout << "Employee default constructor" << endl;
    }
    
    Employee(string n, int num) : name(n), number(num) {
        cout << "Employee constructor: " << name << endl;
    }
    
    ~Employee() {
        cout << "Employee destructor: " << name << endl;
    }
    
    void display() {
        cout << "Name: " << name << ", Number: " << number << endl;
    }
};

class Manager : public Employee {
private:
    string title;
    double dues;
    
public:
    Manager() : Employee(), title(""), dues(0.0) {
        cout << "Manager default constructor" << endl;
    }
    
    Manager(string n, int num, string t, double d) 
        : Employee(n, num), title(t), dues(d) {
        cout << "Manager constructor" << endl;
    }
    
    ~Manager() {
        cout << "Manager destructor" << endl;
    }
    
    void display() {
        Employee::display();  // Call base class method
        cout << "Title: " << title << ", Dues: " << dues << endl;
    }
};

void test_inheritance() {
    cout << "\n========== TEST 4: Basic Inheritance ==========" << endl;
    
    cout << "Creating Manager object:" << endl;
    Manager mgr("John Doe", 12345, "Senior Manager", 5000.0);
    
    cout << "\nDisplaying Manager:" << endl;
    mgr.display();
    
    cout << "\nDestructing Manager:" << endl;
}

// ============================================================================
// PROBLEM 5: Function Overriding
// Practice: Overriding base class methods
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
    
    virtual void display() {
        cout << "Shape with color: " << color << endl;
    }
    
    virtual double area() {
        return 0.0;
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
    
    void display() override {
        Shape::display();  // Call base class version
        cout << "Circle with radius: " << radius << endl;
    }
    
    double area() override {
        return 3.14159 * radius * radius;
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
    
    void display() override {
        Shape::display();
        cout << "Rectangle: " << width << " x " << height << endl;
    }
    
    double area() override {
        return width * height;
    }
};

void test_overriding() {
    cout << "\n========== TEST 5: Function Overriding ==========" << endl;
    
    Circle c(5.0);
    c.display();
    cout << "Area: " << c.area() << endl;
    
    cout << endl;
    
    Rectangle r(4.0, 6.0);
    r.display();
    cout << "Area: " << r.area() << endl;
}

// ============================================================================
// PROBLEM 6: Multiple Inheritance
// Practice: Multiple inheritance, ambiguity
// ============================================================================

class StudentClass {
protected:
    string school;
    string degree;
    
public:
    StudentClass(string s, string d) : school(s), degree(d) {
        cout << "Student constructor" << endl;
    }
    
    void display() {
        cout << "School: " << school << ", Degree: " << degree << endl;
    }
};

class EmployeeClass {
protected:
    string company;
    double salary;
    
public:
    EmployeeClass(string c, double s) : company(c), salary(s) {
        cout << "Employee constructor" << endl;
    }
    
    void display() {
        cout << "Company: " << company << ", Salary: " << salary << endl;
    }
};

class WorkingStudent : public StudentClass, public EmployeeClass {
private:
    int hoursPerWeek;
    
public:
    WorkingStudent(string school, string degree, string company, 
                   double salary, int hours)
        : StudentClass(school, degree), EmployeeClass(company, salary),
          hoursPerWeek(hours) {
        cout << "WorkingStudent constructor" << endl;
    }
    
    void displayAll() {
        cout << "Working Student Information:" << endl;
        StudentClass::display();     // Specify which display
        EmployeeClass::display();    // Specify which display
        cout << "Hours per week: " << hoursPerWeek << endl;
    }
};

void test_multiple_inheritance() {
    cout << "\n========== TEST 6: Multiple Inheritance ==========" << endl;
    
    WorkingStudent ws("MIT", "Computer Science", "Google", 50000, 20);
    cout << endl;
    ws.displayAll();
    
    // This would be ambiguous without specifying:
    // ws.display();  // ERROR: Which display()?
}

// ============================================================================
// PROBLEM 7: Composition Example
// Practice: Has-a relationship, composition
// ============================================================================

class Engine {
private:
    int horsepower;
    
public:
    Engine(int hp) : horsepower(hp) {
        cout << "Engine created with " << hp << " HP" << endl;
    }
    
    ~Engine() {
        cout << "Engine destroyed" << endl;
    }
    
    void start() {
        cout << "Engine with " << horsepower << " HP started" << endl;
    }
};

class Car {
private:
    string model;
    Engine engine;  // Composition: Car HAS-A Engine
    
public:
    Car(string m, int hp) : model(m), engine(hp) {
        cout << "Car created: " << model << endl;
    }
    
    ~Car() {
        cout << "Car destroyed: " << model << endl;
    }
    
    void start() {
        cout << "Starting " << model << "..." << endl;
        engine.start();
    }
};

void test_composition() {
    cout << "\n========== TEST 7: Composition ==========" << endl;
    
    cout << "Creating car:" << endl;
    Car myCar("Toyota Camry", 200);
    
    cout << "\nStarting car:" << endl;
    myCar.start();
    
    cout << "\nDestroying car (Engine destroyed too):" << endl;
}

// ============================================================================
// PROBLEM 8: Access Specifiers
// Practice: public, protected, private members
// ============================================================================

class Base {
private:
    int privateVar;
    
protected:
    int protectedVar;
    
public:
    int publicVar;
    
    Base() : privateVar(1), protectedVar(2), publicVar(3) {}
    
    void showBase() {
        cout << "Private: " << privateVar << endl;      // OK
        cout << "Protected: " << protectedVar << endl;  // OK
        cout << "Public: " << publicVar << endl;        // OK
    }
};

class Derived : public Base {
public:
    void showDerived() {
        // cout << privateVar << endl;     // ERROR: Cannot access
        cout << "Protected: " << protectedVar << endl;  // OK
        cout << "Public: " << publicVar << endl;        // OK
    }
};

void test_access_specifiers() {
    cout << "\n========== TEST 8: Access Specifiers ==========" << endl;
    
    Base b;
    cout << "From Base class:" << endl;
    b.showBase();
    
    cout << "\nFrom Derived class:" << endl;
    Derived d;
    d.showDerived();
    
    // d.privateVar = 10;    // ERROR: Cannot access
    // d.protectedVar = 20;  // ERROR: Cannot access
    d.publicVar = 30;        // OK
    cout << "Modified public var: " << d.publicVar << endl;
}

// ============================================================================
// MAIN FUNCTION - Run All Tests
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║  OOP C++ MIDTERM PRACTICE PROBLEMS        ║" << endl;
    cout << "║  Based on Dr. Sejuti Rahman's Lectures    ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    test_counter();
    test_point_vector();
    test_copy_constructor();
    test_inheritance();
    test_overriding();
    test_multiple_inheritance();
    test_composition();
    test_access_specifiers();
    
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║  ALL TESTS COMPLETED SUCCESSFULLY!        ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    return 0;
}

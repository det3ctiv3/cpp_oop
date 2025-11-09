# OOP in C++ - Midterm Study Guide
## Based on Lectures 1-5 from Dr. Sejuti Rahman

## 📚 LECTURE BREAKDOWN:

### Lecture 1: Classes, Methods, and Constructors
- Classes and objects
- Fields and methods
- Constructors (default, parameterized, copy)
- Access modifiers (public, private, protected)
- Structs vs Classes

### Lecture 2: Objects, Static Data, and Function Interactions
- Objects as function arguments
- Returning objects from functions
- Static class data

### Lecture 3: Basic Inheritance
- "is a" relationship
- Base and derived classes
- Protected members
- Class access specifiers (public, protected, private)
- Constructors and destructors in inheritance
- Function overriding

### Lecture 4: Advanced Inheritance
- Multilevel inheritance
- Multiple inheritance
- Diamond problem and ambiguity
- Aggregation vs Composition

### Lecture 5: Revision
- Review of all concepts

---

## 1. CLASSES AND OBJECTS (Lecture 1)

### Basic Class Structure:
```cpp
class Point {
private:
    double x, y;
public:
    Point(double nx, double ny) {
        x = nx; y = ny;
    }
    void print() {
        cout << "(" << x << "," << y << ")";
    }
};
```

### Key Concepts:
- **Class**: Blueprint for objects
- **Object/Instance**: Specific realization of a class
- **Fields**: Data members of a class
- **Methods**: Functions that belong to a class

### Fields Can Be Classes:
```cpp
class Vector {
public:
    Point start, end;  // Fields can be classes
};
```

### Accessing Nested Fields:
```cpp
Vector vec;
vec.start.x = 1.2;  // Access nested fields with dot operator
vec.end.y = 2.0;
```

---

## 2. PASSING CLASSES (Lecture 1)

### Pass by Value (Makes a Copy):
```cpp
void printVector(Vector v) {  // Pass by value
    // Changes to v don't affect original
}
```

### Pass by Reference (Modifies Original):
```cpp
void offsetVector(Vector &v, double offsetX, double offsetY) {
    v.start.x += offsetX;  // Modifies original
    v.end.x += offsetX;
}
```

**Rule**: Use pass-by-reference when you need to modify the object

---

## 3. METHODS (Lecture 1)

### Methods are Functions Inside Classes:
```cpp
class Vector {
public:
    Point start, end;
    
    void print() {  // Method
        cout << "(" << start.x << "," << start.y << ") -> ";
        cout << "(" << end.x << "," << end.y << ")" << endl;
    }
    
    void offset(double offsetX, double offsetY) {
        start.x += offsetX;  // Can access fields directly
        end.x += offsetX;
        start.y += offsetY;
        end.y += offsetY;
    }
};
```

### Calling Methods:
```cpp
Vector vec;
vec.print();           // Call method on object
vec.offset(1.0, 2.0);  // Pass arguments to method
```

### Methods Can Call Other Methods:
```cpp
void Vector::offset(double offsetX, double offsetY) {
    start.offset(offsetX, offsetY);  // Call method on field
    end.offset(offsetX, offsetY);
}
```

---

## 4. IMPLEMENTING METHODS SEPARATELY (Lecture 1)

### Header File (vector.h):
```cpp
class Point {
public:
    double x, y;
    void offset(double offsetX, double offsetY);
    void print();
};
```

### Implementation File (vector.cpp):
```cpp
#include "vector.h"

void Point::offset(double offsetX, double offsetY) {
    x += offsetX; 
    y += offsetY;
}

void Point::print() {
    cout << "(" << x << "," << y << ")";
}
```

**Note**: `::` indicates which class's method is being implemented

---

## 5. CONSTRUCTORS (Lecture 1 & 2)

### Why Constructors?
Without constructors, fields have garbage values:
```cpp
Counter c1;  // count has garbage value! ❌
```

### Constructor Syntax:
- Same name as class
- No return type
- Called automatically when object is created

### Default Constructor:
```cpp
class Counter {
private:
    unsigned int count;
public:
    Counter() : count(0) {  // Initialization list
        // Empty body
    }
};
```

### Parameterized Constructor:
```cpp
class Point {
public:
    double x, y;
    Point(double nx, double ny) {
        x = nx; 
        y = ny;
    }
};

int main() {
    Point p(2.0, 3.0);  // Create with parameters
}
```

### Multiple Constructors (Overloading):
```cpp
class Point {
public:
    double x, y;
    
    Point() {  // Default constructor
        x = 0.0; y = 0.0;
    }
    
    Point(double nx, double ny) {  // Parameterized
        x = nx; y = ny;
    }
};
```

---

## 6. COPY CONSTRUCTOR (Lecture 1)

### Default Copy Constructor:
```cpp
Point q(1.0, 2.0);
Point r = q;  // Copies all fields automatically
// r.x is 1.0, r.y is 2.0
```

### Custom Copy Constructor:
```cpp
class Point {
public:
    double x, y;
    
    Point(Point &o) {  // Copy constructor
        x = o.x; 
        y = o.y;
        cout << "custom copy constructor" << endl;
    }
};
```

### Why Custom Copy Constructor?
**Problem with default copy (shallow copy)**:
```cpp
class MITStudent {
public:
    int studentID;
    char *name;  // Pointer!
};

int main() {
    MITStudent student1;
    student1.name = "foo";
    MITStudent student2 = student1;  // Copies pointer address
    student2.name[0] = 'b';
    cout << student1.name;  // "boo" - CHANGED! ❌
}
```

**Solution with custom copy (deep copy)**:
```cpp
class MITStudent {
public:
    MITStudent(MITStudent &o) {
        studentID = o.studentID;
        name = strdup(o.name);  // Allocate new memory!
    }
};
```

**Key Point**: Use custom copy constructor when class has pointers/dynamic memory

---

## 7. ACCESS MODIFIERS (Lecture 1)

### Three Types:
1. **public**: Can be accessed from anywhere
2. **private**: Only accessible within the class
3. **protected**: Accessible in class and derived classes

### Example:
```cpp
class Point {
private:
    double x, y;  // Cannot access from outside
    
public:
    Point(double nx, double ny) {
        x = nx; y = ny;  // Can access inside class
    }
    
    double getX() { return x; }  // Getter for read access
    double getY() { return y; }
};

int main() {
    Point p(2.0, 3.0);
    // p.x = 5.0;  // ERROR! x is private ❌
    cout << p.getX();  // OK! Use getter ✓
}
```

### Default Access Modifiers:
- **class**: private by default
- **struct**: public by default

```cpp
class Point {
    double x;  // private by default
};

struct Point {
    double x;  // public by default
};
```

---

## 8. STRUCTS VS CLASSES (Lecture 1)

### In C++, structs and classes are almost identical!
The ONLY difference is default access:

```cpp
struct Point {
    double x, y;  // public by default
};

class Point {
    double x, y;  // private by default
};
```

**Convention**: Use `struct` for simple data containers, `class` for objects with behavior

---

## 9. OBJECTS AS FUNCTION ARGUMENTS (Lecture 2)

### Passing Objects by Value:
```cpp
void func(Counter c) {  // Receives copy
    // Changes don't affect original
}
```

### Passing Objects by Reference:
```cpp
void func(Counter &c) {  // Receives reference
    // Changes affect original
}
```

---

## 10. RETURNING OBJECTS FROM FUNCTIONS (Lecture 2)

### Example:
```cpp
Counter getCounter() {
    Counter c;
    c.inc_count();
    return c;  // Returns copy of c
}

int main() {
    Counter c1 = getCounter();
}
```

---

## 11. STATIC CLASS DATA (Lecture 2)

### Static Members:
- Shared by all instances of the class
- Only one copy exists for the entire class
- Accessed using class name or object

### Example:
```cpp
class Counter {
private:
    int count;
    static int totalCount;  // Shared by all objects
    
public:
    Counter() {
        count = 0;
        totalCount++;  // Increment for all objects
    }
    
    static int getTotalCount() {
        return totalCount;
    }
};

// Initialize static member outside class
int Counter::totalCount = 0;

int main() {
    Counter c1, c2, c3;
    cout << Counter::getTotalCount();  // 3
}
```

---

## 12. INHERITANCE - BASICS (Lecture 3)

### The "is a" Relationship:
- A poodle **is a** dog
- A car **is a** vehicle
- A flower **is a** plant

### Terminology:
- **Base Class** (Parent/Superclass): The class being inherited from
- **Derived Class** (Child/Subclass): The class that inherits

### Basic Syntax:
```cpp
class Vehicle {  // Base class
protected:
    string brand;
    int year;
    
public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    
    void displayInfo() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {  // Derived class
private:
    int doors;
    
public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}
    
    void displayInfo() {
        cout << "Car - ";
        Vehicle::displayInfo();
        cout << "Doors: " << doors << endl;
    }
};
```

### What Does a Child Have?
An object of derived class has:
- All members defined in child class ✓
- All members declared in parent class ✓

An object of derived class can access:
- All public and protected members of child class ✓
- All public and protected members of parent class ✓
- **Cannot** access private members of parent class ❌

---

## 13. PROTECTED MEMBERS (Lecture 3)

### Access Level Comparison:
| Access Modifier | Same Class | Derived Class | Outside Class |
|----------------|------------|---------------|---------------|
| private        | ✓          | ❌            | ❌            |
| protected      | ✓          | ✓             | ❌            |
| public         | ✓          | ✓             | ✓             |

### Example:
```cpp
class Base {
private:
    int privateVar;    // Only Base can access
protected:
    int protectedVar;  // Base and derived can access
public:
    int publicVar;     // Everyone can access
};

class Derived : public Base {
public:
    void func() {
        // privateVar = 5;    // ERROR! ❌
        protectedVar = 10;    // OK! ✓
        publicVar = 15;       // OK! ✓
    }
};
```

---

## 14. CLASS ACCESS SPECIFIERS (Lecture 3 & 4)

### Three Types of Inheritance:
1. **public** inheritance: Most common
2. **protected** inheritance: Rarely used
3. **private** inheritance: Used for implementation hiding

### How Base Members Appear in Derived Class:

| Base Class Member | public inheritance | protected inheritance | private inheritance |
|-------------------|-------------------|----------------------|---------------------|
| private           | inaccessible      | inaccessible         | inaccessible        |
| protected         | protected         | protected            | private             |
| public            | public            | protected            | private             |

### Examples:
```cpp
// PUBLIC INHERITANCE (most common)
class Test : public Grade {
    // Grade's public → public in Test
    // Grade's protected → protected in Test
};

// PROTECTED INHERITANCE
class Test : protected Grade {
    // Grade's public → protected in Test
    // Grade's protected → protected in Test
};

// PRIVATE INHERITANCE
class Test : private Grade {
    // Grade's public → private in Test
    // Grade's protected → private in Test
};
```

---

## 15. CONSTRUCTORS/DESTRUCTORS IN INHERITANCE (Lecture 3)

### Order of Execution:

**Creation (Constructor)**:
1. Base class constructor runs FIRST
2. Derived class constructor runs SECOND

**Destruction (Destructor)**:
1. Derived class destructor runs FIRST
2. Base class destructor runs SECOND

### Example:
```cpp
class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
    Derived d;
    return 0;
}
```

**Output**:
```
Base constructor
Derived constructor
Derived destructor
Base destructor
```

---

## 16. CONSTRUCTOR CHAINING (Lecture 3)

### The Problem:
When creating a derived object, the compiler must initialize the base part first, but doesn't know which base constructor to use.

### The Solution:
Call base constructor in derived constructor's initialization list:

```cpp
class Rectangle {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
        // Call base constructor with side for both width and height
    }
};

int main() {
    Square s(5);  // Creates 5x5 square
}
```

### Full Example:
```cpp
class Vehicle {
protected:
    string brand;
    int year;
public:
    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle constructor" << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;
public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {
        cout << "Car constructor" << endl;
    }
};

int main() {
    Car myCar("Toyota", 2020, 4);
    // Vehicle constructor
    // Car constructor
}
```

---

## 17. FUNCTION OVERRIDING (Lecture 3)

### Definition:
Derived class provides its own implementation of a function already defined in base class.

### Requirements:
- Same function name
- Same parameter list (signature)
- Different implementation

### Example:
```cpp
class Shape {
public:
    void display() {
        cout << "This is a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void display() {  // Overriding
        cout << "This is a circle" << endl;
    }
};

int main() {
    Shape s;
    s.display();  // "This is a shape"
    
    Circle c;
    c.display();  // "This is a circle"
}
```

### Calling Base Class Version:
```cpp
class Circle : public Shape {
public:
    void display() {
        Shape::display();  // Call base version
        cout << "This is a circle" << endl;
    }
};
```

---

## 18. MULTILEVEL INHERITANCE (Lecture 4)

### Definition:
A class is derived from another derived class (inheritance chain).

### Example Hierarchy:
```
Employee
    ↓
Manager    Scientist
    ↓
Foreman
```

### Code Example:
```cpp
class Employee {
protected:
    string name;
    int number;
public:
    void getdata() { /* ... */ }
    void putdata() { /* ... */ }
};

class Manager : public Employee {
private:
    char title[50];
    double dues;
public:
    void getdata() { /* ... */ }
    void putdata() { /* ... */ }
};

class Foreman : public Manager {
private:
    float quotas;
public:
    void getdata() { /* ... */ }
    void putdata() { /* ... */ }
};
```

**Foreman has**:
- Its own members (quotas)
- Manager's members (title, dues)
- Employee's members (name, number)

---

## 19. MULTIPLE INHERITANCE (Lecture 4)

### Definition:
A class can be derived from MORE THAN ONE base class.

### Syntax:
```cpp
class C : public A, public B {
    // C inherits from both A and B
};
```

### Example:
```cpp
class Student {
protected:
    char school[50];
    char degree[50];
public:
    void getedu() { /* ... */ }
    void putedu() { /* ... */ }
};

class Employee {
protected:
    char name[50];
    unsigned long number;
public:
    void getdata() { /* ... */ }
    void putdata() { /* ... */ }
};

class Manager : public Employee, public Student {
    // Manager inherits from BOTH Employee and Student
private:
    char title[50];
    double dues;
public:
    void getdata() { /* ... */ }
    void putdata() { /* ... */ }
};
```

**Manager has**:
- Employee members (name, number)
- Student members (school, degree)
- Its own members (title, dues)

---

## 20. DIAMOND PROBLEM (Lecture 4)

### The Problem:
Ambiguity when a class inherits from two classes that share a common base class.

### Example:
```
    Animal
    ↙    ↘
  Dog    Cat
    ↘    ↙
    DogCat (What happens?)
```

### Ambiguity Issue:
```cpp
class A {
public:
    void display() { cout << "Class A" << endl; }
};

class B : public A {
public:
    void show() { cout << "Class B" << endl; }
};

class C : public A {
public:
    void show() { cout << "Class C" << endl; }
};

class D : public B, public C {
    // D has TWO copies of A!
};

int main() {
    D obj;
    obj.display();  // ERROR! Ambiguous - which A? ❌
    obj.show();     // ERROR! Ambiguous - B::show or C::show? ❌
}
```

### Solution 1: Specify Which Class:
```cpp
obj.B::display();  // Use B's copy of A
obj.C::display();  // Use C's copy of A
obj.B::show();     // Use B's show
obj.C::show();     // Use C's show
```

### Solution 2: Virtual Inheritance:
```cpp
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };
// Now D has only ONE copy of A
```

---

## 21. AGGREGATION (Lecture 4)

### Definition:
**"Has-a"** relationship where one class contains another class as a member, but the contained object can exist independently.

### Characteristics:
- Weaker relationship
- Child can exist without parent
- Represented by hollow diamond in UML

### Example - Department has Professors:
```cpp
class Professor {
private:
    string name;
public:
    Professor(string n) : name(n) {}
    void display() { cout << "Prof: " << name << endl; }
};

class Department {
private:
    Professor* profs[10];  // Array of pointers
    int count;
public:
    Department() : count(0) {}
    
    void addProfessor(Professor* p) {
        profs[count++] = p;
    }
};

int main() {
    Professor p1("Dr. Smith");
    Professor p2("Dr. Jones");
    
    Department dept;
    dept.addProfessor(&p1);  // Department HAS professors
    dept.addProfessor(&p2);
    
    // Professors exist independently
}
```

---

## 22. COMPOSITION (Lecture 4)

### Definition:
**Strong "has-a"** relationship where contained object cannot exist without container.

### Characteristics:
- Stronger relationship
- Child cannot exist without parent
- Contained object's lifetime controlled by container
- Represented by filled diamond in UML

### Example - Car has Engine:
```cpp
class Engine {
private:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    void start() { cout << "Engine started" << endl; }
};

class Car {
private:
    Engine engine;  // Engine is created with Car
    string model;
public:
    Car(string m, int hp) : model(m), engine(hp) {
        // Engine is constructed when Car is constructed
    }
    
    void startCar() {
        engine.start();
    }
};  // When Car is destroyed, Engine is automatically destroyed

int main() {
    Car myCar("Toyota", 150);
    myCar.startCar();
}  // Car and Engine both destroyed here
```

---

## 23. AGGREGATION VS COMPOSITION (Lecture 4)

### Comparison Table:

| Feature | Aggregation | Composition |
|---------|-------------|-------------|
| Relationship | Has-a (weak) | Part-of (strong) |
| Lifetime | Independent | Dependent |
| Example | Department has Professors | Car has Engine |
| UML Symbol | Hollow diamond | Filled diamond |
| Object Creation | Can exist separately | Created with container |
| Object Destruction | Survives container | Destroyed with container |

### Memory:
```cpp
// AGGREGATION - using pointers
class Department {
    Professor* prof;  // Points to existing object
};

// COMPOSITION - using objects
class Car {
    Engine engine;  // Engine is part of Car
};
```

---

## EXAM PREPARATION TIPS

### Common Exam Question Types:

1. **Constructor/Destructor Order**
   - Remember: Base → Derived for construction
   - Derived → Base for destruction

2. **Access Specifier Problems**
   - Can derived class access private members? NO
   - Can derived class access protected members? YES

3. **Function Overriding**
   - Which function gets called?
   - How to call base class version?

4. **Multiple Inheritance Ambiguity**
   - Identify ambiguous calls
   - How to resolve using `::`

5. **Aggregation vs Composition**
   - Identify relationship type
   - Understand lifetime dependencies

### What You Must Know:

✓ **Constructors**:
- Default, parameterized, copy
- Constructor initialization list syntax
- Constructor chaining in inheritance

✓ **Access Modifiers**:
- public, private, protected
- How they work in inheritance

✓ **Inheritance**:
- public, protected, private inheritance
- What derived class can access
- Constructor/destructor order

✓ **Function Overriding**:
- How to override functions
- Calling base class version with `::`

✓ **Multiple Inheritance**:
- Diamond problem
- Ambiguity resolution

✓ **Aggregation vs Composition**:
- Difference between them
- When to use each

---

## COMMON MISTAKES TO AVOID

❌ **Forgetting constructor chaining**:
```cpp
class Derived : public Base {
public:
    Derived(int x) : Base(x) { }  // Don't forget this!
};
```

❌ **Trying to access private base members**:
```cpp
class Derived : public Base {
    void func() {
        // privateBaseVar = 5;  // ERROR!
    }
};
```

❌ **Not resolving multiple inheritance ambiguity**:
```cpp
obj.display();     // ERROR if ambiguous
obj.B::display();  // CORRECT
```

❌ **Confusing aggregation and composition**:
- Aggregation: Uses pointers, independent lifetime
- Composition: Uses objects, dependent lifetime

---

## STUDY STRATEGY

### Day 1-2: Classes & Constructors
- Practice writing classes with multiple constructors
- Understand copy constructor (deep vs shallow copy)
- Know when constructors are called

### Day 3-4: Inheritance Basics
- Practice inheritance syntax
- Understand access specifiers
- Master constructor chaining

### Day 4-5: Advanced Inheritance
- Multiple inheritance examples
- Resolve diamond problem
- Aggregation vs composition

### Day 6: Practice Problems
- Write complete programs
- Trace constructor/destructor calls
- Identify and fix errors

### Day 7: Review
- Go through lecture slides again
- Review your study guide
- Practice explaining concepts out loud

---

## QUICK REFERENCE SYNTAX

### Class Definition:
```cpp
class ClassName {
private:
    // private members
protected:
    // protected members
public:
    // constructors
    ClassName();  // default
    ClassName(params);  // parameterized
    ClassName(const ClassName& other);  // copy
    
    // destructor
    ~ClassName();
    
    // methods
    void method();
};
```

### Inheritance:
```cpp
class Derived : public Base {
public:
    Derived() : Base() { }  // Constructor chaining
};
```

### Multiple Inheritance:
```cpp
class Derived : public Base1, public Base2 {
public:
    Derived() : Base1(), Base2() { }
};
```

Good luck on your midterm! 🎓📚

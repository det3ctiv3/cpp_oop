# OOP C++ Midterm Practice Quiz
## Based on Dr. Sejuti Rahman's Lectures 1-5

---

## Section 1: Multiple Choice Questions

### Question 1
What will happen if you forget to call `set_count()` in a Counter class without a constructor?

```cpp
class Counter {
private:
    unsigned int count;
public:
    void set_count() { count = 0; }
    void inc_count() { count++; }
    int get_count() { return count; }
};

int main() {
    Counter c1;
    cout << c1.get_count();  // What happens?
}
```

**A)** Prints 0  
**B)** Prints garbage value  
**C)** Compilation error  
**D)** Runtime error  

**Answer: B** - Without a constructor or calling `set_count()`, `count` has a garbage value.

**Solution**: Use a constructor!
```cpp
Counter() : count(0) { }
```

---

### Question 2
In which order are constructors and destructors called in inheritance?

```cpp
class Base {
public:
    Base() { cout << "Base "; }
    ~Base() { cout << "~Base "; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived "; }
    ~Derived() { cout << "~Derived "; }
};

int main() {
    Derived d;
    return 0;
}
```

**A)** `Base Derived ~Base ~Derived`  
**B)** `Derived Base ~Derived ~Base`  
**C)** `Base Derived ~Derived ~Base`  
**D)** `Derived Base ~Base ~Derived`  

**Answer: C** - Base constructor first, then Derived. Destructors in reverse order.

---

### Question 3
What is the default access modifier for a `class` in C++?

**A)** public  
**B)** private  
**C)** protected  
**D)** No default  

**Answer: B** - `private` is the default for classes. (`public` is default for structs)

---

### Question 4
What is the difference between passing an object by value vs by reference?

```cpp
void func1(Point p) { p.x = 10; }
void func2(Point &p) { p.x = 10; }
```

**A)** Both modify the original  
**B)** func1 modifies original, func2 doesn't  
**C)** func1 doesn't modify original, func2 does  
**D)** Neither modifies original  

**Answer: C** - Pass by value copies the object, pass by reference modifies original.

---

### Question 5
In multiple inheritance, what does a derived class inherit?

```cpp
class A { public: void funcA(); };
class B { public: void funcB(); };
class C : public A, public B { };
```

**A)** Only members from A  
**B)** Only members from B  
**C)** Members from both A and B  
**D)** No members  

**Answer: C** - Class C inherits from both A and B.

---

### Question 6
What is the "is-a" relationship in inheritance?

**A)** Composition  
**B)** Aggregation  
**C)** Inheritance  
**D)** Encapsulation  

**Answer: C** - Inheritance represents "is-a" (e.g., Dog IS-A Animal)

---

### Question 7
Can a derived class access private members of its base class?

**A)** Yes, always  
**B)** Yes, if using public inheritance  
**C)** No, never  
**D)** Only through getter methods  

**Answer: C** - Private members are NEVER accessible in derived classes. (Use protected or getters)

---

## Section 2: True or False

1. **A class can have multiple constructors with different parameters.**  
   - **TRUE** - This is called constructor overloading

2. **Structs and classes are identical in C++ except for default access.**  
   - **TRUE** - struct is public by default, class is private by default

3. **When an object is assigned to another, only pointers are copied.**  
   - **FALSE** - By default, all fields are copied (shallow copy)

4. **Protected members can be accessed by derived classes.**  
   - **TRUE** - That's the purpose of protected

5. **In multiple inheritance, a class can only inherit from two base classes.**  
   - **FALSE** - Can inherit from any number of base classes

6. **Constructor initialization lists are optional.**  
   - **FALSE** - They're required for const members and when calling base constructors

7. **In composition, the contained object's lifetime depends on the container.**  
   - **TRUE** - The engine dies when the car dies

8. **Function overriding requires the same function signature in derived class.**  
   - **TRUE** - Same name and parameters

---

## Section 3: Code Analysis - Find the Errors

### Problem 1

```cpp
class Counter {
private:
    unsigned int count;
public:
    void inc_count() {
        count++;  // ERROR: count not initialized!
    }
};
```

**Error**: No constructor to initialize `count`. It will have garbage value.

**Fix**:
```cpp
Counter() : count(0) { }
```

---

### Problem 2

```cpp
class Employee {
private:
    string name;
public:
    Employee(string n) : name(n) { }
};

class Manager : public Employee {
public:
    Manager(string n) {  // ERROR: Not calling base constructor!
        // ...
    }
};
```

**Error**: Must call base class constructor in initialization list.

**Fix**:
```cpp
Manager(string n) : Employee(n) { }
```

---

### Problem 3

```cpp
class Base {
private:
    int x;
protected:
    int y;
};

class Derived : public Base {
public:
    void func() {
        x = 10;  // ERROR: Cannot access private member!
        y = 20;  // OK
    }
};
```

**Error**: Cannot access private members of base class.

**Fix**: Make `x` protected or provide a setter.

---

### Problem 4

```cpp
class A {
public:
    void display() { cout << "A" << endl; }
};

class B {
public:
    void display() { cout << "B" << endl; }
};

class C : public A, public B {
};

int main() {
    C obj;
    obj.display();  // ERROR: Ambiguous!
}
```

**Error**: Ambiguity in multiple inheritance - which display()?

**Fix**:
```cpp
obj.A::display();  // Specify which one
obj.B::display();
```

---

## Section 4: What's the Output?

### Problem 1

```cpp
class Point {
public:
    double x, y;
    Point() { x = 0; y = 0; }
    Point(double nx, double ny) { x = nx; y = ny; }
};

int main() {
    Point p1;
    Point p2(5.0, 10.0);
    cout << p1.x << " " << p2.x;
}
```

**Output**: `0 5`

---

### Problem 2

```cpp
class A {
public:
    A() { cout << "A "; }
    ~A() { cout << "~A "; }
};

class B : public A {
public:
    B() { cout << "B "; }
    ~B() { cout << "~B "; }
};

class C : public B {
public:
    C() { cout << "C "; }
    ~C() { cout << "~C "; }
};

int main() {
    C obj;
    return 0;
}
```

**Output**: `A B C ~C ~B ~A`

**Explanation**: Multilevel inheritance - constructors go A→B→C, destructors go C→B→A

---

### Problem 3

```cpp
class Shape {
public:
    void display() { cout << "Shape "; }
};

class Circle : public Shape {
public:
    void display() { cout << "Circle "; }
};

int main() {
    Circle c;
    c.display();
    c.Shape::display();
}
```

**Output**: `Circle Shape`

**Explanation**: First calls Circle's overridden version, then explicitly calls base version.

---

## Section 5: Short Answer Questions

### Question 1
**Explain the difference between aggregation and composition with examples.**

**Answer:**

**Aggregation** (Has-a, weak relationship):
- Container and contained can exist independently
- Example: Department HAS Professors
- Professors can exist without the department
- Uses pointers typically

**Composition** (Part-of, strong relationship):
- Contained cannot exist without container
- Example: Car HAS Engine
- Engine cannot exist without the car
- Uses objects directly
- Contained object destroyed when container is destroyed

---

### Question 2
**Why do we need a custom copy constructor?**

**Answer:**

Default copy constructor does **shallow copy** - copies pointer addresses.

**Problem**:
```cpp
Student s1;
s1.name = "Alice";
Student s2 = s1;  // Both point to same memory
s2.name[0] = 'B';
// Now s1.name is "Blice" too! BAD!
```

**Solution**: Custom copy constructor does **deep copy** - allocates new memory:
```cpp
Student(const Student& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}
```

---

### Question 3
**What is constructor chaining and why is it necessary?**

**Answer:**

**Constructor chaining** = Calling base class constructor from derived class constructor.

**Why necessary**: Base class must be initialized before derived class.

```cpp
class Rectangle {
public:
    Rectangle(double w, double h) { ... }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
        // Must call Rectangle constructor!
    }
};
```

Without it, compiler doesn't know which base constructor to use.

---

### Question 4
**What is the diamond problem in multiple inheritance?**

**Answer:**

**Diamond Problem**: When a class inherits from two classes that share a common base.

```
    Animal
    ↙    ↘
  Dog    Cat
    ↘    ↙
    DogCat
```

**Problem**: DogCat has TWO copies of Animal!

**Solutions**:
1. Specify which one: `obj.Dog::animalMethod()`
2. Virtual inheritance: `class Dog : virtual public Animal`

---

## Section 6: Coding Problems

### Problem 1: Implement Student Class
Write a complete Student class with:
- Private: name, id
- Constructor (parameterized)
- Copy constructor
- display() method

**Solution**:
```cpp
class Student {
private:
    string name;
    int id;
    
public:
    Student(string n, int i) : name(n), id(i) { }
    
    Student(const Student& other) {
        name = other.name;
        id = other.id;
    }
    
    void display() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};
```

---

### Problem 2: Create Inheritance Hierarchy
Design classes for:
- Base: `Vehicle` (brand, year)
- Derived: `Car` (adds doors)
- Include constructors with chaining

**Solution**:
```cpp
class Vehicle {
protected:
    string brand;
    int year;
    
public:
    Vehicle(string b, int y) : brand(b), year(y) { }
    
    void display() {
        cout << brand << " (" << year << ")" << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;
    
public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) { }
    
    void display() {
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }
};
```

---

### Problem 3: Fix Multiple Inheritance Ambiguity

```cpp
class A {
public:
    void show() { cout << "A"; }
};

class B {
public:
    void show() { cout << "B"; }
};

class C : public A, public B { };

int main() {
    C obj;
    // How to call both show() methods?
}
```

**Solution**:
```cpp
obj.A::show();  // Calls A's show
obj.B::show();  // Calls B's show
```

Or create wrapper:
```cpp
class C : public A, public B {
public:
    void showA() { A::show(); }
    void showB() { B::show(); }
};
```

---

## Section 7: Trace the Code

### Problem 1

```cpp
class Base {
public:
    Base() { cout << "1 "; }
    ~Base() { cout << "2 "; }
};

class Derived : public Base {
public:
    Derived() { cout << "3 "; }
    ~Derived() { cout << "4 "; }
};

int main() {
    Derived d;
    cout << "5 ";
    return 0;
}
```

**Output**: `1 3 5 4 2`

**Explanation**:
1. Create Derived → calls Base constructor (1)
2. Then Derived constructor (3)
3. Main prints (5)
4. Destroy Derived → calls Derived destructor (4)
5. Then Base destructor (2)

---

## Exam Strategy Tips

### Time Management:
1. **Read all questions first** (5 min)
2. **Answer easy ones first** (15 min)
3. **Tackle medium difficulty** (20 min)
4. **Handle hard problems** (15 min)
5. **Review answers** (5 min)

### Common Traps to Avoid:
❌ Forgetting constructor chaining  
❌ Trying to access private base members  
❌ Not initializing variables  
❌ Ambiguous multiple inheritance calls  
❌ Mixing up constructor/destructor order  

### Quick Checklist Before Exam:
✅ Know constructor types (default, parameterized, copy)  
✅ Understand deep vs shallow copy  
✅ Remember access specifiers (public, protected, private)  
✅ Know inheritance types and access  
✅ Understand constructor/destructor order  
✅ Can resolve multiple inheritance ambiguity  
✅ Know difference between aggregation and composition  

---

## Final Tips

### What to Memorize:
1. **Constructor syntax**: `ClassName() : member(value) { }`
2. **Inheritance syntax**: `class Derived : public Base`
3. **Copy constructor**: `ClassName(const ClassName& other)`
4. **Calling base method**: `BaseClass::method()`
5. **Resolving ambiguity**: `obj.ClassA::method()`

### Practice Strategy:
- Day 1-2: Classes, constructors, copy constructors
- Day 3-4: Inheritance basics, access specifiers
- Day 5: Multiple inheritance, function overriding
- Day 6: Aggregation/composition, practice problems
- Day 7: Take full practice tests

**Good luck on your midterm! 🎓**

---

## Section 2: True or False

1. **A class can have multiple destructors.** 
   - **FALSE** - Only one destructor per class

2. **A pure virtual function must be implemented in the base class.**
   - **FALSE** - It's implemented in derived classes

3. **Virtual destructors are important when using polymorphism.**
   - **TRUE** - Ensures proper cleanup in inheritance hierarchies

4. **Private members of a base class are accessible in derived classes.**
   - **FALSE** - Only public and protected members are accessible

5. **An abstract class can be instantiated.**
   - **FALSE** - Abstract classes cannot be instantiated

---

## Section 3: Code Analysis

### Problem 1: Find the Errors

```cpp
class Book {
    string title;
    int pages;
public:
    Book(string t, int p) {
        title = t;
        pages = p;
    }
    
    // Copy constructor
    Book(Book other) {  // ERROR 1: Missing const reference
        title = other.title;
        pages = other.pages;
    }
    
    // Assignment operator
    void operator=(const Book& other) {  // ERROR 2: Should return Book&
        title = other.title;
        pages = other.pages;
        // ERROR 3: Missing return *this
    }
};
```

**Corrected Code:**
```cpp
Book(const Book& other) {
    title = other.title;
    pages = other.pages;
}

Book& operator=(const Book& other) {
    if (this != &other) {  // Also add self-assignment check
        title = other.title;
        pages = other.pages;
    }
    return *this;
}
```

---

### Problem 2: What's the Output?

```cpp
class A {
public:
    A() { cout << "A "; }
    virtual ~A() { cout << "~A "; }
    virtual void print() { cout << "A::print "; }
};

class B : public A {
public:
    B() { cout << "B "; }
    ~B() { cout << "~B "; }
    void print() override { cout << "B::print "; }
};

int main() {
    A* ptr = new B();
    ptr->print();
    delete ptr;
    return 0;
}
```

**Output:** `A B B::print ~B ~A`

**Explanation:**
1. Base constructor (A) called
2. Derived constructor (B) called
3. `ptr->print()` calls B's version (virtual function)
4. `delete ptr` calls B's destructor first (virtual destructor)
5. Then A's destructor

---

## Section 4: Short Answer

### Question 1
**Explain the difference between shallow copy and deep copy.**

**Answer:**
- **Shallow Copy**: Copies the pointer address. Both objects point to the same memory location. Dangerous when one object is destroyed.
- **Deep Copy**: Allocates new memory and copies the actual data. Each object has its own independent copy.

### Question 2
**What is the Rule of Three?**

**Answer:**
If a class requires a user-defined:
1. Destructor (to manage resources)
2. Copy Constructor (for proper copying)
3. Assignment Operator (for proper assignment)

Then it should explicitly define all three to prevent resource management issues.

### Question 3
**Why should base class destructors be virtual?**

**Answer:**
When deleting a derived class object through a base class pointer, a virtual destructor ensures that the derived class destructor is called first, followed by the base class destructor. Without `virtual`, only the base destructor would be called, causing memory leaks.

---

## Section 5: Coding Problems

### Problem 1: Implement a Point Class
Write a complete class for 2D points with:
- Constructors (default and parameterized)
- Copy constructor
- Assignment operator
- Method to calculate distance from origin
- Display method

### Problem 2: Create an Inheritance Hierarchy
Design classes for:
- Base class: `Employee` (name, id, salary)
- Derived class: `Manager` (adds: department, bonus)
- Derived class: `Developer` (adds: programming language, projects)

Include:
- Appropriate constructors
- Virtual function `calculatePay()`
- Virtual function `displayInfo()`

### Problem 3: Fix the Memory Leak
```cpp
class Container {
    int* data;
    int size;
public:
    Container(int s) {
        size = s;
        data = new int[size];
    }
    // What's missing?
};

int main() {
    Container c(100);
    return 0;  // Memory leak here!
}
```

**Solution:** Add destructor:
```cpp
~Container() {
    delete[] data;
}
```

---

## Section 6: Exam Tips

### Common Mistakes to Avoid:
1. ❌ Forgetting to delete dynamically allocated memory
2. ❌ Not checking for self-assignment in assignment operator
3. ❌ Missing `const` in copy constructor parameter
4. ❌ Forgetting to return `*this` in assignment operator
5. ❌ Not making base class destructor virtual
6. ❌ Trying to instantiate abstract classes
7. ❌ Shallow copying objects with pointers

### Best Practices:
1. ✅ Use initialization lists in constructors
2. ✅ Always check for nullptr before using pointers
3. ✅ Make destructors virtual in base classes
4. ✅ Use `const` references for read-only parameters
5. ✅ Follow the Rule of Three/Five
6. ✅ Use `override` keyword for virtual functions (C++11)
7. ✅ Initialize all member variables

### Key Concepts to Memorize:
- Constructor initialization list syntax
- Virtual function syntax
- Pure virtual function: `= 0`
- Copy constructor signature: `ClassName(const ClassName&)`
- Assignment operator signature: `ClassName& operator=(const ClassName&)`
- Destructor syntax: `~ClassName()`

---

## Practice Strategy:

1. **Day 1-2**: Review constructors, destructors, Rule of Three
2. **Day 3-4**: Practice inheritance and constructor chaining
3. **Day 5-6**: Master virtual functions and polymorphism
4. **Day 7**: Take practice tests and review mistakes

Good luck on your midterm! 🎓

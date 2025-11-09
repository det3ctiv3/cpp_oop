# OOP C++ Midterm - Quick Reference Sheet
## Dr. Sejuti Rahman's Lectures 1-5

---

## 📖 LECTURE TOPICS

| Lecture | Topics |
|---------|--------|
| 1 | Classes, Objects, Methods, Constructors, Access Modifiers |
| 2 | Objects as Arguments, Return Objects, Static Data |
| 3 | Inheritance, Protected Members, Constructor Chaining, Overriding |
| 4 | Multilevel & Multiple Inheritance, Diamond Problem, Aggregation/Composition |
| 5 | Revision |

---

## 🔑 KEY CONCEPTS CHEAT SHEET

### 1. Class Definition
```cpp
class ClassName {
private:
    // Private members
protected:
    // Protected members
public:
    // Constructors
    ClassName();                          // Default
    ClassName(params);                    // Parameterized
    ClassName(const ClassName& other);    // Copy
    
    // Destructor
    ~ClassName();
    
    // Methods
    void method();
};
```

### 2. Constructor Types

| Type | Syntax | When Called |
|------|--------|-------------|
| Default | `Class()` | `Class obj;` |
| Parameterized | `Class(int x)` | `Class obj(5);` |
| Copy | `Class(const Class& o)` | `Class obj2 = obj1;` |

### 3. Access Modifiers

| Modifier | Same Class | Derived Class | Outside |
|----------|------------|---------------|---------|
| private | ✓ | ❌ | ❌ |
| protected | ✓ | ✓ | ❌ |
| public | ✓ | ✓ | ✓ |

### 4. Inheritance Syntax
```cpp
class Derived : public Base {
public:
    Derived() : Base() { }  // Constructor chaining
};
```

### 5. Inheritance Access

| Base Member | public | protected | private |
|-------------|--------|-----------|---------|
| private | inaccessible | inaccessible | inaccessible |
| protected | protected | protected | private |
| public | public | protected | private |

### 6. Constructor/Destructor Order

**Construction**: Base → Derived  
**Destruction**: Derived → Base

```cpp
Base()      // 1st
Derived()   // 2nd
~Derived()  // 3rd
~Base()     // 4th
```

### 7. Multiple Inheritance
```cpp
class C : public A, public B {
public:
    C() : A(), B() { }
};

// Resolve ambiguity:
obj.A::method();
obj.B::method();
```

### 8. Aggregation vs Composition

| Feature | Aggregation | Composition |
|---------|-------------|-------------|
| Relationship | Has-a (weak) | Part-of (strong) |
| Lifetime | Independent | Dependent |
| Implementation | Pointers | Objects |
| Example | Dept has Profs | Car has Engine |

---

## 💡 COMMON EXAM PATTERNS

### Pattern 1: Constructor Order
```cpp
class A { A() { cout << "A "; } };
class B : public A { B() { cout << "B "; } };
int main() { B obj; }
```
**Output**: `A B`

### Pattern 2: Access Error
```cpp
class Base { private: int x; };
class Derived : public Base {
    void func() { x = 5; }  // ERROR!
};
```

### Pattern 3: Missing Constructor Chain
```cpp
class Base { Base(int x) { } };
class Derived : public Base {
    Derived(int x) { }  // ERROR! Must call Base(x)
};
// FIX: Derived(int x) : Base(x) { }
```

### Pattern 4: Multiple Inheritance Ambiguity
```cpp
class A { void f(); };
class B { void f(); };
class C : public A, public B { };
C obj;
obj.f();  // ERROR! Ambiguous
// FIX: obj.A::f(); or obj.B::f();
```

### Pattern 5: Shallow vs Deep Copy
```cpp
class String {
    char* str;
    // Need custom copy constructor!
    String(const String& o) {
        str = new char[strlen(o.str) + 1];
        strcpy(str, o.str);
    }
};
```

---

## ⚡ QUICK SYNTAX REFERENCE

### Pass by Value vs Reference
```cpp
void func(Class obj);    // Pass by value (copy)
void func(Class &obj);   // Pass by reference (original)
```

### Method Implementation
```cpp
// In header:
class Point {
    void print();
};

// In .cpp:
void Point::print() {
    // implementation
}
```

### Calling Base Class Method
```cpp
class Derived : public Base {
    void method() {
        Base::method();  // Call base version
    }
};
```

### Constructor Initialization List
```cpp
Class(int x, int y) : member1(x), member2(y) {
    // body
}
```

---

## 🎯 MEMORIZE THESE

### 1. Constructor Rules
- Same name as class
- No return type
- Can be overloaded
- Base constructor called first

### 2. Copy Constructor
- Called on: initialization, pass by value, return by value
- Syntax: `Class(const Class& other)`
- Use for: Deep copy when class has pointers

### 3. Inheritance Rules
- Derived inherits all base members (but may not access all)
- Cannot access private base members
- Use `protected` for derived class access
- Constructor chaining required

### 4. Multiple Inheritance
- Can inherit from multiple classes
- Use `::` to resolve ambiguity
- Diamond problem solved with virtual inheritance

---

## 🚨 COMMON MISTAKES

1. ❌ Forgetting to initialize members
   ```cpp
   Counter() : count(0) { }  // ✓ Always initialize
   ```

2. ❌ Not calling base constructor
   ```cpp
   Derived(int x) : Base(x) { }  // ✓ Must chain
   ```

3. ❌ Trying to access private base members
   ```cpp
   // In Base:
   protected: int x;  // ✓ Use protected
   ```

4. ❌ Ambiguous multiple inheritance
   ```cpp
   obj.A::method();  // ✓ Specify which class
   ```

5. ❌ Missing copy constructor for pointers
   ```cpp
   // ✓ Always implement deep copy
   ```

---

## 📝 EXAM CHECKLIST

Before the exam, make sure you can:

✅ Write a class with multiple constructors  
✅ Implement a copy constructor (deep copy)  
✅ Explain public/private/protected  
✅ Create inheritance with constructor chaining  
✅ Override functions in derived class  
✅ Resolve multiple inheritance ambiguity  
✅ Explain aggregation vs composition  
✅ Trace constructor/destructor order  

---

## 🕐 LAST MINUTE REVIEW (10 minutes before exam)

1. **Constructor order**: Base → Derived
2. **Destructor order**: Derived → Base
3. **Can't access**: private base members
4. **Can access**: protected and public base members
5. **Resolve ambiguity**: `obj.ClassName::method()`
6. **Copy constructor**: For deep copy
7. **Constructor chaining**: `Derived() : Base() { }`
8. **Default access**: class = private, struct = public

---

## 📞 QUICK FORMULAS

### Inheritance Relationship
```
Base (parent, superclass)
  ↓
Derived (child, subclass)
```

### Multiple Inheritance
```
Class A    Class B
     ↘    ↙
      Class C
```

### Multilevel Inheritance
```
Class A
  ↓
Class B
  ↓
Class C
```

---

## 💪 CONFIDENCE BOOSTERS

You've got this! Remember:
- Read questions carefully
- Start with easy ones
- Check for tricky private/protected access
- Watch for constructor chaining
- Resolve ambiguity with `::`
- Always initialize variables

**Good luck! 🍀**

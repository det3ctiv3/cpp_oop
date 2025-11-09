#include <iostream>

class Person {
    public:
    std::string name;
    int age;

    
    
    Person(std::string n, int a) : name(n), age(a) {}

    void introduce() {
        std::cout << "My name is " << name << ", and I'm " << age << " years old." ;
    }
    void have_birthday() {
        age++;
        std::cout << "Happy birthday " << name << "! You are now " << age << " years old." << std::endl;
    }
    ~Person() {
        std::cout << "Person object is being destroyed." << std::endl;
    }
};


class Student : public Person {
    private:
    std::string university;
    public:
    Student(std::string name, int age, std::string university) : Person(name, age), university(university) {
        std::cout << "The student has been created." << std::endl;
    }
    void introduce() {
        Person::introduce();
        std::cout << " I study at " << university << std::endl; // Call base class introduce
    }
    void study() {
        std::cout << name << " is studying at " << university << "." << std::endl;
    }   
    void study(std::string name, std::string university) {
        std::cout << name << " is studying at " << university << "." << std::endl;
    }
};



int main(){
    Student s1("Rustambek", 20, "MIT"); 
    s1.introduce();
    s1.have_birthday();
    s1.study();
    s1.introduce();
    return 0;

};
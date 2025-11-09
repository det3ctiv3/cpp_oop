#include <iostream>

class Person {
    private:
    int nationalID;
    protected:
    std::string name;
    int age;

    public:
    
    Person() {
        std::cout << "Default constructor of Person is called" << std::endl;
    }
    Person(std::string n, int a, int id) : name(n), age(a), nationalID(id){
        std::cout <<"Person constructor is called" << std::endl;
    }

    void setName(std::string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    void setNationalID(int id) {
        nationalID = id;
    }

    void displayPerson(){
        std::cout << "Name: " << name << ", Age: " << age << ", National ID: " << nationalID << std::endl;
    }
    ~Person() {
        std::cout << "Person destructor is called" << std::endl;
    }
   
};


class Student : virtual public Person {

    protected:
    float gpa;
    public:
    Student() : Person(){
        std::cout << "Default constructor of Student is called" << std::endl;
    }
    Student(std::string n, int a, int id, float g) : Person(n, a, id), gpa(g){
        std::cout << "Student constructor is called" << std::endl;
    }
    void setGpa(float g){
        gpa = g;
    }
    void displayStudent(){
        displayPerson();
        std::cout << "GPA: " << gpa << std::endl;
    }

    ~Student() {
        std::cout << "Student destructor is called" << std::endl;
    }

};



class Teacher : virtual public Person {

    private:
    std::string subject;
    public:
    Teacher() : Person(){
        std::cout << "Default constructor of Teacher is called" << std::endl;

    }

    Teacher(std::string n, int a, int id, std::string sub) : Person(n, a, id), subject(sub){
        std::cout << "Teacher constructor is called" << std::endl;
    
    }

    void setsubject(std::string sub){
        subject = sub;
    }
    void showRole(){
        std::cout << "I am a teacher, Subject I teach: " << subject << std::endl;
    }
    void displayTeacher(){
        displayPerson();
        std::cout << "I teach " << subject << std::endl;
    }
    ~Teacher(){
        std::cout << "Teacher destructor is called" << std::endl;
    
    }

};


class TeachingAssistant : public Student, public Teacher {
    private:
    int hoursPerWeek;
    public:
    TeachingAssistant(): Student(), Teacher(){
        std::cout << "Default constructor of TeachingAssistant is called" << std::endl;
    }
    TeachingAssistant(std::string n, int a, int id, float g, std::string sub, int hours) : Student(n, a, id, g), Teacher(n, a, id, sub), hoursPerWeek(hours){
        std::cout << "TeachingAssistant constructor is called" << std::endl;
    }


    void setTAInfo(int hours){
        hoursPerWeek = hours;
    }
    void displayTA(){
        Student::displayStudent();
        Teacher::showRole();
        std::cout << "Hours per week: " << hoursPerWeek << std::endl;
    }
    ~TeachingAssistant(){
        std::cout << "TeachingAssistant destructor is called" << std::endl;
    }


};


int main(){
    TeachingAssistant ta("Alice", 24, 123456, 3.8, "Mathematics", 20);
    ta.displayTA();
    return 0;
}




#include <iostream>

class Vehicle {
    private:
    std::string make;
    int year;

    public:
    Vehicle(std::string make, int year) {
        make = make;
        year = year;
    }

    void displayInfo() {
        std::cout << "Make: " << make << std::endl;
        std::cout << "Year: " << year << std::endl;
    }    
};

class Car : public Vehicle {
    private:
    int numDoors;

    public:
    Car(std::string make, int year, int doors) : Vehicle(make, year) {
        numDoors = doors;
    }

    void honk() {
        std::cout << "Beep beep!" << std::endl;
    }
};

int main() {
    Car myCar("Toyota", 2020, 4);
    myCar.displayInfo();
    myCar.honk();
    return 0;
}
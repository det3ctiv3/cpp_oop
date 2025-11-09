#include <iostream>
class Distance {
    int meters;
    double centimeters;
    public:
    Distance() : meters(0), centimeters(0.0) {}
    Distance(int m, double cm) : meters(m), centimeters(cm) {}
    void normalize(){
        while(centimeters >=100.0){
            centimeters -=100.0;
            meters +=1;
        }
        while(centimeters <0.0){
            centimeters +=100.0;
            meters -=1;
        }
    }
    void get_data(){
        std::cout << "Enter meters: ";
        std::cin >> meters;
        std::cout << "Enter centimeters: ";
        std::cin >> centimeters;
        normalize();
            
    }
    void show_data() {
        std::cout << "Meters: " << meters << ", Centimeters: " << centimeters << std::endl;
    }

    Distance operator++(){ //prefix
        ++centimeters;
        normalize();
        return *this;
    }


    Distance operator++(int){ //postfix
        Distance temp = *this;
        centimeters++;
        normalize();
        return temp;

    }

    Distance operator--(){
        --centimeters;
        normalize();
        return *this;
    }

    Distance operator--(int){
        Distance temp = *this;
        centimeters--;
        normalize();
        return temp;
    }

    Distance operator+(const Distance d)const{
        Distance temp;
        temp.meters = meters + d.meters;
        temp.centimeters = centimeters + d.centimeters;
        temp.normalize();
        return temp;
    }
    Distance operator-(const Distance d)const{
        Distance temp;
        temp.meters = meters - d.meters;
        temp.centimeters = centimeters - d.centimeters;
        temp.normalize();
        return temp;
    }

    Distance operator*(Distance const d) const{
        double c1 = meters * 100.0 + centimeters;
        double c2 = d.meters * 100.0 + d.centimeters;
        double product = c1 * c2;
        Distance temp;
        temp.meters = product/10000;
        temp.centimeters = product/100-temp.meters*100;
        temp.normalize();
        return temp;
    }

    bool operator==(const Distance d)const{
        return (meters == d.meters && centimeters == d.centimeters);
    }

    Distance operator+=(const Distance d){
        meters += d.meters;
        centimeters += d.centimeters;
        normalize();
        return *this;

    }

    Distance operator-=(const Distance d){
        meters -= d.meters;
        centimeters -= d.centimeters;
        normalize();
        return *this;
    }
    Distance operator*=(const Distance d){
        meters -= d.meters;
        centimeters -= d.centimeters;
        normalize();
        return *this;
    }
};

int main(){
    Distance d1(2, 75), d2(3, 50), d3;
    std::cout << "Initial Distances:\n";
    d1.show_data();
    d2.show_data();
    std::cout << "\nTesting + operator:\n";
    d3 = d1 + d2;
    d3.show_data();
    std:: cout << "\nTesting - operator:\n";
    d3 = d1 - d2;
    d3.show_data();
    std::cout << "\nTesting * operator:\n";
    d3 = d1 * d2;
    d3.show_data();
    std::cout << "\nTesting prefix ++:\n";
    ++d1;
    d1.show_data();
    std::cout << "\nTesting postfix ++:\n";
    d1++;
    d1.show_data();
    std::cout << "\nTesting prefix --:\n";
    --d2;
    d2.show_data();
    std::cout << "\nTesting postfix --:\n";
    d2--;
    d2.show_data();
    std::cout << "\nTesting == operator:\n";
    if (d1 == d2)
        std::cout << "Equal distances\n";
    else
        std::cout << "Not equal\n";
    std::cout << "\nTesting +=, -=, *= operators:\n";
    d1 += d2;
    d1.show_data();
    d1 -= d2;
    d1.show_data();
    d1 *= d2;
    d1.show_data();
    return 0;

}
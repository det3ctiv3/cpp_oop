//
// Created by det3ctive on 8/26/25.
//

#include <iostream>
using namespace std;
int main() {
    int number;
    cin >> number;
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;

    }
    cout << sum << endl;



}
//
// Created by det3ctive on 8/26/25.
//

//
// Created by det3ctive on 8/26/25.
//

#include <iostream>
using namespace std;
int main() {
    int number;
    cin >> number;
    int arr[number];
    for (int i = 0; i < number; i++) {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 1; i < number; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

    }
    cout << max << endl;

}
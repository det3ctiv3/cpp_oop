//
// Created by det3ctive on 8/26/25.
//

//
// Created by det3ctive on 8/26/25.
//

#include <iostream>
#include <math.h>
#include <bits/valarray_after.h>
using namespace std;


bool isPrime(int x) {
    if (x <= 1) return false;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;

    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (isPrime(i)) {
            cout << "Prime" << endl;
        }
        else {
            cout << "Not prime" << endl;
        }

    }
    return 0;

}
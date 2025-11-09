//
// Created by det3ctive on 8/26/25.
//

//
// Created by det3ctive on 8/26/25.
//

#include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (isPrime(i)) {
            cout << i << endl;

        }

    }
    return 0;

}
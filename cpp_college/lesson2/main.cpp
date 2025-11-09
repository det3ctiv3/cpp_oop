//
// Created by det3ctive on 9/2/25.
//
#include <iostream>
using namespace std;

float minimum(float a, float b, float c) {
    if (a<b && a<c) {
        return a;
    }
    else if (b<a && b<c) {
        return b;
    }
    else {
        return c;
    }
}
float maximum(float a, float b, float c) {
    if (a>b && a>c) {
        return a;
    }
    else if (b>a && b>c) {
        return b;
    }
    else {
        return c;
    }
}


int main() {
    float a, b, c;
    cin >> a >> b >> c;
    cout << minimum(a, b, c) << endl;
    cout << maximum(a, b, c) << endl;
    float mid=a+b+c-minimum(a,b,c)-maximum(a,b,c);
    cout<<mid<<endl;


    return 0;

}
//
// Created by det3ctive on 9/2/25.
//

#include <iostream>
using namespace std;




int main() {
    int num;
    cin>>num;
    if (num<0) {
        cout<<"Not a palindrome";
    }
    else {
        int r=0;
        int temp=num;
        while (temp>0) {
            r=r*10+temp%10;
            temp=temp/10;
        }
    if (r==num) {
        cout<<"Palindrome";

    }
        else {
            cout<<"Not a palindrome";
        }
    }

}
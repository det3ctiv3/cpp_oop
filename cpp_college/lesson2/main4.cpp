
//
// Created by det3ctive on 9/2/25.
//

#include <iostream>
using namespace std;
#include <string>
#include <algorithm> // For std::transform
#include <cctype>

std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return s;
}
int main() {
    srand(time(0));
    int r=1+rand()%15;
    int num;
    while (true) {
        cin>>num;
        if (num==r) {
            cout<<"You won!"<<endl;
            break;
        }
        else {
            cout<<"No! Want to continue?"<<endl;
            std::string resp;
            cin>>resp;

            if (to_lower(resp)=="no") {
                break;
            }
            else if (to_lower(resp)!="yes") {
                cout<<"Wrong input, buddy"<<endl;
                cin>>resp;
            }
        }
    }
}
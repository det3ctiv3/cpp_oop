#include <iostream>
#include <string>
#include "bro.h"

int main(){
    Monster k1 = Monster();
    k1.name ;
    std::cout<< k1.name << std::endl;
    std::cout<< k1.health << std::endl;
    std::cout<< k1.is_alive << std::endl;
    return 0;
}
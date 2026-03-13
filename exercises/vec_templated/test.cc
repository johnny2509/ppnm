#include "vect.h"
#include <iostream>

int main(){

    vec<double> a(1.0,2.0,3.0);
    vec<double> b(4.0,5.0,6.0);

    vec<float> c(1.f,2.f,3.f);
    vec<float> d(4.f,5.f,6.f);

    std::cout << a + b << std::endl;
    std::cout << c + d << std::endl;
}

#include<cmath>
#include<complex>
#include<iostream>
#include<numbers>
#include"sfuns.h"

using complex=std::complex<double>;

constexpr double  π = 3.14159265358979324;
constexpr double  E = 2.71828182845904523;
constexpr complex I = complex(0,1);

int main(){

    std::printf("Task %d.\n", 1);
        
    std::cout << "sqrt(2)=" << std::sqrt(2) << "\n";
    std::cout << "2^(1/5)=" << std::pow(2, 1.0/5.0) << "\n";
    std::cout << "E^π=" << std::pow(E, π) << "\n";
    std::cout << "E^I=" << std::pow(E, I) << "\n";
    std::cout << "π^E=" << std::pow(π, E) << "\n";

    std::cout << "π^I=" << std::pow(π, I) << "\n";
    std::cout << "E^I=" << std::pow(E, I) << "\n";
    std::cout << "I^I=" << std::pow(I, I) << "\n";
    std::cout << "log(I)=" << std::log(I) << "\n";

    {
    std::printf("Task %d.\n", 2);
    std::cout << "Gamma(1)=" << sfuns::fgamma(1) << "\n";
    std::cout << "Gamma(2)=" << sfuns::fgamma(2) << "\n";
    std::cout << "Gamma(3)=" << sfuns::fgamma(3) << "\n";
    std::cout << "Gamma(4)=" << sfuns::fgamma(4) << "\n";
    std::cout << "Gamma(5)=" << sfuns::fgamma(5) << "\n";
    std::cout << "Gamma(6)=" << sfuns::fgamma(6) << "\n";
    std::cout << "Gamma(7)=" << sfuns::fgamma(7) << "\n";
    std::cout << "Gamma(8)=" << sfuns::fgamma(8) << "\n";
    std::cout << "Gamma(9)=" << sfuns::fgamma(9) << "\n";
    std::cout << "Gamma(10)=" << sfuns::fgamma(10) << "\n";
    }

    {
    std::printf("Task %d.\n", 3);
    std::cout << "lnGamma(1)=" << sfuns::lngamma(1) << "\n";
    std::cout << "lnGamma(2)=" << sfuns::lngamma(2) << "\n";
    std::cout << "lnGamma(3)=" << sfuns::lngamma(3) << "\n";
    std::cout << "lnGamma(4)=" << sfuns::lngamma(4) << "\n";
    std::cout << "lnGamma(5)=" << sfuns::lngamma(5) << "\n";
    std::cout << "lnGamma(6)=" << sfuns::lngamma(6) << "\n";
    std::cout << "lnGamma(7)=" << sfuns::lngamma(7) << "\n";
    std::cout << "lnGamma(8)=" << sfuns::lngamma(8) << "\n";
    std::cout << "lnGamma(9)=" << sfuns::lngamma(9) << "\n";
    std::cout << "lnGamma(10)=" << sfuns::lngamma(10) << "\n";
    }

    return 0;
}

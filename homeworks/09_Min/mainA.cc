#include "min.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

// This block of code was realized by Chat GPT Instant 5.3.

int main(){

	std::cout.precision(15);

    auto rosenbrock = [](const pp::vector& x){
        double X = x[0];
        double Y = x[1];
        return std::pow(1-X, 2) + 100*std::pow(Y - X*X, 2);
    };

    auto himmelblau = [](const pp::vector& x){
        double X = x[0];
        double Y = x[1];
        return std::pow(X*X + Y - 11, 2) + std::pow(X + Y*Y - 7, 2);
    };

    pp::vector start_r(2);
    start_r[0] = -2;
    start_r[1] = 2;
    int steps_r;
    pp::vector minimum_r = pp::newton(rosenbrock, start_r, 1e-6, 1000, &steps_r);
    std::ofstream outr("rosenbrock.txt");
    outr << "# x y steps\n";
    outr << minimum_r[0] << " " << minimum_r[1] << " " << rosenbrock(minimum_r) << " " << steps_r << "\n";
    outr.close();

    pp::vector start_h(2);
    start_h[0] = 4;
    start_h[1] = 4;
    int steps_h;
    pp::vector minimum_h = pp::newton(himmelblau, start_h, 1e-6, 1000, &steps_h);
    std::ofstream outh("himmelblau.txt");
    outh << "# x y steps\n";
    outh << minimum_h[0] << " " << minimum_h[1] << " " << himmelblau(minimum_h) << " " << steps_h << "\n";
    outh.close();

}
// Task 2: plot the gamma-function together with several of its tabulated values (Wikipedia)
#include <iostream>
#include <cmath>
#include <vector>
#include <numbers>
#include <utility>
#include "gnuplot-iostream.h"

constexpr double PI = 3.14159265358979324;

double my_sgamma(double x){
	if(x < 0) return PI / std::sin(PI * x) / my_sgamma(1 - x);
	if(x < 9) return my_sgamma(x + 1) / x;
	double lnsgamma = std::log(2 * PI) / 2 + (x - 0.5) * std::log(x) - x
    	+ (1.0 / 12) / x - (1.0 / 360) / (x * x * x) + (1.0 / 1260) / (x * x * x * x * x);
	return std::exp(lnsgamma);
}
int main(){
        std::vector <std::pair <double, double>> curve;
        for(double x = 0; x <= 3.2; x += 0.05){
                curve.push_back({x, my_sgamma(x)});
        }
        Gnuplot gp;
        gp << "plot '-' with lines title 'Stirling approximation', "
              "'wiki_fact.dat' with points pt 7 ps 1.5 title 'Wikipedia values'\n";
        gp.send1d(curve);
}

// Task 2: plot the gamma-function together with several of its tabulated values (Wikipedia)
#include <iostream>
#include <cmath>
#include <vector>
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
double stirling(double x){
	if (x==0) return 0;
	return std::sqrt(2 * PI * x) * std::pow(x / std::exp(1.0), x);
}

int main(){
        std::vector <std::pair <double, double>> gamma_curve;
	std::vector <std::pair <double, double>> stirling_curve;

        for(double x = 0.001; x <= 3.2; x += 0.05){
                gamma_curve.push_back({x, my_sgamma(x + 1)}); // + 1 was added to match wikipedia plot
        	stirling_curve.push_back({x, stirling(x)});
	}

        Gnuplot gp;
	gp << "set xrange [0:3.2]\n";
	gp << "set yrange [0:6.5]\n";
	gp << "set grid\n";
	gp << "plot "
	      "'-' with lines lw 2 title 'Gamma(x+1)', "
              "'-' with lines lw 2 title 'sqrt(2*pi*x)(x/e)^x', "
              "'wiki_fact.dat' with points pt 7 ps 1.5 title 'n!'\n";
        gp.send1d(gamma_curve);
	gp.send1d(stirling_curve);
}

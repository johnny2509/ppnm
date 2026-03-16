// Task 1: plot the error-function with several tabulated values (Wikipedia)

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include "gnuplot-iostream.h"

double my_erf(double x){

	// single precision error function (Abramowitz and Stegun, from Wikipedia)
	if(x<0) return -my_erf(-x);	

	std::vector<double> a {0.254829592,-0.284496736,1.421413741,-1.453152027,1.061405429};
	double t = 1 / (1 + 0.3275911 * x);

	double sum = t * (a[0] + t * (a[1] + t * (a[2] + t * (a[3] + t * a[4]))));/* the right thing */
	return 1 - sum * std::exp(-x * x); 
}

int main(){

	std::vector <std::pair <double, double>> curve;

	for(double x = -3; x <= 3; x += 0.05){
		curve.push_back({x, my_erf(x)});
	}

	Gnuplot gp;

	gp << "plot '-' with lines title 'erf approximation', "
	      "'wiki_erf.dat' with points pt 7 ps 1.5 title 'Wikipedia values'\n";

	gp.send1d(curve);

} 
// compiles for macOS: g++ main_1.cc -o main_1 -std=c++17 \ -I/opt/homebrew/opt/boost/include \ -L/opt/homebrew/opt/boost/lib \ -lboost_iostreams

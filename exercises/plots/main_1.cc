// Task 1: plot the error-function with several tabulated values

#include <iostream>
#include <cmath>
#include <vector>
#include "gnuplot-iostream.h"

double _erf(double x){

	// single precision error function (Abramowitz and Stegun, from Wikipedia)
	if(x<0) return -erf(-x);	

	std::vector<double> a {0.254829592,-0.284496736,1.421413741,-1.453152027,1.061405429};
	double t=1/(1+0.3275911*x);

	double sum=t*(a[0]+t*(a[1]+t*(a[2]+t*(a[3]+t*a[4]))));/* the right thing */
	return 1-sum*std::exp(-x*x); 
}

int main(){

	std::vector<std::pair<double, double>> curve;
	std::vector<std::pair<double, double>> table;

	for(double x = -3; x <= 3; x += 0.05){
		curve.push_back({x, _erf(x)});

	std::vector<double> xtab = {-2, -1, 0, 1, 2};

	for(double x : xtab){
		table.push_back({, _erf(x)});
	}

	Gnuplot gp;

	gp << "plot '-' with lines title 'erf(x)', "
	      "'-' with points pt 7 ps 1.5 title 'tabulated values'\n";

	gp.send1d(curve);
	gp.send1d(table);
} 

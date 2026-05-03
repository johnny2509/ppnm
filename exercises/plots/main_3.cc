// Task 3: plot of the gamma-function, lngamma-function, and factorial
#include <iostream>
#include <cmath>
#include <vector>
#include <utility> // Chat GPT Instant 5.3
#include <limits>
#include "gnuplot-iostream.h"

constexpr double PI = 3.14159265358979324;

double lngamma(double x){
	if(x<=0) return std::numeric_limits<double>::quiet_NaN();
	if(x<9) return lngamma(x+1)-std::log(x);
	return x*std::log(x+1/(12*x-1/x/10))-x+std::log(2*PI/x)/2;
}

int main(){ // Chat GPT Instant 5.3
        
        std::vector <std::pair <double, double>> lngamma_curve; // Chat GPT Instant 5.3

        for(double x = 0.001; x <= 3.2; x += 0.05){ // Chat GPT Instant 5.3
                lngamma_curve.push_back({x, lngamma(x+1)}); // Chat GPT Instant 5.3
        }

        Gnuplot gp; // Chat GPT Instant 5.3
        gp << "set xrange [-0.1:3.2]\n";
        gp << "set yrange [-0.4:2.5]\n";
        gp << "set grid\n";
        gp << "plot "
              "'-' with lines lw 2 title 'lnGamma(x+1)', "
              "'wiki_fact.dat' using 1:(log($2)) with points pt 7 ps 1.5 title 'ln(n!)'\n"; 
              // the above line takes log of n! (second column)
        gp.send1d(lngamma_curve);
}

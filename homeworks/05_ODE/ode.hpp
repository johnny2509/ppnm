#pragma once
#include<functional>
#include<tuple>
#include<vector>
#include<cmath>
#include<algorithm>
#include"matrix.hpp"

namespace pp {

// Task A, 1.

std::tuple<vector,vector> rkstep12(
	std::function<vector(double, vector)> f, // the f from dy/dx=f(x,y) 
	double x,                                // the current value of the variable 
	vector y,                                // the current value y(x) of the sought function 
	double h                                 // the step to be taken 
){
	vector k0 = f(x,y);                      // embedded lower order formula (Euler) 
	vector k1 = f(x+h/2,y+k0*(h/2));         // higher order formula (midpoint) 

	vector yh = y+k1*h;                      // y(x+h) estimate 
	vector dy = (k1-k0)*h;                   // error estimate 

	return {yh, dy}; // Chat GPT Instant 5.3
}

// Task A, 2.

std::tuple<std::vector<double>, std::vector<vector>> driver(

	std::function<vector(double, vector)> f, // Chat GPT Instant 5.3
	double a, 
	double b,                                // initial-point,final-point 
	vector yinit,                            // y(initial-point) 
	double h=0.125,                          // initial step-size 
	double acc=0.01,                         // absolute accuracy goal 
	double eps=0.01,                         // relative accuracy goal 
	double hmax=0.1                          // Chat GPT Instant 5.3
){
	double x=a; 
	vector y(yinit);

	std::vector<double> xlist = {x}; // Chat GPT Instant 5.3
	std::vector<vector> ylist = {y}; // Chat GPT Instant 5.3
	
	while(x < b){ // Chat GPT Instant 5.3

		if(x+h > b) h = b-x;                  // last step should end at b 
		auto [yh, dy] = rkstep12(f, x, y, h); // Chat GPT Instant 5.3
	
		double tol = (acc + eps * yh.norm()) * std::sqrt(h / (b-a));
		double err = dy.norm();
	
		if(err <= tol){ // accept step
			x+=h; 
			y=yh;
			xlist.push_back(x);
			ylist.push_back(y);
		}

		if(err > 0) 
			h *= std::min(std::pow(tol/err, 0.25) * 0.95, 2.0); // Chat GPT Instant 5.3
		else 
			h*=2;
		h = std::min(h, hmax); // Chat GPT Instant 5.3
	}
	return {xlist, ylist};
}

}

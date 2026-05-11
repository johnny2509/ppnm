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
	std::function<vector(double,vector)> f, /* the f from dy/dx=f(x,y) */
	double x,                    /* the current value of the variable */
	vector y,                    /* the current value y(x) of the sought function */
	double h                     /* the step to be taken */
){
	vector k0 = f(x,y);              /* embedded lower order formula (Euler) */
	vector k1 = f(x+h/2,y+k0*(h/2)); /* higher order formula (midpoint) */

	vector yh = y+k1*h;              /* y(x+h) estimate */
	vector δy = (k1-k0)*h;           /* error estimate */

	return {yh, δy}; // Chat GPT Instant 5.3
}

// Task A, 2.

std::tuple<std::vector<double>, std::vector<vector>) driver(

	std::function<vector(vector,double)> F,/* the f from dy/dx=f(x,y) */
	double a, 
	double b,           /* initial-point,final-point */
	vector yinit,                /* y(initial-point) */
	double h=0.125,              /* initial step-size */
	double acc=0.01,             /* absolute accuracy goal */
	double eps=0.01              /* relative accuracy goal */
){
	double x=a; 
	vector y(yinit);

	std::vector<double> xlist = {x}; // Chat GPT Instant 5.3
	std::vector<vector> ylist = {y}; // Chat GPT Instant 5.3
	
	while(x<b){ // Chat GPT Instant 5.3

		if(x+h>b) h=b-x;               /* last step should end at b */
		auto [yh,δy] = rkstep12(F,x,y,h);
	
		double tol = (acc+eps*yh.norm()) * std::sqrt(h/(b-a));
		double err = δy.norm();
	
		if(err<=tol){ // accept step
			x+=h; 
			y=yh;
			xlist.push_back(x);
			ylist.push_back(y);
		}

		if(err>0) 
			h *= std::min( std::pow(tol/err,0.25)*0.95 , 2); // readjust stepsize
		else 
			h*=2;
	}
	return {xlist, ylist};
}//driver

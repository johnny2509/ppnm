#pragma once
#include <cmath>
#include <limits>

// This block of code was realized with Chat GPT Instant 5.3

namespace pp {

template<typename F>
double integrate(
	F f,
	double a,
	double b,
	double acc=1e-3,
	double eps=1e-3,
	double f2=std::numeric_limits<double>::quiet_NaN(),
	double f3=std::numeric_limits<double>::quiet_NaN()
){
	double h = b-a;

	if(std::isnan(f2)){ // first call, no points to reuse
		f2=f(a+2*h/6);
		f3=f(a+4*h/6);
	}

	double f1=f(a+h/6); 
	double f4=f(a+5*h/6);

	double Q = (2*f1+f2+f3+2*f4)/6*h; // higher order rule
	double q = (  f1+f2+f3+  f4)/4*h; // lower order rule

	double err = std::abs(Q-q); 
	double tol = acc+eps*abs(Q);
 
	if(err < tol){ 
		return Q;
	}
	else{
		double mid = (a+b)/2;
		return integrate(f, a, mid, acc/std::sqrt(2.0), eps, f1, f2)
		+ integrate(f, mid, b, acc/std::sqrt(2.0), eps, f3, f4);
	}
}

inline double erf_integral(double z, double acc=1e-6, double eps=1e-6){
	const double pi = std::acos(-1.0);
	if(z<0){ 
		return -erf_integral(-z, acc, eps);
	}
	if(z<=1){
		auto f = [](double x){
			return std::exp(-x*x);
		};
		return 2/std::sqrt(pi) * integrate(f, 0.0, z, acc, eps);
	}
	auto f = [z](double t){
		double u = z+(1-t)/t;
		return std::exp(-u*u)/(t*t);
	};	
	return 1 - 2/std::sqrt(pi)*integrate(f, 0.0, 1.0, acc, eps);
}
}



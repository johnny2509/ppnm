// parts of the code are reused from the 06_Quad homework

#pragma once
#include <cmath>

namespace pp {

// Recursive adapter function 

template<typename F>
double adapt(
    F f,
    double a,
    double b,
    double acc,
    double eps,
    double f1,
    double f2,
    double f3,
    double f4
){
    double h = b-a;
    
    double Q_est = h * (11.0*f1 + f2 + f3 + 11.0*f4)/24.0;

    double m = (a+b)/2.0; 

    // The left child receives parent values f1, f2, which become fl2, fl4 (must compute fl1, fl3)
    double fl1 = f(a + (m-a)/5.0); // new, [a, m]
    double fl2 = f1; // reused
    double fl3 = f(a + 3*(m-a)/5.0); // new, [a, m]
    double fl4 = f2; // reused

    // The right child receives parent values f3, f4 which become fr1, fr3 (must compute fr2, fr4)
    double fr1 = f3; // reused
    double fr2 = f(m + 2.0*(b-m)/5.0); // new, [m, b]
    double fr3 = f4; // reused
    double fr4 = f(m + 4.0*(b-m)/5.0); //new, [m, b]

    double h_l = m-a;
    double Q_l = h_l * (11.0*fl1 + fl2 + fl3 + 11.0*fl4)/24.0;

    double h_r = b-m;
    double Q_r = h_r * (11.0*fr1 + fr2 + fr3 + 11.0*fr4)/24.0;

    double Q = Q_l + Q_r; 

    double err = std::abs(Q - Q_est)/15.0;

    if(err < acc + eps*std::abs(Q)){
        return Q + (Q - Q_est)/15.0;
    }

    else{
        return adapt(f, a, m, acc/std::sqrt(2.0), eps, fl1, fl2, fl3, fl4) 
        + adapt(f, m, b, acc/std::sqrt(2.0), eps, fr1, fr2, fr3, fr4);
    }

}

// We define an integration function

template<typename F>
double integrate(
    F f,
    double a,
    double b,
    double acc=1e-3,
    double eps=1e-3
){
    double h = b-a;

    double f1 = f(a + 1.0/5.0*h);
    double f2 = f(a + 2.0/5.0*h);
    double f3 = f(a + 3.0/5.0*h);
    double f4 = f(a + 4.0/5.0*h);

    return adapt(f, a, b, acc, eps, f1, f2, f3, f4);

}

// Added from the 06_Quad homework

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
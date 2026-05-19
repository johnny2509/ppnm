#include <iostream>
#include <iomanip>
#include <cmath>
#include "quadinteg.hpp"

// This block of code was realized with Chat GPT Instant 5.3

int main(){
	std::cout << std::setprecision(15);

	double acc=1e-4;
	double eps=1e-4;
	
	// Calculate some integrals with integrable divergencies at 
	// the end-points of the intervals; record the number of 
	// integrand evaluations; compare with your ordinary integrator 
	// without variable transformation.

	// Integral: 1/sqrt(x) [0, 1]

	int calls_normal = 0; // number of integrand evaluations with technique from task A
	auto f1_normal = [&](double x){
		calls_normal++;
		return 1.0/std::sqrt(x);
	};

	int calls_clenshaw_curtis = 0; // number of integrand evaluations from Clenshaw-Curtis
	auto f1_CC = [&](double x){
		calls_clenshaw_curtis++;
		return 1.0/std::sqrt(x);
	};

	double normal_1 = pp::integrate(f1_normal, 0.0, 1.0, acc, eps);
	double cc_1 = pp::clenshaw_curtis(f1_CC, 0.0, 1.0, acc, eps);

	std::cout << "Integral 1/sqrt(x), exact = 2\n";
	std::cout << "normal result = " << normal_1 << ", calls = " << calls_normal << "\n";
	std::cout << "Clenshaw-Curtis result = " << cc_1 << ", calls = " << calls_clenshaw_curtis << "\n\n";

	// Integral: ln(x)/sqrt(x) [0, 1]

	calls_normal = 0; // number of integrand evaluations with technique from task A
        auto f2_normal = [&](double x){
                calls_normal++;
                return std::log(x)/std::sqrt(x); 
        };
        
        calls_clenshaw_curtis = 0; // number of integrand evaluations from Clenshaw-Curtis
        auto f2_CC = [&](double x){
                calls_clenshaw_curtis++;
                return std::log(x)/std::sqrt(x);
        };
        
        double normal_2 = pp::integrate(f2_normal, 0.0, 1.0, acc, eps);
        double cc_2 = pp::clenshaw_curtis(f2_CC, 0.0, 1.0, acc, eps);
        
        std::cout << "Integral ln(x)/sqrt(x), exact = -4\n";
        std::cout << "normal result = " << normal_2 << ", calls = " << calls_normal << "\n";
        std::cout << "Clenshaw-Curtis result = " << cc_2 << ", calls = " << calls_clenshaw_curtis << "\n\n";

	// test the infinite limit implementation with  e^(-x^2) on [-inf, inf]

	int calls = 0;
	auto gaussian = [&](double x){
		calls++;
		return std::exp(-x*x);
	};

	double res = pp::intinf(
		gaussian,
		-std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(),
		1e-6,
		1e-6
	);

	std::cout << "Integral exp(-x*x) from -inf to inf\n";
	std::cout << "result = " << res << "\n";
	std::cout << "exact = " << std::sqrt(std::acos(-1.0)) << "\n";
	std::cout << "calls = " << calls << "\n";


	// test the infinite limit implementation with 
	// setting the integral of 1/(1+x^2) equal to pi on [-inf, inf]

	calls = 0;

	auto cauchy = [&](double x){
		calls++;
		return 1.0/(1+x*x);
	};

	double pi = std::acos(-1.0);

	double res2 = pp::intinf(
		cauchy,
		-std::numeric_limits<double>::infinity(),
                std::numeric_limits<double>::infinity(),
                1e-6,
                1e-6
        );

	std::cout << "\nIntegral 1/(1+x*x) from -inf to inf\n";
        std::cout << "result = " << res2 << "\n";
        std::cout << "exact = " << pi << "\n";
        std::cout << "calls = " << calls << "\n";


	return 0;

}

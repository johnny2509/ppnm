#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <functional>
#include "quadinteg.hpp"

// This block of code was realized with Chat GPT Instant 5.3

int main(){
	std::cout << std::setprecision(15);

	double acc=1e-6;
	double eps=1e-6;

	auto test = [&](std::string name,
			std::function<double(double)> f,
			double exact){
		double result = pp::integrate(f, 0,1, acc, eps);
		double diff = std::abs(result-exact);

		std::cout << name << "\n";
		std::cout << "result = " << result << "\n";
		std::cout << "exact  = " << exact << "\n";
		std::cout << "diff   = " << diff << "\n\n";
	};

	test("Integral sqrt(x)",
		[](double x){ return std::sqrt(x); },
		2.0/3.0);

	test("Integral 1/sqrt(x)",
		[](double x){ return 1.0/std::sqrt(x); },
		2.0);

	test("Integral sqrt(1-x^2)",
		[](double x){ return std::sqrt(1-x*x); },
		M_PI/4.0);

	test("Integral log(x)/sqrt(x)",
		[](double x){ return std::log(x)/std::sqrt(x); },
		-4.0);

	double exact_erf1 = 0.84270079294971486934;
	double my_erf1 = pp::erf_integral(1.0, 1e-6, 0);

	std::cout << "erf(1)\n";
	std::cout << "result = " << my_erf1 << "\n";
	std::cout << "exact  = " << exact_erf1 << "\n";
	std::cout << "diff   = " << std::abs(my_erf1-exact_erf1) << "\n\n";

	std::cout << "# acc abs_error\n";
	for(double a=1e-1; a>=1e-8; a/=10){
		double val = pp::erf_integral(1.0, a, 0);
		double err = std::abs(val-exact_erf1);
		std::cout << a << " " << err << "\n";
	}

	std::cout << "\nComparison with tabulated values:\n";
	std::cout << "z\tcomputed\t\tknown\n";

	double zvals[] = {0.0, 0.5, 1.0, 1.5, 2.0};

	for(double z : zvals){
		double computed = pp::erf_integral(z, 1e-6, 1e-6);
		double known = std::erf(z);
		std::cout << z << "\t"
			  << computed << "\t"
			  << known << "\n";
	}
	std::ofstream out("erf_acc.dat");

	for(double a=1e-1; a >= 1e-8; a/=10){
		double val = pp::erf_integral(1.0, a, 0);
		double err = std::abs(val-exact_erf1);

		out << a << " " << err << "\n";
	}
	out.close();

	std::ofstream erfplot("erf_plot.dat");
	for(double z=-3.0; z<=3.0; z+=0.05){
		erfplot << z << " " << pp::erf_integral(z, 1e-6, 1e-6) << "\n";
	}
	erfplot.close();	

	return 0;
} 

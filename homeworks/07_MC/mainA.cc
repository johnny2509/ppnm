#include <iostream>
#include <cmath>
#include <fstream>
#include "matrix.hpp"
#include "monte.hpp"

int main(){
	pp::LCG rng(12345);

	// Task A, 3: Area of a unit circle

	auto circle = [](const pp::vector& x){
		double r2 = x[0] * x[0] + x[1] * x[1];
		return r2 <= 1.0 ? 1.0 : 0.0;
	};

	pp::vector a2 = {-1.0, -1.0};
	pp::vector b2 = {1.0, 1.0};
	const double pi = 3.14159265359;

	std::cout << "# N result estimated_error actual_error\n";

	for(int N = 100; N <= 10000000; N *= 2){
		auto [res, err] = pp::plainmc(circle, a2, b2, N, rng);
		double actual_error = std::abs(res - pi);

		std::cout << N << " "
			  << res << " "
			  << err << " "
			  << actual_error << "\n";
	}

	// Task A, 4: Volume of a 3D ellipoid, semi-axes: a=1, b=2, c=3

	auto ellipsoid = [](const pp::vector& x){
		double a = 1.0;
		double b = 2.0;
		double c = 3.0;

		// ellipsoid eq: x^2/a^2+y^2/b^2+z^2/c^2 <= 1
		double val = x[0]*x[0]/(a*a) + x[1]*x[1]/(b*b) + x[2]*x[2]/(c*c);

		return val <= 1.0 ? 1.0 : 0.0;
	};

	pp::vector a3 = {-1.0, -2.0, -3.0};
	pp::vector b3 = {1.0, 2.0, 3.0};

	int N = 10000000;

	auto [V, err] = pp::plainmc(ellipsoid, a3, b3, N, rng);

	double exact = 4.0/3.0 * pi * 1.0 * 2.0 * 3.0;

	std::ofstream ellipsoidfile("ellipsoid.data");

	ellipsoidfile << "Monte Carlo volume = " << V << "\n";
	ellipsoidfile << "estimated error    = " << err << "\n";
	ellipsoidfile << "exact volume       = " << exact << "\n";
	ellipsoidfile << "actual error       = " << std::abs(V-exact) << "\n";

	ellipsoidfile.close();

	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <functional>
#include "lsfit.hpp"

int main() {
	std::ifstream in("thx.dat");
	if(!in){
		std::cerr << "Error: could not open thx.dat\n";
		return 1;
	}

	std::vector<double> ts, ys, dys_raw;
	double t, y, dy;

	while(in >> t >> y >> dy){
		ts.push_back(t);
		ys.push_back(y);
		dys_raw.push_back(dy);
	}

	int n = ts.size();
	pp::vector x(n), logy(n), dlogy(n);

	for(int i = 0; i < n; i++){
		x[i] = ts[i];
		logy[i] = std::log(ys[i]);
		dlogy[i] = dys_raw[i] / ys[i];
	}
	
	std::vector<std::function<double(double)>> fs{ // The hint from Dmitri
		[](double){ return 1.0; },
		[](double z){ return z; }
	};

	pp::vector c = pp::lsfit(fs, x, logy, dlogy);

	double c0 = c[0];
	double c1 = c[1];
	double a = std::exp(c0);
	double lambda = -c1;
	double T12 = std::log(2.0) / lambda;

	std::cout << "Fit to ln(y) = c0 + c1*t\n";
	std::cout << "c0 = " << c0 << "\n";
	std::cout << "c1 = " << c1 << "\n";
	std::cout << "a = exp(c0) = " << a << "\n";
	std::cout << "lambda = -c1 = " << lambda << " 1/day\n";
	std::cout << "Half-life T1/2 = ln(2)/lambda = " << T12 << " days\n";

	std::cout << "The half-life for 224Ra is today known to be approximately 3.632 days, which roughly matches the found half-life of ThX.\n";
	std::cout << "Note: When Y=ln(y) the standard error propagation deltaY ~ |dY/dy|deltay,\n";
	std::cout << "then we have that d/dy ln(y)=1/y, thus delta(ln(y)) ~ deltay/y.\n";	

	std::ofstream logout("thx_log.dat");
	for(int i = 0; i < n; i++){
		logout << x[i] << " " << logy[i] << " " << dlogy[i] << "\n";
	}

	std::ofstream fitout("thx_fit.dat");
	for(int i = 0; i < n; i++){
		double yfit = a * std::exp(-lambda * x[i]);
		fitout << x[i] << " " << ys[i] << " " << dys_raw[i] << " " << yfit << "\n";
	}

	return 0;
}


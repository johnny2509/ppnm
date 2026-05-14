#include <iostream>
#include <cmath>
#include "ode.hpp"

int main(){
	auto f = [](double x, pp::vector y){
		pp::vector dydx(2);
		dydx[0] = y[1];
		dydx[1] = -y[0];
		return dydx;
	};

	pp::vector yinit = {0, 1};

	auto [xs, ys] = pp::driver(f, 0, 10, yinit, 0.1, 1e-4, 1e-4);

	for(size_t i = 0; i < xs.size(); i++){
		double x = xs[i];
		std::cout << x << " " << ys[i][0] << " " << std::sin(x) << "\n";
	}
}

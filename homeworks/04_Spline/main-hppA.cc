#include <iostream>
#include <cmath>
#include "linear.hpp"

// Task A, 3.
// Chat GPT Instant 5.3

int main(){
	vector x(19), y(19);

	for(int i = 0; i < x.size(); i++){
		x[i] = 0.5*i;
		y[i] = std::cos(x[i]);
	}

	for(double z = x[0]; z <= x[x.size()-1]; z += 0.05){
		std::cout << z << " " << std::cos(z) << " " << linterp(x, y, z) << " " << linterpInteg(x, y, z) << "\n";
	}
}

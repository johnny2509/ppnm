#include <iostream>
#include <fstream>
#include <cmath>
#include "linear.hpp"

// Task A, 3.
// Chat GPT Instant 5.3

int main(){
	int n = 19;
	vector x(n), y(n);

	for(int i = 0; i < n; i++){
		x[i] = 0.5*i;
		y[i] = std::cos(x[i]);
	}

	std::ofstream data("outA.txt");
	std::ofstream points("pointsA.txt");

	for(int i=0; i<n; i++){
		points << x[i] << " " << y[i] << "\n";
	}

	int N = 500;
	for(int k=0; k<=N; k++){
		double z = x[0] + (x[n-1] - x[0])*k/N;

		data << z << " " 
			 << std::cos(z) << " "
			 << linterp(x, y, z) << " "
			 << std::sin(z) << " "
			 << linterpInteg(x, y, z) << "\n";
	}
	return 0;
}

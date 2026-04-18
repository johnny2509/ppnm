#include<iostream>
#include<string>
#include<cstdlib>
#include<tuple>
#include"matrix.hpp"
#include"eigen.hpp"

// Task B. Build and diagonalize H 
// This block of code was realized by Chat GPT Instant 5.3

int main(int argc, char** argv){
	double rmax = 20.0;
	double dr = 0.1;

	for(int i = 1; i < argc; i++){
		std::string arg = argv[i];
		if(arg == "-rmax" && i + 1 < argc) rmax = std::atof(argv[++i]);
		else if(arg == "-dr" && i + 1 < argc) dr = std::atof(argv[++i]);
	}

	int npoints = (int)(rmax / dr) - 1;

	pp::vector r(npoints);
	for(int i = 0; i < npoints; i++) r[i] = dr*(i + 1);

	pp::matrix H(npoints, npoints);
	
	for(int i = 0; i < npoints - 1; i++){
   		H(i, i)  = -2 * (-0.5 / dr /dr); // Chat GPT Instant 5.3
   		H(i, i + 1) = 1 * (-0.5 / dr / dr); // Chat GPT Instant 5.3
   		H(i + 1, i) = 1 * (-0.5 / dr / dr); // Chat GPT Instant 5.3
	}

	H(npoints - 1, npoints - 1) = -2 * (-0.5 / dr / dr);
	
	for(int i = 0; i < npoints; i++) H(i, i) += -1.0 / r[i];

	auto [e, V] = pp::jacobi(H); // e: eigenvalues, V: eigenvectors

	std::cout << "eigenvalues:\n";
	for(int i = 0; i < e.size(); i++){
		std::cout << i << " " << e[i] << "\n";
	}

	return 0;
}

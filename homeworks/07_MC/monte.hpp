#pragma once
#include <cmath>
#include <utility>
#include "matrix.hpp" // reused from the QR homework

// Task A, 1: Monte Carlo multi-dimensional integrator

namespace pp {

struct LCG { // unsigned long was Chat GPT Instant 5.3's idea
	unsigned long seed;
	unsigned long a = 1664525;
	unsigned long c = 1013904223;
	unsigned long m = 4294967296;

	LCG(unsigned long seed_) : seed(seed_) {}

	double operator()(){
		seed = (a*seed+c) % m;
		return double(seed+1)/double(m+1);
	}
};

template<typename F, typename RNG> // RNG was Chat GPT Instant 5.3's idea
std::pair<double, double> plainmc(
	F f,
	const pp::vector& a,
	const pp::vector& b,
	int N,
	RNG& random_double
){
	int dim = a.size();

	double V = 1.0;

	for(int i = 0; i < dim; i++){
		V *= (b[i] - a[i]);
	}

	double sum1 = 0.0;
	double sum2 = 0.0;

	for(int j = 0; j < N; j++){

		pp::vector x(dim);

		for(int i = 0; i < dim; i++){
			x[i] = a[i] + random_double() * (b[i] - a[i]);
		}
		
		double fx = f(x);
		sum1 += fx;
		sum2 += fx * fx;
	}

	double mean = sum1 / N;
	double sigma = std::sqrt(sum2 / N - mean*mean);

	double res = mean*V;
	double err = sigma*V/std::sqrt(N);

	return {res, err};			

}

// Task B, 1: Monte Carlo integrator using the Halton sequence 

inline double corput(int n, int base){
	double q = 0.0;
	double bk = 1.0/base;

	while(n > 


}

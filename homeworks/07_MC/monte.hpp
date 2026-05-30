#pragma once
#include <cmath>
#include <utility>
#include <array>
#include <random>
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

	while(n > 0){
		q += (n%base)*bk;
		n /= base;
		bk /= base;
	}

	return q; 
}

inline pp::vector halton(int n, int dim, int shift = 0){
	static const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

	pp::vector x(dim);

	for(int i = 0; i<dim; i++){
		x[i] = corput(n+shift, primes[i]);
	}

	return x;
}

template<typename F>
double quasimc(
	F f,
	const pp::vector& a,
	const pp::vector& b,
	int N,
	int shift = 0
){
	int dim = a.size();

	double V = 1.0;
	for(int i = 0; i<dim; i++){
		V *= b[i]-a[i];
	}

	double sum = 0.0;

	for(int n = 0; n<N; n++){
		pp::vector u = halton(n+1, dim, shift);
		pp::vector x(dim);

		for(int i = 0; i<dim; i++){
			x[i]=a[i]+u[i]*(b[i]-a[i]);
		}

		sum += f(x);
	}

	return V*sum/N;

}

template<typename F>
std::pair<double, double> quasimc_error(
        F f,
        const pp::vector& a,
        const pp::vector& b, 
        int N
){

	double result1 = quasimc(f,a,b,N,0);
	double result2 = quasimc(f,a,b,N,1000000);

	double result = 0.5*(result1+result2);
	double error = std::abs(result1-result2);

	return {result, error};
}

} //pp

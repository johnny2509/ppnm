#pragma once
#include <cassert>
#include "matrix.hpp"

using vector = pp::vector; // Chat GPT Instant 5.3

// Task A, 1.

int binsearch(const vector& x, double z){
	assert(x.size() >= 2); // Chat GPT Instant 5.3
	assert(z >= x[0] && z <= x[x.size()-1]);
	int i = 0, j = x.size()-1;
	while(j-i > 1){
		int mid = (i+j)/2;
		if(z > x[mid]) i = mid; else j = mid;
	}
	return i;
}

double linterp(const vector& x, const vector& y, double z){ // Chat GPT Instant 5.3
	assert(x.size() == y.size()); // Chat GPT Instant 5.3
	int i = binsearch(x, z);

	double dx = x[i+1] - x[i];
	assert(dx > 0);

	double dy = y[i+1] - y[i];
	return y[i] + dy / dx * (z - x[i]);
}

// Task A, 2.
// The following function was realized by Chat GPT Instant 5.3

double linterpInteg(const vector& x, const vector& y, double z){
	assert(x.size() == y.size());
	int iz = binsearch(x, z);

	double sum = 0;

	for(int i = 0; i < iz; i++){
		double h = x[i+1] - x[i];
		assert(h > 0);
		double slope = (y[i+1] - y[i]) / h;
		sum += y[i] * h + 0.5 * slope * h * h;
	}

	double dz = z - x[iz];
	double h = x[iz+1] - x[iz];
	double slope = (y[iz+1] - y[iz])/h;
	sum += y[iz] * dz + 0.5 * slope * dz * dz;

	return sum;
}

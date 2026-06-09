#pragma once
#include "matrix.hpp" // reuse of the matrix class from the 01_QR homework
#include <functional>
#include <cmath>
#include <algorithm>

// This block of code was realized with Chat GPT Instant 5.3

namespace pp {

using vecfunc = std::function<vector(const vector&)>;

inline matrix jacobian(
	const vecfunc& f,
	const vector& x,
	const vector& fx,
	const vector* user_dx = nullptr
){
	int n = x.size();
	matrix J(n,n);

	vector dx(n);
	if(user_dx){
		dx = *user_dx; // delta x if the user supplies it
	} else { // when delta x is not supplied --> delta x_i=max(|x_i|, 1)*2^(-26)
		for(int i=0; i<n; i++)
			dx[i] = std::max(std::abs(x[i]), 1.0) * std::pow(2, -26);
	}

	for(int j=0; j<n; j++){
		vector x_step = x;
		x_step[j] += dx[j];

		vector df = f(x_step)-fx;

		for(int i=0; i<n; i++)
			J(i,j) = df[i]/dx[j];
	}

	return J;
}

inline vector newton(
	const vecfunc& f,
	vector x,
	double acc = 1e-6,
	double alpha_min = 1e-3,
	int max_iter = 100,
	const vector* user_dx = nullptr
){
	vector fx = f(x);

	for(int iter=0; iter<max_iter; iter++){
		if(fx.norm() < acc) break;

		matrix J = jacobian(f,x,fx,user_dx);
		qr QRJ(J);
		
		vector Dx = QRJ.solve(-fx);

		vector dx_for_stop(x.size());
		if(user_dx){
			dx_for_stop = *user_dx;
		} else {
			for(int i=0; i<x.size(); i++)
				dx_for_stop[i] = std::max(std::abs(x[i]), 1.0) * std::pow(2, -26);
		}

		// if(Dx.norm() < dx_for_stop.norm()) break;

		double alpha = 1.0;
		vector z;
		vector fz;

		while(true){
			z = x+alpha*Dx;
			fz = f(z);

			if(fz.norm() < fx.norm()) break;
			if(alpha < alpha_min) break;

			alpha /= 2;
		}

		x = z;
		fx = fz;
	}
		
	return x;

}

} // namespace pp

	

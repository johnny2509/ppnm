#pragma once
#include<cmath>  
#include<tuple>
#include<cassert>
#include"matrix.hpp" // Reuse of the vector and matrix class from homework "Linear Equations"

namespace pp{ // Chat GPT Instant 5.3

// Task A, 1. Function that multiplies a given A matrix with Jacobi J(p,q,theta)
// from the right A <-- A * J

inline void timesJ(matrix& A, int p, int q, double theta){ // Chat GPT Instant 5.3
        double c = std::cos(theta), s = std::sin(theta);
        for(int i = 0; i < A.size1(); i++){
                double aip = A(i, p), aiq = A(i, q);
                A(i, p) = c * aip - s * aiq;
                A(i, q) = s * aip + c * aiq;
        }
}

// Task A, 2. Function that multiplies a given A matrix with Jacobi J(p,q,theta)
// from the left A <-- J * A

inline void Jtimes(matrix& A, int p, int q, double theta){ // Chat GPT Instant 5.3
        double c = std::cos(theta), s = std::sin(theta);
        for(int j = 0; j < A.size2(); j++){ // Chat GPT Instant 5.3
                double apj = A(p, j), aqj = A(q, j);
                A(p, j) = c * apj + s * aqj; 
                A(q, j) = -s * apj + c * aqj;
        }
}

inline std::tuple<vector, matrix> jacobi(matrix A){ // Chat GPT Instant 5.3 
	int n = A.size1();
	assert(n == A.size2()); // Chat GPT Instant 5.3	

	matrix V(n, n); 
	V.setid(); 
	vector w(n);

	// Task A, 3. Function for the Jacobi eigenvalue algorithm for real symmetric matrices

	bool changed;
	do{
		changed = false;
		for(int p = 0; p < n - 1; p++){
			for(int q = p + 1; q < n; q++){
				double apq = A(p,q), app = A(p, p), aqq = A(q, q);
				double theta = 0.5 * std::atan2(2 * apq, aqq - app);
				double c = std::cos(theta), s = std::sin(theta);

				double new_app = c*c * app - 2*s*c * apq + s*s * aqq;
				double new_aqq = s*s * app + 2*s*c * apq + c*c * aqq;

				if(new_app != app || new_aqq != aqq){ // do rotation
					changed = true;
					timesJ(A, p, q, theta); // A←A*J 
					Jtimes(A, p, q, -theta); // A←JT*A 
					timesJ(V, p, q, theta); // V←V*J
				}
			}
		}
	}while(changed);

	for(int i = 0; i < n; i++) w[i] = A(i, i); // Chat GPT Instant 5.3

	return std::make_tuple(w, V);
} //jacobi

}//pp

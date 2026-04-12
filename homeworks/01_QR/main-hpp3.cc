#include"matrix.hpp"
#include <cstdlib>
#include <ctime>

// main file for Task A, 3.
// realized with the help of Chat GPT Instant 5.3

pp::matrix random_matrix(int n, int m){
	pp::matrix A(n, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			A(i, j) = 2.0*rand()/double(RAND_MAX) - 1.0;
		}
	}
	return A;
}

pp::vector random_vector(int n){
	pp::vector v(n);
	for(int i = 0; i < n; i++){
		v[i] = 2.0*rand()/double(RAND_MAX) - 1.0;
	}
	return v;
}

int main(){
	srand(time(nullptr));

	int n = 6;
	pp::matrix A = random_matrix(n, n);
	pp::vector b = random_vector(n);

	pp::qr decomp(A);
	pp::vector x = decomp.solve(b);
	pp::vector Ax = A * x;

	A.print("A =");
	b.print("b =");
	x.print("x =");
	Ax.print("A*x =");

	std::cout << "Ax = b? " << (pp::approx(Ax, b) ? "yes" : "no") << "\n";

	return 0;
} 

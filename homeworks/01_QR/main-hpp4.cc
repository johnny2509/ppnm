#include"matrix.hpp"
#include <cstdlib>
#include <ctime>

pp::matrix random_matrix(int n, int m){
	pp::matrix A(n, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			A(i, j) = 2.0*rand()/double(RAND_MAX) - 1.0;
		}
	}
	return A;
}

int main(){
	srand(time(nullptr));

	// int n = 5;

	// pp::matrix A = random_matrix(n, n);
	pp::matrix A(3,3);
	A(0,0)=1; A(0,1)=0; A(0,2)=0;
	A(1,0)=0; A(1,1)=2; A(1,2)=0;
	A(2,0)=1; A(2,1)=0; A(2,2)=3;
	
	pp::qr decomp(A);

	pp::matrix Q = decomp.Q;
	pp::matrix R = decomp.R;

	A.print("A =");
	Q.print("Q =");
	R.print("R =");

	double detA = decomp.det();

	std::cout << "det(A) ~ det(R) = " << detA << "\n";

	return 0;
}

#include"matrix.hpp"
#include <cstdlib>
#include <ctime>

pp::matrix eye(int n){
	pp::matrix M(n,n);
	for(int i=0;i<n;i++)M(i,i)=1; //Chat GPT Instant 5.3
	return M;
}

bool test_triangular(const pp::matrix& R, double tol=1e-10){
	for(int i = 0; i < R.size1(); i++){
		for(int j = 0; j < i && j < R.size2(); j++){
			if(std::abs(R(i, j)) > tol) return false;
		}
	}
	return true;
}

bool approx(const pp::matrix& A, const pp::matrix& B, double acc=1e-6, double eps=1e-6){
	if(A.size1() != B.size1() || A.size2() != B.size2()) return false;
	for(int i = 0; i < A.size1(); i++){
		for(int j = 0; j < A.size2(); j++){
			if(!pp::approx(A(i, j), B(i, j), acc, eps)) return false;
		}
	}
	return true;
}

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

	int n = 5;
	int m = 3;

	pp::matrix A = random_matrix(n, m);
	pp::qr decomp(A);

	pp::matrix Q = decomp.Q;
	pp::matrix R = decomp.R;

	A.print("A =");
	Q.print("Q =");
	R.print("R =");
	(Q.T()*Q).print("Q^T Q =");
	(Q*R).print("Q R =");

	std::cout << "R upper triangular? " << (test_triangular(R) ? "yes" : "no") << "\n";
	std::cout << "Q^T Q = I? " << (approx(Q.T()*Q, eye(m)) ? "yes" : "no") << "\n";
	std::cout << "Q R = A? " << (approx(Q*R, A) ? "yes" : "no") << "\n";

	return 0;
}


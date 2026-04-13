#include"matrix.hpp"
#include <cstdlib>
#include <ctime>
#include <cstring>

pp::matrix random_matrix(int n, int m){
	pp::matrix A(n, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			A(i, j) = 2.0*rand()/double(RAND_MAX) - 1.0;
		}
	}
	return A;
}

int main(int argc, char** argv){
	srand((unsigned)time(nullptr)); // "unsigned" to make the Makefile work and compatible with macOS

	int n = 100;

	for(int i = 1; i < argc; i++){
		if(std::strcmp(argv[i], "-size") == 0 && i + 1 < argc){
			n = std::atoi(argv[i+1]);
			i++;
		}
	}

	pp::matrix A = random_matrix(n, n);
	pp::qr decomp(A);

	return 0;
}

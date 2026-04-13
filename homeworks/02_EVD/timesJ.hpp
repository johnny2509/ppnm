

// Task A, 1. Function that multiplies a given A matrix with Jacobi J(p,q,theta)  
// from the right A <-- A * J

static void timesJ(pp::matrix& A, int p, int q, double theta){
	double c = std::cos(theta), s = std::sin(theta);
	for(int i = 0; i < A.size1(); i++){
		double aip = A[i,p], aiq = A[i,q];
		A[i,p] = c * aip - s * aiq;
		A[i,q] = s * aip + c * aiq;
		}
}

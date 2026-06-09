#pragma once
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<initializer_list>
#include<functional>
#include<ranges>

#define SELF (*this)
#define FOR(i,V) for(int i=0;i<V.size();i++)
#define FOR1(i,A) for(int i=0;i<A.size1();i++)
#define FOR2(j,A) for(int j=0;j<A.size2();j++)

namespace pp{

struct vector {
	std::vector<double> data;

	vector() = default;
	vector(int n) : data(n) {}
	vector(std::initializer_list<double> list) : data(list) {}
	vector(const vector&) = default;
	vector(vector&&) noexcept = default;
	vector& operator=(const vector&) = default;
	vector& operator=(vector&&) noexcept = default;

	int size() const {return data.size();}
	double& operator[](int i) {return data[i];}
	const double& operator[](int i) const {return data[i];}

	vector& operator+=(const vector& other){
		assert(size() == other.size());  //  Chat GPT Instant 5.3
		FOR(i,SELF) SELF[i]+=other[i];
		return SELF;
		}

	vector& operator-=(const vector& other){
		assert(size() == other.size());  // Chat GPT Instant 5.3
		FOR(i,SELF) SELF[i]-=other[i];
		return SELF;
		}

	vector& operator*=(double c){
		FOR(i,SELF) SELF[i]*=c;
		return SELF;
		}

	vector& operator/=(double c){
		FOR(i,SELF) SELF[i]/=c;
		return SELF;
		}

	double dot(const vector& other) const{  // Chat GPT Instant 5.3
		assert(size() == other.size());  // Chat GPT Instant 5.3
		double sum = 0;  // Chat GPT Instant 5.3
		FOR(i,SELF) sum += SELF[i] * other[i];  // Chat GPT Instant 5.3
		return sum;  // Chat GPT Instant 5.3
	}

	double norm() const {
		double sum2 = 0;  // Chat GPT Instant 5.3
		FOR(i, SELF) sum2 += SELF[i] * SELF[i]; // Chat GPT Instant 5.3
		return std::sqrt(sum2); // Chat GPT Instant 5.3
	}

	void print(std::string s="") const {
		std::cout<<s;
		for(auto &x : data) printf("%10.3g ",x);
		std::cout<<"\n";
	}

	vector map(std::function<double(double)> f) const{
		vector r(size());
		FOR(i,SELF) r.data[i]=f(data[i]);
		return r;
	}

}; // vector

inline vector operator+(vector a, const vector& b){ a+=b ; return a; }
inline vector operator-(vector a)                 { a*=-1; return a; }
inline vector operator-(vector a, const vector& b){ a-=b ; return a; }
inline vector operator*(vector a, double c) { a*=c ; return a; } // Chat GPT Instant 5.3
inline vector operator*(double c, vector a) { a*=c ; return a; } // Chat GPT Instant 5.3
inline vector operator/(vector a, double c) { a/=c ; return a; } // Chat GPT Instant 5.3

inline bool approx(double x, double y, double acc=1e-6, double eps=1e-6){
	if(std::abs(x-y) < acc) return true;
	if(std::abs(x-y) < eps*std::max(std::abs(x),std::abs(y))) return true;
	return false;
}

inline bool approx(const vector& a, const vector& b, double acc=1e-6, double eps=1e-6){
	if(a.size() != b.size()) return false;
	for(int i=0;i<a.size();i++)
		if(!approx(a[i],b[i],acc,eps)) return false;
	return true;
}

struct matrix {
	std::vector<pp::vector> cols;

	matrix()=default;
	matrix(int n,int m) : cols(m, pp::vector(n)) {}
	matrix(const matrix& other)=default;
	matrix(matrix&& other)=default;
	matrix& operator=(const matrix& other)=default;
	matrix& operator=(matrix&& other)=default;

	int size1() const {return cols.empty() ? 0 : cols[0].size(); }
	int size2() const {return cols.size();}

	double& operator()(int i, int j){return cols[j][i];} // Chat GPT Instant 5.3
	const double& operator()(int i, int j) const {return cols[j][i];} // Chat GPT Instant 5.3

	vector& operator[](int i){return cols[i];} // Chat GPT Instant 5.3
	const vector& operator[](int i) const {return cols[i];} // Chat GPT Instant 5.3

	void setid(){
		assert(size1()==size2());
		for(int i=0;i<size1();i++){
			for(int j = 0; j < size2(); j++){  // Chat GPT Instant 5.3
				SELF(i,j) = (i == j ? 1.0 : 0.0); // Chat GPT Instant 5.3
			}
		}
	}
	matrix transpose() const{
		matrix R(size2(),size1());
		FOR1(i,SELF)
		FOR2(j,SELF)
			R(j,i)=SELF(i,j); // Chat GPT Instant 5.3
		return R;
	}

	matrix T() const {return transpose();}
	
	double get (int i, int j) const {return cols[j][i];}
	void set(int i, int j, double value){cols[j][i] = value;}

	matrix& operator+=(const matrix& B){
		assert(size1() == B.size1() && size2() == B.size2()); // Chat GPT Instant 5.3
		for(int i=0;i<size2();i++) SELF[i]+=B[i];
		return *this;
	}
	matrix& operator-=(const matrix& B){
		assert(size1() == B.size1() && size2() == B.size2()); // Chat GPT Instant 5.3
		for(int i=0;i<size2();i++) SELF[i]-=B[i];
		return *this;
	}
	matrix& operator*=(double c){ // Chat GPT Instant 5.3
		for(int i=0;i<size2();i++) SELF[i]*=c;
		return *this;
	}
	matrix& operator/=(double c){ // Chat GPT Instant 5.3
		for(int i=0;i<size2();i++) SELF[i]/=c;
		return *this;
	}

	void print(std::string s="") const{
		printf("%s\n",s.c_str());
		for(int i=0;i<size1();i++){
			for(int j=0;j<size2();j++) printf("%10.3g ", SELF(i,j)); // Chat GPT Instant 5.3
			printf("\n");
		}
	}
};

inline matrix operator+(matrix A, const matrix& B){
	A += B; // Chat GPT Instant 5.3
	return A;
}

inline matrix operator-(matrix A, const matrix& B){
	A -= B; // Chat GPT Instant 5.3
	return A;
}

inline vector operator*(const matrix& A, const vector& v){
	assert(A.size2() == v.size()); // Chat GPT Instant 5.3
	vector r(A.size1());
	FOR2(j,A){
		double vj=v[j];
		FOR1(i,A) r[i]+=A(i,j)*vj; // Chat GPT Instant 5.3
	}
	return r;
}

inline matrix operator*(const matrix& A, const matrix& B){
	assert(A.size2()==B.size1()); // Chat GPT Instant 5.3
	matrix R(A.size1(),B.size2());
	FOR2(j,R) R[j]=A*B[j];
	return R;
}

inline matrix operator*(matrix A, double c){ // Chat GPT Instant 5.3
	for(auto &col : A.cols) col*=c;
	return A;
}

inline matrix operator*(double c, matrix A){ // Chat GPT Instant 5.3
	for(auto &col : A.cols) col*=c;
	return A;
}

inline matrix operator/(matrix A, double c){ // Chat GPT Instant 5.3
	for(auto &col : A.cols) col/=c;
	return A;
}

struct qr {
	matrix Q;
	matrix R;

	qr(const matrix& A){
		int n = A.size1();
		int m = A.size2();
		assert(n >= m);

		Q = A; // copy of A
		R = matrix(m, m);

		for(int i = 0; i < m; i++){
			double rii = Q[i].norm();
			assert(rii > 0); // checks for linearly dependent colums
			R(i, i) = rii;
			Q[i] /= rii; // normalization

			for(int j = i + 1; j < m; j++){
				double rij = Q[i].dot(Q[j]);
				R(i, j) = rij;
				Q[j] -= Q[i] * rij; // orthogonalization
			}
		}
	}

	vector solve(const vector& b) const{
		assert(Q.size1() == b.size());

		int m = R.size1();
		vector c = Q.T() * b;
		vector x(m);

		for(int i = m - 1; i >= 0; i--){
			double sum = c[i];
			for(int j = i + 1; j < m; j++){
				sum -= R(i, j) * x[j];
			}
			x[i] = sum / R(i, i);
		}
		return x;
	}

	double det() const{
		assert(R.size1() == R.size2());

		int m = R.size1();

		double prod = 1;

		for(int i = 0; i < m; i++){
			prod *= R(i, i);
		}
		return prod;
	}

	matrix inverse() const{
		assert(R.size1() == R.size2());

		int n = R.size1();
		matrix B(n, n);

		for(int i = 0; i < n; i++){
			vector e(n); // basis vector 
			e[i] = 1.0;
			B[i] = solve(e);
		}
		return B;
	}    

};
} // pp

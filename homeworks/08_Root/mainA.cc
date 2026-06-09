#include "matrix.hpp"
#include "newton.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

int main(){
	using namespace pp;

	std::cout.precision(15);

	// To debug the root-finding routine we use a 1D, and a 2D equations
	// 1D test: x^2 - 2 = 0
	vecfunc f1 = [](const vector& x){
		return vector{ x[0]*x[0] - 2 };
	};

	vector r1 = newton(f1, vector{1.0});

	std::cout << "root of x^2 - 2 = ";
	r1.print();
	std::cout << "sqrt(2) = " << std::sqrt(2) << "\n\n";

	// 2D test: x + y = 3, x - y = 1
	vecfunc f2 = [](const vector& x){
		return vector{
			x[0] + x[1] - 3,
			x[0] - x[1] - 1
		};
	};

	vector r2 = newton(f2, vector{0.0, 0.0});
	std::cout << "root of linear 2D system = ";
	r2.print();
	std::cout << "expected: x = 2, y = 1\n\n";

	// We use the routine to find extremum(s) of the Rosenbrock's valley function
	// We notice df/dx = - 2 + 2x - 400yx + 400x^3 = -2(1-x) - 400x(y-x^2)
	// and  also df/dy = 200y - 200x^2 = 200(y-x^2)

	vecfunc rosen_grad = [](const vector& v){
		double x = v[0];
		double y = v[1];
		return vector{
			-2*(1-x) - 400*x*(y-x*x),
			200*(y-x*x)
		};
	};
	
	// We initialize the routine and give the start guess of vec={0, 0}

	vector rr = newton(rosen_grad, vector{0.0, 0.0}, 1e-8);

	std::cout << "Rosenbrock minimum = ";
	rr.print();
	std::cout << "expected: x = 1, y = 1\n\n";

	// We apply the routine to the Himmelblau's function f(x,y)=(x^2+y-11)^2+(x+y^2-7)^2
	// where we have       df/dx = 4x^3 + 4xy - 42x + 2y^2 - 14
	// and correspondingly df/dy = 4y^3 + 2x^2 +4xy - 26y - 22

	vecfunc himmel_grad = [](const vector& v){
		double x = v[0];
		double y = v[1];

		return vector{
			4*x*x*x + 4*x*y - 42*x + 2*y*y - 14,
			4*y*y*y + 2*x*x + 4*x*y - 26*y - 22
		};
	};

	vector h1 = newton(himmel_grad, vector{ 3.0, 2.0}, 1e-8);
	vector h2 = newton(himmel_grad, vector{-3.0, 3.0}, 1e-8);
	vector h3 = newton(himmel_grad, vector{-4.0,-3.0}, 1e-8);
	vector h4 = newton(himmel_grad, vector{ 4.0,-2.0}, 1e-8);

	std::cout << "Himmelblau minimum 1 = ";
	h1.print();

	std::cout << "Himmelblau minimum 2 = ";
        h2.print();

	std::cout << "Himmelblau minimum 3 = ";
        h3.print();

	std::cout << "Himmelblau minimum 4 = ";
        h4.print();

	return 0;
}


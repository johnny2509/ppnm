#include<iostream>
#include<limits>
#include<cstdio>
#include<iomanip>
#include<cmath>

bool approx(double a, double b, double acc=1e-9, double eps=1e-9);

int main() {
	std::printf("%d. Machine epsilon\n", 1);

	float f = 1.0f; while((float) (1.0f + f) != 1.0f) {f /= 2.0f;} f*= 2.0f;
	double d = 1.0; while((double) (1.0 + d) != 1.0) {d /= 2.0;} d*=2.0;
	long double l = 1.0L; while((long double) (1.0L + l) != 1.0L) {l /= 2.0L;} l*=2.0L;

	std::printf("float eps=%g\n", f);
	std::printf("double eps=%g\n", d);
	std::printf("long double eps=%Lg\n", l);
	std::cout << std::numeric_limits<float>::epsilon() << "\n";
	std::cout << std::numeric_limits<double>::epsilon() << "\n";
	std::cout << std::numeric_limits<long double>::epsilon() << "\n";
	
	float x = std::pow(2.0f, -23); // Chat GPT Instant 5.3
	double y = std::pow(2.0, -52); // Chat GPT Instant 5.3

	std::printf("precision for single (float): %g\n ", x);
	std::printf("precision for double: %g\n", y);

	std::printf("%d. Non-commutativity af addition\n", 2);

	double epsilon = std::pow(2, -52);
	double tiny = epsilon / 2;
	double a = 1 + tiny + tiny;
	double b = tiny + tiny + 1;

	std::cout << "a==b ? " << (a==b ? "true":"false") << "\n";
	std::cout << "a>1 ? " << (a>1 ? "true":"false") << "\n";
	std::cout << "b>1 ? " << (b>1 ? "true":"false") << "\n";

	std::printf("Explanation: for 'a' firstly '1+tiny' is calculated which is still '1', and then again '1+tiny' is calculated which is still '1'. For 'b' 'tiny+tiny' is calculated which and gives 'epsilon'. Thus '1+tiny+tiny>1' \n");

	std::cout << std::fixed << std::setprecision(17);
	std::cout << "           tiny = " << tiny << "\n";
	std::cout << "1 + tiny + tiny = " << a << "\n";
	std::cout << "tiny + tiny + 1 = " << b << "\n";

	std::printf("%d. Comparing doubles: introduction\n", 3);

	std::printf("d%d is a sum of %d: %d.%d\n", 1, 8, 0, 1);
	std::printf("d%d is %d times %d.%d\n", 2, 8, 0, 1);	

	double d1 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
	double d2 = 8 * 0.1;

	std::cout << "d1 == d2? " << (d1 == d2 ? "true": "false") << "\n";

	std::cout << std::fixed << std::setprecision(17);
	std::cout << "d1 =" << d1 << "\n";
	std::cout << "d2 =" << d2 << "\n";

	std::cout << "approx(d1, d2)? " << (approx(d1, d2) ? "true" : "false") << "\n";

	return 0;

}

bool approx(double a, double b, double acc, double eps) {
	double diff = std::abs(a - b);
	if (diff <= acc) return true; // absolute tolerance
	double max_ab = std::max(std::abs(a), std::abs(b));
	return diff <= eps * max_ab; // relative tolerance
}


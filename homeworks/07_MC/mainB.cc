#include <iostream>
#include <cmath>
#include <fstream>
#include <random>
#include "matrix.hpp"
#include "monte.hpp"

const double pi = 3.14159265358979323846;

struct LCG{ // unsigned long was Chat GPT Instant 5.3's idea
	unsigned long seed;
	unsigned long a = 1664525;
	unsigned long c = 1013904223;
	unsigned long m = 4294967296;

	LCG(unsigned long seed_) : seed(seed_) {}

	double operator()(){
		seed = (a*seed+c) % m;
		return double(seed+1)/double(m+1);
	}
};

int main(){
	// Test integral for error estimates
	auto smooth = [](const pp::vector& x){
		return std::sin(x[0]) * std::cos(x[1]) * std::exp(x[2]);
	};

	pp::vector a = {0.0, 0.0, 0.0};
	pp::vector b = {1.0, 1.0, 1.0};

	double exact_smooth = (1.0-std::cos(1.0)) * std::sin(1.0) * (std::exp(1.0)-1.0);

	std::ofstream scaling("scalingB.data");
	scaling << "# lcg_actual_error quasi_actual_error quasi_estimated error\n";

	for(int N = 100; N <= 1000000; N *= 2){

		LCG rng(12345);

		auto [plain_result, plain_error] = pp::plainmc(smooth, a, b, N, rng);
		auto [quasi_result, quasi_error] = pp::quasimc_error(smooth, a, b, N);

		double plain_actual = std::abs(plain_result-exact_smooth);
		double quasi_actual = std::abs(quasi_result-exact_smooth);

		scaling << N << " " << plain_actual << " " << quasi_actual << " " << quasi_error << "\n";
	}

	scaling.close();

	// Integral given by the task B
	auto singular = [](const pp::vector& x){
		return 1.0/(1.0-std::cos(x[0])*std::cos(x[1])*std::cos(x[2]));
	};

	pp::vector sa = {0.0, 0.0, 0.0};
	pp::vector sb = {pi, pi, pi};

	double exact = 1.3932039296856768591842462603255;

	std::ofstream out("singularB.data");
	out << "# lcg stl quasi exact\n";

	for(int N = 1000; N <= 1000000; N *= 2){
		LCG rng_lcg(12345);

		auto [lcg_result_raw, lcg_error_raw] = pp::plainmc(singular, sa, sb, N, rng_lcg);

		double lcg_result = lcg_result_raw/(pi*pi*pi);

		std::mt19937 gen(12345);
		std::uniform_real_distribution<double> dist(0.0, 1.0);

		auto stl_rng = [&](){
			return dist(gen);
		};

		auto [stl_result_raw, stl_error_raw] = pp::plainmc(singular, sa, sb, N, rng_lcg);
		double stl_result = stl_result_raw/(pi*pi*pi);

		auto [quasi_result_raw, quasi_error_raw] = pp::quasimc_error(singular, sa, sb, N);
		double quasi_result = quasi_result_raw/(pi*pi*pi);

		out << N << " " << lcg_result << " " << stl_result << " " << quasi_result << " " << exact << "\n";

	}

	out.close();

	return 0;
}

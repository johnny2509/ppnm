#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <functional>
#include "integ_open.hpp"

// Test integrals on the interval [0, 1]:
// ∫dx √(x) = 2/3, 
// ∫dx √(1-x²) = π/4, 

int main(){
    std::cout << std::setprecision(15);

    double acc=1e-6;
    double eps=1e-6;

    //auto test = [&](std::string name,
    //        std::function<double(double)> f,
    //        double exact){

    //    size_t ncalls = 0; // Chat GPT Instant 5.3

    //    auto counted_f = [&](double x){ // Chat GPT Instant 5.3
    //        ncalls++; // Chat GPT Instant 5.3
    //        return f(x); // Chat GPT Instant 5.3
    //    };

    //    double result = pp::integrate(counted_f, 0, 1, acc, eps); // Chat GPT Instant 5.3
    //    double diff = std::abs(result - exact);

        //std::cout << name << "\n";
		//std::cout << "result = " << result << "\n";
        //std::cout << "# of calls = " << ncalls << "\n";
		//std::cout << "exact  = " << exact << "\n";
		//std::cout << "diff   = " << diff << "\n\n";
	//};

    //test("Integral sqrt(x)",
	//	[](double x){ return std::sqrt(x); },
	//	2.0/3.0);

	//test("Integral sqrt(1-x^2)",
	//	[](double x){ return std::sqrt(1-x*x); },
	//	std::acos(-1.0)/4.0);


    double exact_erf1 = 0.84270079294971486934;
	double my_erf1 = pp::erf_integral(1.0, 1e-6, 0);
    double pi = std::acos(-1.0);

	//std::cout << "erf(1)\n";
	//std::cout << "result = " << my_erf1 << "\n";
	//std::cout << "exact  = " << exact_erf1 << "\n";
	//std::cout << "diff   = " << std::abs(my_erf1-exact_erf1) << "\n\n";

	//std::cout << "# acc abs_error\n";
	//for(double a=1e-1; a>=1e-8; a/=10){
	//	double val = pp::erf_integral(1.0, a, 0);
	//	double err = std::abs(val-exact_erf1);
	//	std::cout << a << " " << err << "\n";
	//}

	//std::cout << "\nComparison with tabulated values:\n";
	//std::cout << "z\tcomputed\t\tknown\n";

    double zvals[] = {0.0, 0.5, 1.0, 1.5, 2.0};

	for(double z : zvals){
		double computed = pp::erf_integral(z, 1e-6, 1e-6);
		double known = std::erf(z);
	//	std::cout << z << "\t"
	//		  << computed << "\t"
	//		  << known << "\n";
	}

	std::cerr << "Starting erf data\n";
	std::ofstream out_erf_acc("erf_acc_open.dat");

	for(double a=1e-1; a >= 1e-8; a/=10){
        size_t ncalls = 0; // Chat GPT Instant 5.3
        auto f = [&](double x){ // Chat GPT Instant 5.3
            ncalls++; // Chat GPT Instant 5.3
            return std::exp(-x*x); // Chat GPT Instant 5.3
        };
        double integral = pp::integrate(f, 0.0, 1.0, a, 0.0);
		double val = 2.0/std::sqrt(std::acos(-1.0)) * integral; // Chat GPT Instant 5.3
        double err = std::abs(val-exact_erf1);
		out_erf_acc << a << " " << err << " " << ncalls << "\n";
	}
	out_erf_acc.close();

	std::cerr << "Starting sqrt data\n";
	std::ofstream sqrt_out("sqrt_calls_open.dat");

	for(double a=1e-1; a >= 1e-8; a/=10){
        size_t ncalls = 0; // Chat GPT Instant 5.3
        auto f = [&](double x){ // Chat GPT Instant 5.3
            ncalls++; // Chat GPT Instant 5.3
            return std::sqrt(x); // Chat GPT Instant 5.3
        };
        double val = pp::integrate(f, 0.0, 1.0, a, 0.0);
        double err = std::abs(val-2.0/3.0);
		sqrt_out << a << " " << err << " " << ncalls << "\n";
	}
	sqrt_out.close();

	std::cerr << "Starting inv_sqrt CC data\n";
	std::ofstream invsqrt_out("invsqrt_calls_open_cc.dat");

	for(double a=1e-1; a >= 1e-8; a/=10){
        size_t ncalls = 0; // Chat GPT Instant 5.3
        auto f = [&](double x){ // Chat GPT Instant 5.3
            ncalls++; // Chat GPT Instant 5.3
            return 1.0/std::sqrt(x); // Chat GPT Instant 5.3
        };
        double val = pp::integrate_cc(f, 0.0, 1.0, a, 0.0);
        double err = std::abs(val-2.0);
		invsqrt_out << a << " " << err << " " << ncalls << "\n";
	}
	invsqrt_out.close();

	std::ofstream nested_out("nested_calls_open.dat");

	for(double a=1e-1; a >= 1e-8; a/=10){
        size_t ncalls = 0; // Chat GPT Instant 5.3
        auto f = [&](double x){ // Chat GPT Instant 5.3
            ncalls++; // Chat GPT Instant 5.3
            return std::sqrt(1-x*x); // Chat GPT Instant 5.3
        };
        double val = pp::integrate(f, 0.0, 1.0, a, 0.0);
        double err = std::abs(val-pi/4.0);
		nested_out << a << " " << err << " " << ncalls << "\n";
	}
	nested_out.close();

	std::cerr << "Starting ln_sqrt CC data\n";
	std::ofstream ln_sqrt_out("ln_sqrt_calls_open_cc.dat");

	for(double a=1e-1; a >= 1e-4; a/=10){
        size_t ncalls = 0; // Chat GPT Instant 5.3
        auto f = [&](double x){ // Chat GPT Instant 5.3
            ncalls++; // Chat GPT Instant 5.3
            return std::log(x)/std::sqrt(x); // Chat GPT Instant 5.3
        };
        double val = pp::integrate_cc(f, 0.0, 1.0, a, 0.0);
        double err = std::abs(val-(-4.0));
		ln_sqrt_out << a << " " << err << " " << ncalls << "\n";
	}
	ln_sqrt_out.close();

	std::ofstream erfplot("erf_plot_open.dat");
	for(double z=-3.0; z<=3.0; z+=0.05){
		erfplot << z << " " << pp::erf_integral(z, 1e-6, 1e-6) << "\n";
	}
	erfplot.close();	

	return 0;
            
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <functional>
#include <exception>
#include "integ_open.hpp"

int main(){
    std::cout << std::setprecision(15);

    double acc=1e-6;
    double eps=1e-6;

    double exact_erf1 = 0.84270079294971486934;
	double my_erf1 = pp::erf_integral(1.0, 1e-6, 0);
    double pi = std::acos(-1.0);

    double zvals[] = {0.0, 0.5, 1.0, 1.5, 2.0};

	for(double z : zvals){
		double computed = pp::erf_integral(z, 1e-6, 1e-6);
		double known = std::erf(z);
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

		try{ // Claude Haiku 4.5
            double result = pp::integrate_cc(f, 0.0, 1.0, a, 0.0, 200);
            double error = std::abs(result-(-4.0));

            ln_sqrt_out << a << " " << error << " " << ncalls << "\n"; // Claude Haiku 4.5

            std::cerr << "success: acc = " << a << ", calls = " << ncalls << ", error = " << error << "\n"; // Claude Haiku 4.5
        }

        catch(const std::exception& e){
            std::cerr << "failed: acc = " << a << ", calls = " << ncalls << ", reason: " << e.what() << "\n"; // Claude Haiku 4.5
			break;
        }
 
	}
	ln_sqrt_out.close();

	std::ofstream erfplot("erf_plot_open.dat");
	for(double z=-3.0; z<=3.0; z+=0.05){
		erfplot << z << " " << pp::erf_integral(z, 1e-6, 1e-6) << "\n";
	}
	erfplot.close();	

	return 0;
            
}
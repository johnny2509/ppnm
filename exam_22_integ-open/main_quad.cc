#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <exception>
#include "quadinteg.hpp"

// Modified from the 06_Quad homework (original: main-hppB.cc)

int main(){
	
    double exact_erf1 = 0.84270079294971486934;
    double pi = std::acos(-1.0);

    std::ofstream erf_out("erf_calls_quad.dat"); // Claude Haiku 4.5
    for(double acc=1e-1; acc>=1e-8; acc/=10.0){
        int calls = 0;
        auto f = [&](double x){
            calls++;
            return std::exp(-x*x);
        };
        double integral = pp::integrate(f, 0.0, 1.0, acc, 0.0);
		double erf1 = 2.0/std::sqrt(pi) * integral;
        double error = std::abs(erf1-exact_erf1);
        erf_out << acc << " " << calls << " " << error << " " << erf1 << "\n";
    }
    erf_out.close();

    std::ofstream sqrt_out("sqrt_calls_quad.dat"); // Claude Haiku 4.5
    for(double acc=1e-1; acc>=1e-8; acc/=10.0){
        int calls = 0;
        auto f = [&](double x){
            calls++;
            return std::sqrt(x);
        };
        double result = pp::integrate(f, 0.0, 1.0, acc, 0.0);
        double error = std::abs(result-2.0/3.0);
        sqrt_out << acc << " " << calls << " " << error << "\n";
    }
    sqrt_out.close();

    std::ofstream inv_sqrt_out("inv_sqrt_calls_quad_cc.dat"); // Claude Haiku 4.5
    for(double acc=1e-1; acc>=1e-8; acc/=10.0){
        int calls = 0;
        auto f = [&](double x){
            calls++;
            return 1.0/std::sqrt(x);
        };
        double result = pp::clenshaw_curtis(f, 0.0, 1.0, acc, 0.0);
        double error = std::abs(result-2.0);
        inv_sqrt_out << acc << " " << calls << " " << error << "\n";
    }
    inv_sqrt_out.close();

    std::ofstream nested_out("nested_calls_quad.dat"); // Claude Haiku 4.5
    for(double acc=1e-1; acc>=1e-8; acc/=10.0){
        int calls = 0;
        auto f = [&](double x){
            calls++;
            return std::sqrt(1-x*x);
        };
        double result = pp::integrate(f, 0.0, 1.0, acc, 0.0);
        double error = std::abs(result-pi/4.0);
        nested_out << acc << " " << calls << " " << error << "\n";
    }
    nested_out.close();

    std::ofstream ln_sqrt_out("ln_sqrt_calls_quad_cc.dat"); // Claude Haiku 4.5
    for(double acc=1e-1; acc>=1e-8; acc/=10.0){
        int calls = 0;
        auto f = [&](double x){
            calls++;
            return std::log(x)/std::sqrt(x);
        };

        try{ // Claude Haiku 4.5
            double result = pp::clenshaw_curtis(f, 0.0, 1.0, acc, 0.0);
            double error = std::abs(result-(-4.0));

            ln_sqrt_out << acc << " " << calls << " " << error << "\n";

            std::cerr << "success: acc = " << acc << ", calls = " << calls << ", error = " << error << "\n"; // Claude Haiku 4.5
        }

        catch(const std::exception& e){
            std::cerr << "failed: acc = " << acc << ", calls = " << calls << ", reason: " << e.what() << "\n";
        }
    }
    ln_sqrt_out.close();

	return 0;

}
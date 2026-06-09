#include "matrix.hpp"
#include "ode.hpp"
#include "newton.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

// this block of code was realized with Chat GPT Instant 5.3

int main(){
	using namespace pp;

	std::cout.precision(15);

	// values
	double rmin = 1e-3;
	double rmax = 8.0;
	double acc = 1e-6;
	double eps = 1e-6;

	// For the bound s-wave wave-function we assume f(r)=ar+br^2+...
	// Insert f(r) into -1/2f''-1/r f=Ef, and if we choose a=1
	// then the boundary condition meets f(r)=r-r^2+...

	// for y[0]=f, and y[1]=f'

	auto solve_for_energy = [&](double E){
		auto schrodinger = [=](double r, vector y){
			return vector{
				y[1],
				-2.0*(E+1.0/r)*y[0]
			};
		};

		vector yinit = {
			rmin - rmin*rmin,
			1.0 - 2.0*rmin
		};

		auto [rs, ys] = driver(schrodinger,rmin,rmax,yinit,0.01,acc,eps,0.05);

		return std::make_tuple(rs, ys);
	};

	// Shooting method for M(E)=f_E(rmax)

	vecfunc M = [&](const vector& x){
		double E = x[0];

		auto [rs, ys] = solve_for_energy(E);

		double f_at_rmax = ys.back()[0];
	
		return vector{f_at_rmax};
	};

	// Then we find the lowest bound energy state

	vector Eroot = newton(M, vector{-0.7}, 1e-8);

	double E0 = Eroot[0];

	std::cout << "H-atom s-wave shooting method\n";
	std::cout << "rmin = " << rmin << "\n";
	std::cout << "rmax = " << rmax << "\n";
	std::cout << "acc  = " << acc  << "\n";
	std::cout << "eps  = " << eps  << "\n";

	std::cout << "Numerical ground state energy E0 = " << E0 << "\n";
	std::cout << "Exact ground state energy        = " << -0.5 << "\n";
	std::cout << "Absolute error                   = " << std::abs(E0+0.5) << "\n\n";

	auto [rs, ys] = solve_for_energy(E0);

	std::ofstream wf("wavefunctionB.txt");
	wf << "# r numerical_f exact_f\n";

	for(size_t i=0; i<rs.size(); i++){
		double r = rs[i];
		double numerical = ys[i][0];
		double exact = r*std::exp(-r);

		wf << r << " " << numerical << " " << exact << "\n";
	}

	wf.close();

	// Convergence of rmax

	std::ofstream conv_rmax("convergence_rmaxB.txt");
	conv_rmax << "# rmax E0 abs_error\n" << std::flush;

	std::cout << "Starting rmax convergence\n" << std::flush;

	double Eguess = -0.5;

	for(double R : {4.0,5.0,6.0,7.0,8.0,10.0,12.0}){
		rmax = R;

		std::cout << "Trying rmax = " << R << "\n" << std::flush;

		vecfunc MR = [&](const vector& x){
			double E = x[0];
			auto [rs_tmp, ys_tmp] = solve_for_energy(E);
			return vector{ys_tmp.back()[0]};
		};
	
		vector ER = newton(MR, vector{Eguess}, 1e-8);
		Eguess = ER[0];

		double err = std::abs(ER[0]+0.5);

		std::cout << "rmax = " << R << ", E0 = " << ER[0] << ", err = " << err << "\n" << std::flush;

		conv_rmax << R << " " << ER[0] << " " << err << "\n" << std::flush;

	}

	conv_rmax.close();

	// Convergence of rmin

	rmax = 8.0;

	std::ofstream conv_rmin("convergence_rminB.txt");
	conv_rmin << "# rmin E0 abs_error\n";

	for(double R0 : {1e-1,5e-2,1e-2,5e-3,1e-3,5e-4,1e-4}){
		rmin = R0;
		
		vecfunc MR0 = [&](const vector& x){
			double E = x[0];
			auto [rs_tmp, ys_tmp] = solve_for_energy(E);
			return vector{ys_tmp.back()[0]};
		};

		vector ER0 = newton(MR0, vector{-0.7}, 1e-8);
		double err = std::abs(ER0[0]+0.5);

		conv_rmin << R0 << " " << ER0[0] << " " << err << "\n";
	}

	conv_rmin.close();

	std::cout << "Saved wave-function to wavefunctionB.txt\n";
	std::cout << "Saved rmax convergence to convergence_rmaxB.txt\n";
	std::cout << "Saved rmin convergence to convergence_rminB.txt\n"; 

	// Convergence of acc

	rmin = 1e-3;
	rmax = 8.0;
	eps = 1e-6;

	std::ofstream conv_acc("convergence_accB.txt");
        conv_acc << "# acc E0 abs_error\n";

        for(double A : {1e-3,1e-4,1e-5,1e-6,1e-7,1e-8}){
                acc = A;

                vecfunc MA = [&](const vector& x){
                        double E = x[0];
                        auto [rs_tmp, ys_tmp] = solve_for_energy(E);
                        return vector{ys_tmp.back()[0]};
                };

                vector EA = newton(MA, vector{-0.7}, 1e-8);
                double err = std::abs(EA[0]+0.5);

                conv_acc << A << " " << EA[0] << " " << err << "\n";
        }

        conv_acc.close();

	// Convergence with eps

	std::ofstream conv_eps("convergence_epsB.txt");
        conv_eps << "# eps E0 abs_error\n";
                        
        for(double EP : {1e-3,1e-4,1e-5,1e-6,1e-7,1e-8}){
                eps = EP; 
                  
                vecfunc ME = [&](const vector& x){
                        double E = x[0];
                        auto [rs_tmp, ys_tmp] = solve_for_energy(E);
                        return vector{ys_tmp.back()[0]};
                };
        
                vector EE = newton(ME, vector{-0.7}, 1e-8);
                double err = std::abs(EE[0]+0.5);
        
                conv_eps << EP << " " << EE[0] << " " << err << "\n";
        }
        
        conv_eps.close();

	return 0;
}

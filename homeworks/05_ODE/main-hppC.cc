#include <iostream>
#include <cmath>
#include "ode.hpp"

// This block of code was realized with the help of Chat GPT Instant 5.3

int main(){
	auto threebody = [](double /*t*/, pp::vector z){
		pp::vector dzdt(12);

		double vx1=z[0], vy1=z[1];
		double vx2=z[2], vy2=z[3];
		double vx3=z[4], vy3=z[5];

		double x1=z[6], y1=z[7];
		double x2=z[8], y2=z[9];
		double x3=z[10], y3=z[11];

		auto add_acc = [](double xi, double yi, double xj, double yj, double& ax, double& ay){
			double dx = xj - xi;
			double dy = yj - yi;
			double r2 = dx*dx + dy*dy;
			double r = std::sqrt(r2);
			double r3 = r2*r;

			ax += dx/r3;
			ay += dy/r3;
		};

		double ax1 = 0, ay1 = 0;
		double ax2 = 0, ay2 = 0;
		double ax3 = 0, ay3 = 0;

		add_acc(x1,y1,x2,y2,ax1,ay1);
		add_acc(x1,y1,x3,y3,ax1,ay1);

		add_acc(x2,y2,x1,y1,ax2,ay2);
		add_acc(x2,y2,x3,y3,ax2,ay2);

		add_acc(x3,y3,x1,y1,ax3,ay3);
		add_acc(x3,y3,x2,y2,ax3,ay3);

		dzdt[0]=ax1;
		dzdt[1]=ay1;
		dzdt[2]=ax2;
		dzdt[3]=ay2;
		dzdt[4]=ax3;
		dzdt[5]=ay3;

		dzdt[6]=vx1;
                dzdt[7]=vy1;
                dzdt[8]=vx2;
                dzdt[9]=vy2;
                dzdt[10]=vx3;
                dzdt[11]=vy3;

		return dzdt;
	};

	// Initial conditions from https://www.researchgate.net/publication/369759901_The_remarkable_figure-8_solution_of_the_three-body_problem

	pp::vector z0 = {
		0.4662036850, 0.4323657300,
		-0.9324073700, -0.8647314600,
		0.4662036850, 0.4323657300,
	
		-0.97000436, 0.24308753,
		0.0, 0.0,
		0.97000436, -0.24308753
	};

	double T = 6.3259; // approximate period of figure 8 orbit

	auto [ts, zs]=pp::driver(threebody, 0.0, T, z0, 0.0001, 1e-7, 1e-7, 0.001);

	for(size_t i = 0; i < ts.size(); i++){
		std::cout << ts[i] << " "
			  << zs[i][6] << " " << zs[i][7] << " "
			  << zs[i][8] << " " << zs[i][9] << " "
			  << zs[i][10] << " " << zs[i][11] << "\n";
	}
	return 0;
}

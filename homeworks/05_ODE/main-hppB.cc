#include <iostream>
#include <cmath>
#include "ode.hpp"

int main(){
	
	auto relpre = (double /*t*/, pp::vector y){

		double u = y[0];
		double w = y[1];

		pp::vector dydt(2);
		dydt[0] = w;
		dydt[1] = 1 + ep*u*u - u

#include "ann.hpp"
#include "matrix.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

double g(double x){
    return std::cos(5*x-1) * std::exp(-x*x);
}

int main(){

    int N = 100; // number of training data points
    int n_neurons = 20; // number of hidden neurons

    pp::vector x(N), y(N);

    double start = -1.0;
    double end = 1.0;
    double dx = (end-start)/(N-1); // divide the interval into N-1 segments

    for(int i=0; i<N; i++){
        x[i] = start+i*dx;
        y[i] = g(x[i]);
    }

    pp::ann network(n_neurons);
    network.train(x, y);

    std::ofstream data("outB.txt");

    for(int i=0; i<N; i++){
        data << x[i] << " " 
        << y[i] << " " 
        << network.response(x[i]) << " "
        << network.derivative(x[i]) << " "
        << network.second_derivative(x[i]) << " "
        << network.antiderivative(x[i]) << "\n";
    }

    data.close();

    return 0;

}
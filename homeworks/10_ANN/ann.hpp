#pragma once 
#include "matrix.hpp"
#include "min.hpp"
#include <cmath>
#include <functional>

// The neuron number i transforms its signal into an output signal y_i
// as y_i = f((x - a_i) / b_i) * w_i, so we have parameters a_i, b_i, and 
// w_i for neutron number i. Here f is the activation function, and the whole
// networks respons is y = F_p(x) which is the sum of all y_i, i=1,2,...,n,
// where p = {a_i, b_i, w_i} for i=1,2,...,n is the set of all parameters.

// The idea is to give the network some tabulated values {x_k, y_k} for 
// k=1,2,...,N (training data), and then tuning of the parameters to minimize 
// the cost function C(p) = sum_k (F_p(x_k) - y_k)^2.

// We reuse the matrix.hpp header from 01_QR and the 
// header min.hpp from 09_Min.

// We use the function g(x) = cos(5x-1) * exp(-x^2) as traning function, so our 
// and the gaussian wavelets f(x) = x * exp(-x^2) as activation function, which 
// is (probably) the best choice for this task.

namespace pp {

struct ann{

    int n; // number of hidden neurons

    std::function<double(double)> f; // activation function
    vector p; // parameters: p = {a_i, b_i, w_i} for i=1,2,...,n

    ann(int n) : n(n), p(3*n) { // 3*n because we have 3 parameters.
        f = [](double x){
            return x*std::exp(-x*x); // Gaussian wavelets are (probably) the best activation function as per the task.
        };

        for(int i=0; i<n; i++){
            p[3*i + 0] = -1.0 + 2.0*i/(n-1); // a_i, uniformly distributed in [-1, 1]
            p[3*i + 1] = 0.3; // b_i, set to a constant value (can be tuned)
            p[3*i + 2] = 1.0; // w_i, set to a constant value (can be tuned)
        }
    } // constructor

    double response(double x) const{
        return response(x, p);
    }

    double response(double x, const vector& q) const{
        double sum = 0;

        for(int i=0; i<n; i++){
            double a = q[3*i + 0];
            double b = q[3*i + 1];
            double w = q[3*i + 2];

            sum += w*f((x - a) / b);
        }
        return sum;
    }

    // Task B: 
    // The analytic first derivative, second derivative, and anti-derivative of
    // the Gaussian wavelet activation function is
    // df(z)  = -2z^2*exp(-z^2)+exp(-z^2) = exp(-z^2)(1-2z^2)
    // ddf(z) = exp(-z^2)*(-2z)*(1-2z^2)+exp(-z^2)*(-4z) = exp(-z^2)(-6z+4z^3)
    // int f(z) dz = -0.5*exp(-z^2) + C, where C is the integration constant.

    double derivative(double x) const{
        double sum = 0;

        for(int i=0; i<n; i++){
            double a = p[3*i + 0];
            double b = p[3*i + 1];
            double w = p[3*i + 2];

            double z = (x - a) / b;
            double df = std::exp(-z*z)*(1-2*z*z);
            sum += w*df/b; // chain rule
        }
        return sum;
    }

    double second_derivative(double x) const{
        double sum = 0;

        for(int i=0; i<n; i++){
            double a = p[3*i + 0];
            double b = p[3*i + 1];
            double w = p[3*i + 2];

            double z = (x - a) / b;
            double ddf = std::exp(-z*z)*(-6*z+4*z*z*z);
            sum += w*ddf/(b*b); // chain rule
        }
        return sum;
    }

    double antiderivative(double x) const{
        double sum = 0;

        for(int i=0; i<n; i++){
            double a = p[3*i + 0];
            double b = p[3*i + 1];
            double w = p[3*i + 2];

            double z = (x - a) / b;
            double intf = -0.5*std::exp(-z*z);
            sum += w*intf*b; // chain rule
        }
        return sum;
    }

    void train(const vector& x, const vector& y){
        auto cost = [&](const vector& q){
            double C = 0;

            for(int k =0; k<x.size(); k++){
                double diff = response(x[k], q) - y[k];
                C += diff*diff;
            }
            return C;
        };
        
        // The analytic gardient was not needed, since the network predicted  
        // g(x) accurately using training data from numerical gradients and Hessians.
        p = pp::newton(cost, p, 1e-4, 1000);
    }

};

}
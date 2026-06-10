#pragma once
#include "matrix.hpp"
#include<functional>
#include<cmath>

// We reuse the matrix.hpp header from the homework 01_QR
// This block of code was realized by Chat GPT Instant 5.3.

namespace pp {

using func = std::function<double(const vector&)>;

// The numerical gradient of the object function phi(x):
vector gradient(func phi, vector x){
    double phix = phi(x);
    vector g(x.size());

    for(int i = 0; i<x.size(); i++){
        double dxi = (1+std::abs(x[i])) * std::pow(2,-26);
        x[i] += dxi;
        g[i] = (phi(x) - phix) / dxi;
        x[i] -= dxi;
    }

    return g;
}

// The Hessian matrix of the object function phi(x):
matrix hessian(func phi, vector x){
    int n = x.size();
    matrix H(n, n);
    vector gx = gradient(phi, x);

    for(int j=0; j<n; j++){
        double dxj = (1+std::abs(x[j])) * std::pow(2,-13);
        x[j] += dxj;
        vector dg = gradient(phi, x) - gx;
        for(int i=0; i<n; i++){
            H(i, j) = dg[i] / dxj;
        
        }
        
        x[j] -= dxj;
    }

    return H;
}

// The Newton minimization method:
vector newton(func phi, vector x, double acc=1e-3, int max_steps=1000, int* steps=nullptr){
    int k = 0;
    while(k < max_steps){
        vector g = gradient(phi, x);
        if(g.norm() < acc) break;

        matrix H = hessian(phi, x);

        for(int i=0; i<H.size1(); i++)
            H(i, i) += 1e-6; 

        vector dx = qr(H).solve(-g);

        double phix = phi(x);
        double lambda = 1.0;

        while(lambda >= 1.0/1024){
            if(phi(x + lambda * dx) < phix) break;
            lambda /= 2;
        }

        x = x + lambda * dx;
        k++;
    }

    if(steps != nullptr) *steps = k;
    return x;
}

}
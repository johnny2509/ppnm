#pragma once
#include <iostream>
#include <string>

// Task 1: class storing x, y, z doubles.
struct vec {
    double x, y, z; // Chat GPT Instant 5.3
    // constructors
    vec(double x, double y, double z);  // parameterized, Chat GPT Instant 5.3
    vec();                                  // default, Chat GPT Instant 5.3
    vec(const vec&) = default;                                 // copy
    vec(vec&&) = default;                                      // move
    ~vec() = default;                                          // destructor

    // assignment
    vec& operator=(const vec&) = default;                     // copy assignment
    vec& operator=(vec&&) = default;                          // move assignment

    // arithmetic
    vec& operator+=(const vec&);
    vec& operator-=(const vec&);
    vec& operator*=(double);
    vec& operator/=(double);

    double dot(const vec&) const;
    vec cross(const vec&) const;
    double norm() const;

    // utility
    void set(double, double, double); // Chat GPT Instant 5.3
    void print(const std::string& s = "") const;              // for debugging

    // stream output
    friend std::ostream& operator<<(std::ostream&, const vec&);
};

// non-member operators
vec operator-(const vec&);
vec operator+(vec, const vec&);
vec operator-(vec, const vec&);
vec operator*(vec, double);
vec operator*(double, vec);
vec operator/(vec, double);

// approx
bool approx(double a, double b, double acc=1e-6, double eps=1e-6); // Chat GPT Instant 5.3
bool approx(const vec&, const vec&, double acc=1e-6, double eps=1e-6);

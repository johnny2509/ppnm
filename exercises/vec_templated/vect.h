// Task A: earlier implenented header, "vec.h", for the "vec" class modified 
// to accept float and double for x, y, z. The "vec.cc" file can be disregarded
// and often double is simply replaced by T. 

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

template <typename T>
struct vec {

    T x, y, z;

    // constructors
    vec(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {} 
    vec() : vec(0, 0, 0) {}                        
         
    vec(const vec&) = default;                                 // copy
    vec(vec&&) = default;                                      // move
    ~vec() = default;                                          // destructor

    // assignment
    vec& operator=(const vec&) = default;                     // copy assignment
    vec& operator=(vec&&) = default;                          // move assignment

    // arithmetic
    vec& operator+=(const vec& v){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
    }
    vec& operator-=(const vec& v){
	x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    vec& operator*=(T d){
	x *= d;
	y *= d;
	z *= d;
	return *this;
    }
    vec& operator/=(T d){
        x /= d;
        y /= d;
        z /= d;
        return *this;
    }

    T dot(const vec& v) const{
	return x*v.x + y*v.y + z*v.z;
    }

    vec cross(const vec& v) const{
	return vec(
		y*v.z - z*v.y,
		z*v.x - x*v.z,
		x*v.y - y*v.x
	);
    }

    T norm() const{
	return std::sqrt(dot(*this));
    }

    void set(T a, T b, T c){
	x=a; y=b; z=c;
    }

    void print(const std::string& s = "") const{
	std::cout << s << x << " " << y << " " << z << std::endl;
    }
};

// templated non-member operators
template <typename T>
vec<T> operator-(const vec<T>& v){
	return vec<T>(-v.x, -v.y, -v.z);
}
template <typename T>
vec<T> operator+(vec<T> a, const vec<T>& b){
	a += b;
	return a;
}
template <typename T>
vec<T> operator-(vec<T> a, const vec<T>& b){
        a -= b;
        return a;
}
template <typename T>
vec<T> operator*(vec<T> v, T d){
        v *= d;
        return v;
}
template <typename T>     
vec<T> operator*(T d, vec<T> v){            
        v *= d;
        return v;
}
template <typename T>     
vec<T> operator/(vec<T> v, T d){            
        v /= d;
        return v;
}

// stream output
template <typename T>
std::ostream& operator<<(std::ostream& os, const vec<T>& v){
	os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
	return os;
}

// scalar approximation
template <typename T>
bool approx(T a, T b, T acc=1e-6, T eps=1e-6){
	if (std::abs(a-b) <= acc) return true;
	if (std::abs(a-b) <= eps*std::max(std::abs(a), std::abs(b))) return true;
	return false;
}
// vector approximation
template <typename T>
bool approx(const vec<T>& a, const vec<T>& b, T acc=1e-6, T eps=1e-6){
	if (!approx(a.x, b.x, acc, eps)) return false;
        if (!approx(a.y, b.y, acc, eps)) return false;
        if (!approx(a.z, b.z, acc, eps)) return false;
	return true;
}

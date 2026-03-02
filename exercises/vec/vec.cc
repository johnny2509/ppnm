#include<cmath>
#include"vec.h"

// constructors
vec::vec(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
vec::vec() : vec(0,0,0) {}

void vec::print(std::string s) const {
    std::cout << s << x << " " << y << " " << z << std::endl;
    } 


// plus
vec& vec::operator += (const vec& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

// minus
vec& vec::operator -= (const vec& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
}  

// multiplication
vec& vec::operator *= (double d) {
        x *= d;
        y *= d;
        z *= d;
        return *this;
}  

// dividing
vec& vec:: operator /= (double d) {
        x /= d;
        y /= d;
        z /= d;
        return *this;
}  

// dot product
double vec::dot(const vec& v) const{
	return x*v.x + y*v.y + z*v.z;
}

\\ cross product
vec vec::cross(const vec& v) const{
	return vec(
		y*v.z - z*v.y,
		z*v.x - x*v.z,
		x*v.y - y*v.x
	);
}

\\ norm
double vec::norm() const{
	return std::sqrt(dot(*this));
}


// non-member operators

vec operator-(const vec& v){
	return vec(-v.x, -v.y, -v.z);
}

vec operator+(vec a, const vec& b){
	a += b;
	return a;
}

vec operator-(vec a, const vec& b){
	a -= b;
	return a;
}

vec operator*(vec v, double d){
	v *= d;
	return v;
}

vec operator*(double d, vec v){
	v *= d;
	return v;
}

vec operator/(vec v, double d){
	v /= d;
	return v;
}


// scalar approximation
bool approx(double a, double b, double acc, double eps){
	if (std::abs(a-b) <= acc) return true;
	if (std::abs(a-b) <= eps * std::max(std::abs(a), std::abs(b))) return true;
	return false;
}

// vector approximation
bool approx(const vec& a, const vec& b, double acc, double eps){
	if (!approx(a.x, b.x, acc, eps)) return false;
	if (!approx(a.y, b.y, acc, eps)) return false;
	if (!approx(a.z, b.z, acc, eps)) return false;
	return true;
}


// stream operator
std::ostream& operator<<(std::ostream& os, const vec& v){
    os << "{ " << v.x << ", " << v.y << ", " << v.z << " } ";
    return os;
}


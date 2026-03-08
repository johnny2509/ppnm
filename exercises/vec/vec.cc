#include<cmath>
#include"vec.h"

// Task 2: constructors
vec::vec(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
vec::vec() : vec(0,0,0) {}
// task 1: double values x, y, z.
void vec::set(double a, double b, double c){
	x = a;
	y = b;
	z = c;
}
// Task 4: print function for debugging
void vec::print(const std::string& s) const{
    std::cout << s << x << " " << y << " " << z << std::endl;
    } 
// Task 3: mathematical operators for 3D vectors
vec& vec::operator += (const vec& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
vec& vec::operator -= (const vec& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
}  
vec& vec::operator *= (double d) {
        x *= d;
        y *= d;
        z *= d;
        return *this;
}  
vec& vec:: operator /= (double d) {
        x /= d;
        y /= d;
        z /= d;
        return *this;
}  
double vec::dot(const vec& v) const{
	return x*v.x + y*v.y + z*v.z;
}
vec vec::cross(const vec& v) const{
	return vec(
		y*v.z - z*v.y,
		z*v.x - x*v.z,
		x*v.y - y*v.x
	);
}
double vec::norm() const{
	return std::sqrt(dot(*this));
}
// Also task 3: non-member operators
vec operator-(const vec& v){
	return vec(-v.x, -v.y, -v.z);
}
// Task 6: modern form of the operator+, which is different from the traditional form 
// in that one does not have to create an extra vec r=a to perform the calculation which 
// is faster and optimal for memory.
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
// Task 5: stream operator
std::ostream& operator<<(std::ostream& os, const vec& v){
    os << "{ " << v.x << ", " << v.y << ", " << v.z << " } ";
    return os;
}


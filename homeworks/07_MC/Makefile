CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

all: out.circle.pdf ellipsoid.data

mainA: mainA.cc monte.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

circle.data: mainA
	./mainA > circle.data

out.circle.pdf: circle.data plotA.gp
	gnuplot plotA.gp

clean:
	rm -f mainA circle.data out.circle.pdf



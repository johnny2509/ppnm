CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

all: outA.txt linear_splineA.png linear_integralA.png

mainA: main-hppA.cc linear.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppA.cc -o mainA

outA.txt pointsA.txt: mainA
	./mainA 

linear_splineA.png linear_integralA.png: outA.txt pointsA.txt plotA.gp
	gnuplot plotA.gp

clean:
	rm -f mainA outA.txt pointsA.txt *.png 
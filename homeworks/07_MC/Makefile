CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

all: out.circle.pdf ellipsoid.data out.scalingB.pdf out.singularB.pdf

mainA: mainA.cc monte.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

mainB: mainB.cc monte.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) mainB.cc -o mainB

circle.data ellipsoid.data: mainA
	./mainA > circle.data

scalingB.data singularB.data: mainB
	./mainB

out.circle.pdf: circle.data plotA.gp
	gnuplot plotA.gp

out.scalingB.pdf: scalingB.data plotB.gp
	gnuplot plotB.gp

out.singularB.pdf: singularB.data plotSingular.gp
	gnuplot plotSingular.gp

clean:
	rm -f mainA mainB *.data *.pdf



CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

all: mainA mainB

mainA: main-hppA.cc quadinteg.hpp
	$(CXX) $(CXXFLAGS) -o mainA main-hppA.cc

mainB: main-hppB.cc quadinteg.hpp
	$(CXX) $(CXXFLAGS) -o mainB main-hppB.cc

runA: mainA
	./mainA

runB: mainB
	./mainB

plotA:
	gnuplot plotA.gp

python_compare:
	python3 compare_python.py

claen:
	rm -f mainA mainB *.dat *.pdf

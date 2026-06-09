CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

all: mainA mainB

mainA: mainA.cc newton.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

mainB: mainB.cc newton.hpp ode.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) mainB.cc -o mainB

runA: mainA
	./mainA > outA.txt

runB: mainB
	./mainB > outB.txt

plotB: runB
	gnuplot plotB.gp

run: runA runB

plots: plotB

clean:
	rm -f \
	mainA mainB \
	outA.txt outB.txt \
	wavefunctionB.txt \ 
	convergence_rmaxB.txt \ 
	convergence_rminB.txt \
	convergence_accB.txt \
	convergence_epsB.txt \
	wavefunctionB.png \
	convergence_rmaxB.png \ 
	convergence_rminB.png \
	convergence_accB.png \
	convergence_epsB.png

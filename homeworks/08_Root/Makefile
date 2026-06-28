CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
GNUPLOT = gnuplot

.PHONY: all clean plots

EXES = mainA mainB
TXT_A = outA.txt
TXT_B = wavefunctionB.txt convergence_rmaxB.txt convergence_rminB.txt convergence_accB.txt convergence_epsB.txt outB.txt
PNG = wavefunctionB.png convergence_rmaxB.png convergence_rminB.png convergence_accB.png convergence_epsB.png

all: $(EXES) $(TXT_A) $(TXT_B) $(PNG)

mainA: mainA.cc matrix.hpp newton.hpp 
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

mainB: mainB.cc matrix.hpp ode.hpp newton.hpp  
	$(CXX) $(CXXFLAGS) mainB.cc -o mainB

$(TXT_A): mainA
	./mainA > $@

$(TXT_B): mainB
	./mainB > outB.txt

$(PNG): plotB.gp $(TXT_B)
	$(GNUPLOT) plotB.gp

plots: $(PNG)

clean:
	rm -f $(EXES) $(TXT_A) $(TXT_B) $(PNG)

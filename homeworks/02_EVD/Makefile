CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -Wpedantic
GNUPLOT = gnuplot

.PHONY: all clean plots

EXES = mainA mainB

all: $(EXES) print_statements.txt print_statementsB.txt plots

mainA: main-hppA.cc eigen.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppA.cc -o mainA

mainB: main-hppB.cc eigen.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppB.cc -o mainB

print_statements.txt: $(EXES)
	> $@
	echo "=== Output from mainA ===" >> $@
	./mainA >> $@ 2>&1
	echo "\n=== Output from mainB ===" >> $@
	./mainB >> $@ 2>&1

print_statementsB.txt: mainB
	./mainB -rmax 10 -dr 0.10 > $@

plots: plotB.gp vary_epsB.dat vary_eps2B.dat wavefunc_0.dat wavefunc_1.dat
	$(GNUPLOT) plotB.gp

wavefunc_0.dat wavefunc_1.dat: mainB
	./mainB -rmax 10 -dr 0.10

vary_epsB.dat: mainB
	> $@
	for dr in 0.20 0.15 0.10 0.08 0.06 0.04 0.02 0.01; do \
		printf "%g " $$dr >> $@; \
		./mainB -rmax 10 -dr $$dr | awk '/^[0-9]+ /{print $$2; exit}' >> $@; \
	done

vary_eps2B.dat: mainB
	> $@
	for rmax in 6 8 10 12 15 20 25; do \
		printf "%g " $$rmax >> $@; \
		./mainB -rmax $$rmax -dr 0.10 | awk '/^[0-9]+ /{print $$2; exit}' >> $@; \
	done

clean:
	rm -f $(EXES) print_statements.txt print_statementsB.txt eps0_vs_dr.png eps0_vs_rmax.png wavefunc_01.png wavefunc_0.png vary_eps2B.dat vary_epsB.dat wavefunc_0.dat wavefunc_1.dat

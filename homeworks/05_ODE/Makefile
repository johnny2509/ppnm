CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -Wpedantic
GNUPLOT = gnuplot

.PHONY: all clean plots

EXES = mainA mainA4 mainB mainC
DAT = outA.txt pendulum.txt orbit_circular.txt orbit_ellipse.txt orbit_precession.txt outC.txt
PDF = oscillator.pdf pendulum.pdf orbits.pdf figC.pdf

all: $(EXES) $(DAT) $(PDF)

mainA: main-hppA.cc ode.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppA.cc -o mainA

mainA4: main-hppA4.cc ode.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppA4.cc -o mainA4

mainB: main-hppB.cc ode.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppB.cc -o mainB

mainC: main-hppC.cc ode.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppC.cc -o mainC

outA.txt: mainA
	./mainA > $@

pendulum.txt: mainA4
	./mainA4 > $@

orbit_circular.txt orbit_ellipse.txt orbit_precession.txt: mainB
	./mainB

outC.txt: mainC
	./mainC > $@

oscillator.pdf: plotA.gp outA.txt
	$(GNUPLOT) plotA.gp

pendulum.pdf: plotA4.gp pendulum.txt
	$(GNUPLOT) plotA4.gp

orbits.pdf: plotB.gp orbit_circular.txt orbit_ellipse.txt orbit_precession.txt
	$(GNUPLOT) plotB.gp

figC.pdf: plotC.gp outC.txt
	$(GNUPLOT) plotC.gp

plots: $(PDF)

clean:
	rm -f $(EXES) $(DAT) $(PDF)

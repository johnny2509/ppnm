CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
GNUPLOT = gnuplot

.PHONY: all clean plots

EXES = mainA mainB
TXT = outA.txt outB.txt
PNG = ann.png annB.png derivativeB.png second_derivativeB.png anti_derivativeB.png

all: $(EXES) $(TXT) $(PNG)

mainA: mainA.cc ann.hpp matrix.hpp min.hpp
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

mainB: mainB.cc ann.hpp matrix.hpp min.hpp
	$(CXX) $(CXXFLAGS) mainB.cc -o mainB

outA.txt: mainA
	./mainA

outB.txt: mainB
	./mainB

ann.png: plotA.gp outA.txt
	$(GNUPLOT) plotA.gp

annB.png derivativeB.png second_derivativeB.png anti_derivativeB.png: plotB.gp outB.txt
	$(GNUPLOT) plotB.gp

plots: $(PNG)

clean:
	rm -f $(EXES) $(TXT) $(PNG)

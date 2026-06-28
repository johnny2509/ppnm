CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
GNUPLOT = gnuplot

.PHONY: all clean plots

EXES = mainA mainB
DAT = erf_acc.dat erf_plot.dat
PDF = erf_conv.pdf erf_plot.pdf
TXT = mainA_output.txt

all: $(EXES) $(DAT) $(PDF) $(TXT)

mainA: main-hppA.cc quadinteg.hpp
	$(CXX) $(CXXFLAGS) -o mainA main-hppA.cc

mainB: main-hppB.cc quadinteg.hpp
	$(CXX) $(CXXFLAGS) -o mainB main-hppB.cc

$(TXT): mainA
	./mainA > $@

$(DAT): $(TXT)

erf_conv.pdf: plotA.gp erf_acc.dat
	$(GNUPLOT) plotA.gp

erf_plot.pdf: plot_erf.gp erf_plot.dat
	$(GNUPLOT) plot_erf.gp

plots: $(PDF)

clean:
	rm -f $(EXES) $(DAT) $(PDF) $(TXT)

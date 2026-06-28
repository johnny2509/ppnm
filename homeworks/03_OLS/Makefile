CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -Wpedantic
GNUPLOT = gnuplot

.PHONY: all clean plots

EXE = main-hppA
DAT = thx_log.dat thx_fit.dat
PNG = thx.png

all: $(EXE) $(DAT) $(PNG)

$(EXE): main-hppA.cc lsfit.hpp matrix.hpp
	$(CXX) $(CXXFLAGS) main-hppA.cc -o $(EXE)

$(DAT): $(EXE) thx.dat
	./$(EXE)

$(PNG): plotA.gp thx_fit.dat
	$(GNUPLOT) plotA.gp

plots: $(PNG)

clean:
	rm -f $(EXE) $(DAT) $(PNG)

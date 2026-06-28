CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

.PHONY: all clean

EXE = mainA
TXT = rosenbrock.txt himmelblau.txt

all: $(EXE) $(TXT)

mainA: mainA.cc matrix.hpp min.hpp
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

$(TXT): $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(TXT)

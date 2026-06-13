CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

mainA: mainA.cc 
	$(CXX) $(CXXFLAGS) mainA.cc -o mainA

runA: mainA
	./mainA > outA.txt

outA.txt: mainA
	./mainA > outA.txt

plotA: outA.txt
	gnuplot plotA.gp

mainB: mainB.cc 
	$(CXX) $(CXXFLAGS) mainB.cc -o mainB

runB: mainB
	./mainB > outB.txt

outB.txt: mainB
	./mainB > outB.txt

plotB: outB.txt
	gnuplot plotB.gp

clean:
	rm -f mainA mainB outA.txt outB.txt ann.png annB.png derivativeB.png second_derivativeB.png anti_derivativeB.png
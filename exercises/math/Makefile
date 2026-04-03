CXX = c++
CXXFLAGS = -std=c++20 -O2 -Wall

Out.txt: main
	./main > Out.txt

main: main.o sfuns.o
	$(CXX) -o main main.o sfuns.o

main.o : sfuns.h main.cc
	$(CXX) $(CXXFLAGS) -o main.o -c main.cc

sfuns.o : sfuns.h sfuns.cc
	$(CXX) $(CXXFLAGS) -o sfuns.o -c sfuns.cc

clean:
	rm -f main *.o Out.txt

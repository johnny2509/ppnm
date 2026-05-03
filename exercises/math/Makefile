CXX = c++ # slight change from Chat GPT Instant 5.3
CXXFLAGS = -std=c++20 -O2 -Wall # slight change from Chat GPT Instant 5.3

Out.txt: main
	./main > Out.txt

main: main.o sfuns.o
	$(CXX) -o main main.o sfuns.o # slight change from Chat GPT Instant 5.3

main.o : sfuns.h main.cc
	$(CXX) $(CXXFLAGS) -o main.o -c main.cc

sfuns.o : sfuns.h sfuns.cc
	$(CXX) $(CXXFLAGS) -o sfuns.o -c sfuns.cc

clean:
	rm -f main *.o Out.txt # Chat GPT Instant 5.3

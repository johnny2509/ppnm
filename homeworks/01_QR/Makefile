CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -Wpedantic

.PHONY: all clean

EXES = main main2 main3 main4 mainB mainC

all: $(EXES) out.times.data print_statements.txt

main: main-hpp.cc
	$(CXX) $(CXXFLAGS) main-hpp.cc -o main

main2: main-hpp2.cc
	$(CXX) $(CXXFLAGS) main-hpp2.cc -o main2

main3: main-hpp3.cc
	$(CXX) $(CXXFLAGS) main-hpp3.cc -o main3

main4: main-hpp4.cc
	$(CXX) $(CXXFLAGS) main-hpp4.cc -o main4

mainB: main-hppB.cc
	$(CXX) $(CXXFLAGS) main-hppB.cc -o mainB

mainC: main-hppC.cc
	$(CXX) $(CXXFLAGS) main-hppC.cc -o mainC

print_statements.txt: $(EXES)
	> $@
	echo "=== Output from main ===" >> $@
	./main >> $@ 2>&1
	echo "\n=== Output from main2 ===" >> $@
	./main2 >> $@ 2>&1
	echo "\n=== Output from main3 ===" >> $@
	./main3 >> $@ 2>&1
	echo "\n=== Output from main4 ===" >> $@
	./main4 >> $@ 2>&1
	echo "\n=== Output from mainB ===" >> $@
	./mainB >> $@ 2>&1

out.times.data: mainC
	>$@
	for N in $$(seq 300 50 1500); do \
		./mainC -size $$N > /dev/null 2>&1; \
		/usr/bin/time -p -o .time.tmp ./mainC -size $$N > /dev/null 2>&1; \
		awk '/^real /{gsub(",", ".", $$2);  print "'$$N'", $$2}' .time.tmp >> $@ ; \
	done
	rm -f .time.tmp

clean:
	rm -f $(EXES) out.times.data print_statements.txt out err .time.tmp

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -Wpedantic

mainC: main-hppC.cc
	$(CXX) $(CXXFLAGS) main-hppC.cc -o mainC

out.times.data: mainC
	>$@
	for N in $$(seq 300 50 1500); do \
		./mainC -size $$N > /dev/null 2>&1; \
		/usr/bin/time -p -o .time.tmp ./mainC -size $$N > /dev/null 2>&1; \
		awk '/^real /{gsub(",", ".", $$2);  print "'$$N'", $$2}' .time.tmp >> $@ ; \
	done
	rm -f .time.tmp

clean:
	rm -f mainC out.times.data out err .time.tmp

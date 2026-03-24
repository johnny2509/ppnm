CXX = g++
CXXFLAGS = -std=c+17 -O2 -pthread
TIME = gtime -f "%C %e %U" -a -o out.times
N = 1e9

all: main out.times

main: harm_threads.cc
	$(CXX) $(CXXFLAGS) $< -o $@

out.times: main
	> $@
	>log.main
	for nthreads in 1 2 3 4 5 6 7 8; do \
		$(TIME) ./main -nthreads $$nthreads -nterms $(N) >>log.main ;\
	done

clean:
	rm -f main out.times

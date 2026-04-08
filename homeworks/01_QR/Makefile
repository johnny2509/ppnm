CXXFLAGS += -std=c++23 -I. -Wall -Wextra -Werror #-DLONG_DOUBLE
LDLIBS += -lstdc++ -lm

Out.txt : main-hpp main-h Makefile
	>$@
	echo "\nBoth interface and implementation in matrix.hpp\n" >>$@
	./$(word 1,$^) >> $@
	echo "\nInterface in .h, implementation in matrix.cc\n" >>$@
	./$(word 2,$^) >> $@

main-hpp.o : matrix.hpp
main-h.o : matrix.h
matrix.o : matrix.h
main-h : main-h.o matrix.o

clean:
	$(RM) [Oo]ut* main* *.o
test:
	echo $(findstring clang++,$(CXX)) 
	echo $(CXX)
	echo $(CXXFLAGS)

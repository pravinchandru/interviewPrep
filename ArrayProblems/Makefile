CC=g++

CXXFLAGS=-Wall -g -c -o $@

LDFLAGS=-l ncurses -o $@

DEPENDENCIES=ArrayProblems.o

# FINAL OUTPUTS
ArrayProblems: $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(DEPENDENCIES)

ArrayProblems.o: ArrayProblems.h ArrayProblems.cpp
	$(CC) $(CXXFLAGS) ArrayProblems.cpp


# CLEAN
clean:
	-rm ArrayProblems $(DEPENDENCIES)

CC=g++

CXXFLAGS=-Wall -g -c -o $@

LDFLAGS=-l ncurses -o $@

DEPENDENCIES= BitMathProblems.o

# FINAL OUTPUTS
BitMathProblems: $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(DEPENDENCIES)

# MODULES
BitMathProblems.o: BitMathProblems.h BitMathProblems.cpp
	$(CC) $(CXXFLAGS) BitMathProblems.cpp


# CLEAN
clean:
	-rm BitMathProblems $(DEPENDENCIES)

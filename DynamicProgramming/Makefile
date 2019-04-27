CC=g++

CXXFLAGS=-Wall -g -c -o $@

LDFLAGS=-l ncurses -o $@

DEPENDENCIES= DynamicProgramming.o

# FINAL OUTPUTS
DynamicProgramming: $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(DEPENDENCIES)

# MODULES
DynamicProgramming.o: DynamicProgramming.h DynamicProgramming.cpp
	$(CC) $(CXXFLAGS) DynamicProgramming.cpp


# CLEAN
clean:
	-rm DynamicProgramming $(DEPENDENCIES)

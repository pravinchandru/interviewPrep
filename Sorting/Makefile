CC=g++

CXXFLAGS=-Wall -g -c -o $@

LDFLAGS=-l ncurses -o $@

DEPENDENCIES=Sorting.o

# FINAL OUTPUTS
Sorting: $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(DEPENDENCIES)

# MODULES
Sorting.o: Sorting.h Sorting.cpp
	$(CC) $(CXXFLAGS) Sorting.cpp


# CLEAN
clean:
	-rm Sorting $(DEPENDENCIES)

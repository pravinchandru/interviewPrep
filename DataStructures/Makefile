CC=g++

CXXFLAGS=-Wall -g -c -o $@

LDFLAGS=-l ncurses -o $@

DEPENDENCIES= DataStructures.o

# FINAL OUTPUTS
DataStructures: $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(DEPENDENCIES)

# MODULES
DataStructures.o: DataStructures.h DataStructures.cpp
	$(CC) $(CXXFLAGS) DataStructures.cpp


# CLEAN
clean:
	-rm DataStructures $(DEPENDENCIES)

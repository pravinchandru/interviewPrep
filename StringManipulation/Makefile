CC=g++

CXXFLAGS=-Wall -g -c -o $@

LDFLAGS=-l ncurses -o $@

DEPENDENCIES=StringManipulation.o

# FINAL OUTPUTS
StringManipulation: $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(DEPENDENCIES)

# MODULES
StringManipulation.o: StringManipulation.h StringManipulation.cpp
	$(CC) $(CXXFLAGS) StringManipulation.cpp


# CLEAN
clean:
	-rm StringManipulation $(DEPENDENCIES)

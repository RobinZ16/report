######################################################################
# Makefile
#
# Created by Zhiming Wang on 07/29/2014.
# --------------------------------------
# This makefile is intended for Zhiming's OS X 10.9.4 at
# zmwang.stanford.edu. Compliler and flags need to be modified for
# different systems.
######################################################################

# compiler
CXX = clang++
# generic compiler flags and preprocessor flags
CXXFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -O2 \
-I/usr/local/include/flint/ -I/opt/local/include
# linker flags
LDFLAGS = -fno-common -L/usr/local/lib -L/opt/local/lib -lflint -lmpfr -lgmp -lpthread

SOURCES = search.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGETS = search

$(TARGETS) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	@rm -f $(TARGETS) $(OBJECTS) core

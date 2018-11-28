include src/Sources.mk

OBJECTS = $(SOURCES:.cpp=.o)

#CXX = g++
CXXFLAGS = -Wall -std=c++14
DEFINES =
INCLUDE_DIRS = -Isrc/
CPPFLAGS = $(DEFINES) $(INCLUDE_DIRS)
LDFLAGS =
LIBLINKAGE = -lncurses

# Various output files for debugging as well as release versions.
OUT = bin/term-fun

# Command line arg parse
ifeq ($(debug), y)
	CXXFLAGS += -g -O0
	DEFINES += -DDEBUG_ON
endif

%.o: %.cpp curses.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@ 

$(OUT): $(OBJECTS)
	-mkdir bin
	$(CXX) $(LDFLAGS) $^ -o $@ $(LIBLINKAGE)

.PHONY: build
build: $(OUT)

.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(OUT) bin
	

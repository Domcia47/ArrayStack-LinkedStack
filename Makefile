CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

# Lista plików źródłowych i docelowych
SOURCES := Stack.cpp Generator.cpp ONP.cpp
EXECUTABLES := Stack.x Generator.x ONP.x

# Pliki obiektowe
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean make

all: $(EXECUTABLES)

ONP.x: ONP.o ArrayStack.hpp LinkedStack.hpp
Stack.x: Stack.o ArrayStack.hpp LinkedStack.hpp
Generator.x: Generator.o 

%.o: %.cpp ArrayStack.hpp LinkedStack.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

make: $(OBJECTS) $(EXECUTABLES)

clean:
	$(RM) $(EXECUTABLES) $(OBJECTS)


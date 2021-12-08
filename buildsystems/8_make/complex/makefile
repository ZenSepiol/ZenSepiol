# define clang as standard c++ compiler
CXX = clang++

# use no compiler flags
CXXFLAGS = -g
 
all: main
 
main: main.o shape.o line.o
	$(CXX) $(CXXFLAGS) -o main main.o shape.o line.o

main.o: main.cpp shape.h line.h
	$(CXX) $(CXXFLAGS) -c main.cpp

line.o: line.cpp line.h
	$(CXX) $(CXXFLAGS) -c line.cpp

shape.o: shape.cpp shape.h
	$(CXX) $(CXXFLAGS) -c shape.cpp

clean:
	$(RM) main main.o line.o shape.o

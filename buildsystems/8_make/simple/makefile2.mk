# define clang as standard c++ compiler
CXX = clang++

# use no compiler flags
CXXFLAGS = -g -Wall
 
all: main2
 
main2: main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp
 
clean:
	$(RM) main

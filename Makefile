CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

all: bin/testListArray bin/testListLinked

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListArray testListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h Node.h List.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListLinked testListLinked.cpp

clean:
	rm -rf *.o *.gch bin


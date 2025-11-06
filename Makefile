bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -std=c++17 -O2 -Wall -Wextra -o bin/testListArray testListArray.cpp ListArray.h

clean:
	rm -rf *.o *.gch bin

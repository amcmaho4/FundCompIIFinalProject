all: main

main:main.cpp propertyTree.h
	g++ main.cpp -o main
clean:
	rm *.o main


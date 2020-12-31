result = $(basename PWD)

all:
	g++ a.cpp -o $(shell basename $(CURDIR)).o; ./$(shell basename $(CURDIR)).o
debug:
	g++ -g a.cpp -o $(shell basename $(CURDIR)).o; ./$(shell basename $(CURDIR)).o


clean:
	rm *.o

FILE = main
CC = g++
C_FLAGS =  -O3 -o $(FILE)

all:run

build: $(FILE).cpp
	$(CC) $(FILE).cpp $(C_FLAGS)  

run: build 
	./$(FILE)
CXX = g++
OUT = main
SRC_FILE = main.cpp Record.cpp Patient.cpp
CXX_FLAGS = -Og -o $(OUT) -ggdb3

all:run

build: $(SRC_FILE)
	$(CXX) $(SRC_FILE) $(CXX_FLAGS)

run: build 
	./$(OUT)

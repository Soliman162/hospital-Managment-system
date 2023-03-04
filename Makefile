CXX = g++
OUT = main
SRC_FILE = main.cpp Record.cpp Patient.cpp
CXX_FLAGS = -O3 -o $(OUT)

all:run

build: $(SRC_FILE)
	$(CXX) $(SRC_FILE) $(CXX_FLAGS)

run: build 
	./$(OUT)

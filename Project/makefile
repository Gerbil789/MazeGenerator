CXX=g++
CXXFLAGS=-std=c++17 -Wall
LDFLAGS=`pkg-config --libs sfml-graphics sfml-window sfml-system`
PKG_CONFIG_EXISTS := $(shell command -v pkg-config 2> /dev/null)

SRC=main.cpp maze.cpp mazeGenerator.cpp mazeVisualizer.cpp depthFirstSearchGeneratingStrategy.cpp primsAlgorithmStrategy.cpp deadEndFillingStrategy.cpp depthFirstSearchSolvingStrategy.cpp
OBJ=

all: mazeGenerator

mazeGenerator: $(SRC)
ifdef PKG_CONFIG_EXISTS
	@if ! pkg-config --exists sfml-graphics sfml-window sfml-system; then \
		echo "Error: SFML library not found. Please install it before building the program."; \
		false; \
	fi
else
	$(error "pkg-config is not installed on the system. Please install it before building the program.")
endif
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f mazeGenerator

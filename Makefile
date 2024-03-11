CXX = g++
CXXFLAGS = -Iinclude -std=c++11 -Wall
LDFLAGS =
SRC = $(wildcard src/*.cpp src/**/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
EXEC = $(project_name)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

build/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(EXEC)

.PHONY: all clean

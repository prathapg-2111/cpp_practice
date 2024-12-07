# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Default target
all:
	$(CXX) $(CXXFLAGS) -o program1 $(FILE)
	./program1

# Clean target
clean:
	@echo "Cleaning up..."
	@del program1.exe

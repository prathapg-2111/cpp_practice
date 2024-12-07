# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Default target
all:
	$(CXX) $(CXXFLAGS) -o program1 ACCOUNT.cpp main.cpp Account.h Savings.cpp Savings.h Checking.cpp Checking.h Transaction.cpp Transaction.h
	./program1

# Clean target
clean:
	@echo "Cleaning up..."
	@del program1.exe

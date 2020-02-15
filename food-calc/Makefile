CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: main

main: main.o Meal.o
	$(CXX) $(CXXFLAGS) -o main main.o Meal.o

main.o: main.cpp Meal.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Meal.o: Meal.hpp

clean:
	rm main.o Meal.o main

# Environment 
MKDIR=mkdir
REMOVE_DIR=rm -r
OBJS = flappybird Bird.o Obstacle.o 
CXXFLAGS = -Wall -pedantic -g
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system


# all
all: 
	g++ -c Obstacle.cpp 
	g++ -c Bird.cpp 
	g++ -c main.cpp 
	g++ main.o $(CXXFLAGS) $(SFMLFLAGS) -o $(OBJS) 


# clean
clean: 
	rm -r *.o




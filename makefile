CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic -g
LINK.o=$(LINK.cc)

all: main

main: main.o Actor.o ActorFactory.o BattleMove.o BattleMoveFactory.o CommandManager.o Battle.o functions.o Game.o

clean:
	rm -f *.o main
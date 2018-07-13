##################################################################################
# File: Makefile
# Author: Ju Hye An
# Date: 11/21/2016
# Description: A makefile that creates fantasy combat game program for Assignment4
##################################################################################

JuAn_Assignment4: main.o Game.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Queue.o Stack.o
	g++ main.o Game.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Queue.o Stack.o -o JuAn_Assignment4

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -c Creature.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

Stack.o: Stack.cpp Stack.hpp
	g++ -c Stack.cpp

clean:
	rm -f a.out *.o *~

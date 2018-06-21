##################################################################################
# File: Makefile
# Author: Ju Hye An
# Date: 12/5/2016
# Description: A makefile that creates Final Project program
##################################################################################

JuAn_finalProject: main.o Game.o Space.o TheHogwartsExpress.o TheGreatHall.o ForbiddenForrest.o HospitalWing.o GryffindorCommonRoom.o DefenseAgainsttheDarkArts.o HeadmastersOffice.o Item.o Inventory.o Player.o QuidditchPitch.o
	g++ main.o Game.o Space.o TheHogwartsExpress.o TheGreatHall.o ForbiddenForrest.o HospitalWing.o GryffindorCommonRoom.o DefenseAgainsttheDarkArts.o HeadmastersOffice.o Item.o Inventory.o Player.o QuidditchPitch.o -o JuAn_finalProject

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

TheHogwartsExpress.o: TheHogwartsExpress.cpp TheHogwartsExpress.hpp
	g++ -c TheHogwartsExpress.cpp

TheGreatHall.o: TheGreatHall.cpp TheGreatHall.hpp
	g++ -c TheGreatHall.cpp

ForbiddenForrest.o: ForbiddenForrest.cpp ForbiddenForrest.hpp
	g++ -c ForbiddenForrest.cpp

HospitalWing.o: HospitalWing.cpp HospitalWing.hpp
	g++ -c HospitalWing.cpp

GryffindorCommonRoom.o: GryffindorCommonRoom.cpp GryffindorCommonRoom.hpp
	g++ -c GryffindorCommonRoom.cpp

DefenseAgainsttheDarkArts.o: DefenseAgainsttheDarkArts.cpp DefenseAgainsttheDarkArts.hpp
	g++ -c DefenseAgainsttheDarkArts.cpp

HeadmastersOffice.o: HeadmastersOffice.cpp HeadmastersOffice.hpp
	g++ -c HeadmastersOffice.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Inventory.o: Inventory.cpp Inventory.hpp
	g++ -c Inventory.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

QuidditchPitch.o: QuidditchPitch.cpp QuidditchPitch.hpp
	g++ -c QuidditchPitch.cpp

clean:
	rm -f a.out *.o *~

#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using std::string;
using namespace std;

class Player
{
public:
	int attack, damage, armor, health; //stats
	string weapon, name, gender, race, specialty;//string variables
	int position[2]; //grid position
};


class Fighter : public Player
{
public:
	Fighter() {
	attack = 20;
	damage;
	armor = 26;
	health; //stats
	}
};
class Wizard : public Player
{
public:
	Wizard() {

	int attack, damage = 10 + ((rand ()% 10) + 5), armor = 18, health; //stats
	}
};
class Rogue : public Player
{
public:
	Rogue() {

	int attack, damage = 5 + ((rand()% 5) + 3), armor = 20, health; //stats
	}
};
class Ranger : public Player
{
public:
	Ranger() {
	int attack, damage = (14 + ((rand()% 10) + 1)) * 2, armor = 21, health; //stats
	}
};

Player *player1 = new Player; //creates player2 object
Player *player2 = new Player; //creates player2 object

#pragma once
#include <string>
#include <iostream>


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
	int attack = 20, damage, armor = 26, health; //stats
};
class Wizard : public Player
{
	int attack, damage = 10 + ((rand % 10) + 5), armor = 18, health; //stats
};
class Rogue : public Player
{
	int attack, damage = 5 + ((rand% 5) + 3), armor = 20, health; //stats
};
class Ranger : public Player
{
	int attack, damage = (14 + ((rand% 10) + 1)) * 2, armor = 21, health; //stats
};

Player *player1 = new Player; //creates player2 object
Player *player2 = new Player; //creates player2 object

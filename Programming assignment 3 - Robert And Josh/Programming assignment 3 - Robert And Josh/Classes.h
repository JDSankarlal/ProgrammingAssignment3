#pragma once
#include <string>

using std::string;

class Player
{
public:
	int attack, damage, armor, health; //stats
	string weapon, name, gender, race, specialty;//string variables
	int position[2]; //grid position
};
class Fighter : public Player
{

};
class Wizard : public Player
{

};
class Rogue : public Player
{

};
class Ranger : public Player
{

};
Player *player1 = new Player; //creates player1 object
Player *player2 = new Player; //creates player2 object

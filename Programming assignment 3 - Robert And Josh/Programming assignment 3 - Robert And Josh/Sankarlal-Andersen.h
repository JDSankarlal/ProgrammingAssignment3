//Josh Sankarlal - 100658457
//Robert Andersen - 100658473
//Programming assignment 3

#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using std::string;
using namespace std;

int turn = 1;
bool stillPlaying = true;

class Player
{
public:
	int attack, damage, armor, health; //stats
	string weapon, name, gender, race, specialty,specialOne, specialTwo;//string variables
	int position[2]; //grid position

};

class Fighter : public Player
{
public:
	Fighter() {
	attack = 20;
	damage=20;
	armor = 26;
	health=100; //stats
	}
	
};
class Wizard : public Player
{
public:
	Wizard() {
		attack = 10;
		damage = 10 + ((rand() % 10) + 5);  
		armor = 18; 
		health = 100; //stats
	}
};
class Rogue : public Player
{
public:
	Rogue() {
		attack = 10; 
		damage = 5 + ((rand() % 5) + 3);  
		armor = 20;  
		health=100; //stats
	}
};
class Ranger : public Player
{
public:
	Ranger() {
		attack=10; 
		damage = (14 + ((rand() % 10) + 1)) * 2;
		armor = 21; 
		health =100; //stats
	}
};




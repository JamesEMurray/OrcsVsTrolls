#pragma once

//Project Structure:
//Troll -> Enemy OR Player -> main.cpp
//Troll.h must be included in: Troll.cpp, Player.h, Enemy.h, main.cpp

class Troll {
	//Private Variables
	int health;
	int mDmg; //melee damage
	int rDmg; //ranged damage
	int shieldVal; //how much damage is prevented by taking the "Block" Action
	
	//Private Subclasses
	enum TROLL_TROOP_TYPE { BRUTE, THICKSKIN, ROCK_TOSSER }; //Note: Name of troop type has distinct letter for visual representation
	TROLL_TROOP_TYPE trollTroopType;

public:
	const short trollStartingUnits = 3;
};
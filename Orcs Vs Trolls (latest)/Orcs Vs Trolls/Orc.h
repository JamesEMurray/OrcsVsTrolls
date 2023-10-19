#pragma once

//Project Structure:
//Orc -> Enemy OR Player -> main.cpp
//Orc.h must be included in: Orc.cpp, Player.h, Enemy.h, main.cpp

class Orc {
	//Private Variables
	int health;
	int mDmg; //melee damage
	int rDmg; //ranged damage
	int shieldVal; //how much damage is prevented by taking the "Block" Action
	
	//Private Subclasses
	enum ORC_TROOP_TYPE { ORC, URUKHAI, X_BOW }; //Note: Name of troop type has distinct letter for visual representation
	ORC_TROOP_TYPE orcTroopType;

public:
	//Constructor
	Orc();

	const short orcStartingUnits = 5;
};
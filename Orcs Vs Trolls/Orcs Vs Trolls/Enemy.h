#pragma once

//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Troll.h"
#include "Orc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Enemy {
	//Private Variables

	//Private Functions
	void orcInit();
	void trollInit();

	//Private Subclasses
	enum ENEMY_ARMY_TYPE {ORCS, TROLLS};
	ENEMY_ARMY_TYPE armyType;

	//Constructor
	void EnemyArmyConstructor(ENEMY_ARMY_TYPE &armyType);

public:
	int numUnits;
};
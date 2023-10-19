#pragma once

//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Troll.h"
#include "Orc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Enemy {
	//Private Variables
	Orc** orcArmy[5];
	Troll** trollArmy[5];

	//Private Functions
	void orcInit();
	void trollInit();
	void selectAction(); //random select of action for each enemy unit

	//Private Subclasses
	enum ENEMY_ARMY_TYPE {ORCS, TROLLS};
	ENEMY_ARMY_TYPE armyType;
	enum ENEMY_ACTION { MELEE_ATK, RANGED_ATK, SHIELD };
	ENEMY_ACTION enemyAction;

	//Constructor
	void EnemyArmyConstructor(ENEMY_ARMY_TYPE &armyType);

public:
	int numUnits;
};
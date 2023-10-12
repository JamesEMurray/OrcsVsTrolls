#pragma once

//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Troll.h"
#include "Orc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Player {
	//Private Variables

	//Private Functions
	void orcInit();
	void trollInit();

	//Private Subclasses
	enum PLAYER_ARMY_TYPE { ORCS, TROLLS };
	PLAYER_ARMY_TYPE armyType;

	//Constructor
	void PlayerArmyConstructor(PLAYER_ARMY_TYPE &armyType);
public:
	int numUnits;
};
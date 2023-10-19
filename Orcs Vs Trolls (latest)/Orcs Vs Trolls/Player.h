#pragma once

//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Troll.h"
#include "Orc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Player {
	//Private Variables
	Orc** orcArmy[5];
	Troll** trollArmy[5];
	int actionChoice[5] = {}; //5 is largest possible army size | Note: cannot use a class variable for declaring array size

	//Private Functions
	void orcInit(Orc** &orcArmy);
	void trollInit(Troll** &trollArmy);
	void playerAction();
	void selectAction();
	void outputActionKey();
	void playerTurnMsg();
	void confirmActionChoice();
	void DmgCalc();

	//Private Subclasses
	enum PLAYER_ARMY_TYPE { ORCS, TROLLS };
	PLAYER_ARMY_TYPE armyType;
	enum CHOSEN_ACTION { MELEE_ATK, RANGED_ATK, SHIELD };
	CHOSEN_ACTION chosenAction;
	enum PLAYER_TURN_PHASE {START_TURN, END_TURN};
	PLAYER_TURN_PHASE playerTurnPhase;

	//Constructor
	void PlayerArmyConstructor(PLAYER_ARMY_TYPE &armyType);
public:
	const int largestPossibleArmySize = 5;
	int numUnits;

	//Public Functions
	void playerUpdate();
	
};
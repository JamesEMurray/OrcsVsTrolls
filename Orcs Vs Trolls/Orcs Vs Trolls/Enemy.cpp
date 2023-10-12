//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include "Enemy.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Enemy::EnemyArmyConstructor(ENEMY_ARMY_TYPE &armyType)
{
	switch (armyType)
	{
	case ORCS:
		orcInit();
		break;
	case TROLLS:
		trollInit();
		break;
	default:
		std::cout << "Error: An army type must be selected\n";
		numUnits = 0;
	}
}

void Enemy::orcInit() {
	Orc OrcUnit1;
	Orc OrcUnit2;
	Orc OrcUnit3;
	Orc OrcUnit4;
	Orc OrcUnit5;
	numUnits = OrcUnit1.orcStartingUnits; //awkward workaround for keeping startingUnits part of orc class and it having to be related to an object
}

void Enemy::trollInit() {
	Troll TrollUnit1;
	Troll TrollUnit2;
	Troll TrollUnit3;
	numUnits = TrollUnit1.trollStartingUnits; //awkward workaround for keeping startingUnits part of troll class and it having to be related to an object
}
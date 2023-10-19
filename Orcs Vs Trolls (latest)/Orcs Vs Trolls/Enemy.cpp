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
	Orc* OrcUnit1 = new Orc(); OrcUnit1->Orc::Orc();
	Orc* OrcUnit2 = new Orc(); OrcUnit2->Orc::Orc();
	Orc* OrcUnit3 = new Orc(); OrcUnit3->Orc::Orc();
	Orc* OrcUnit4 = new Orc(); OrcUnit4->Orc::Orc();
	Orc* OrcUnit5 = new Orc(); OrcUnit5->Orc::Orc();
	Orc** orcArmy = new Orc * [5] { OrcUnit1, OrcUnit2, OrcUnit3, OrcUnit4, OrcUnit5 };
	numUnits = OrcUnit1->orcStartingUnits; //awkward workaround for keeping startingUnits part of orc class and it having to be related to an object
}

void Enemy::trollInit() {
	Troll* TrollUnit1 = new Troll(); TrollUnit1->Troll::Troll();
	Troll* TrollUnit2 = new Troll(); TrollUnit2->Troll::Troll();
	Troll* TrollUnit3 = new Troll(); TrollUnit3->Troll::Troll();
	Troll** trollArmy = new Troll * [5] { TrollUnit1, TrollUnit2, TrollUnit3}; //two empty slots in the array to facilitate selectAction function (Don't reduce to size 3)
	numUnits = TrollUnit1->trollStartingUnits; //awkward workaround for keeping startingUnits part of troll class and it having to be related to an object
}

//void Enemy::selectAction() {random action selection (utilising: srand nullptr etc.) rand in range of 0-3 aka. meleeAtk, rangedAtk and shield}
void Enemy::selectAction() {
	std::cout << "Random Action Selection Procedure\n";
}
//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include "Orc.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Orc::Orc()
{
	switch (orcTroopType)
	{
	case ORC:
		health = 6;
		mDmg = 3; //melee damage
		rDmg = 1; //ranged damage
		shieldVal = 4; //how much damage is prevented by taking the "Block" Action
		break;
	case URUKHAI:
		health = 12;
		mDmg = 5; //melee damage
		rDmg = 1; //ranged damage
		shieldVal = 1; //how much damage is prevented by taking the "Block" Action
		break;
	case X_BOW:
		health = 6;
		mDmg = 1; //melee damage
		rDmg = 3; //ranged damage
		shieldVal = 2; //how much damage is prevented by taking the "Block" Action
		break;
	default:
		std::cout << "Error: No unit type selected\n";
	}
}
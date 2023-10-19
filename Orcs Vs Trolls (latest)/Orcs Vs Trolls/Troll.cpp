//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include "Troll.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Troll::Troll()
{
	switch (trollTroopType)
	{
	case BRUTE:
		health = 8;
		mDmg = 3; //melee damage
		rDmg = 1; //ranged damage
		shieldVal = 4; //how much damage is prevented by taking the "Block" Action
		break;
	case THICKSKIN:
		health = 15;
		mDmg = 5; //melee damage
		rDmg = 1; //ranged damage
		shieldVal = 1; //how much damage is prevented by taking the "Block" Action
		break;
	case ROCK_TOSSER:
		health = 8;
		mDmg = 1; //melee damage
		rDmg = 4; //ranged damage
		shieldVal = 2; //how much damage is prevented by taking the "Block" Action
		break;
	default:
		std::cout << "Error: No unit type selected\n";
	}
}
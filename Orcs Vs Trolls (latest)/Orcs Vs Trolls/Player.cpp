//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include "Player.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Player::PlayerArmyConstructor(PLAYER_ARMY_TYPE &armyType)
{
	switch (armyType)
	{
	case ORCS:
		orcInit(orcArmy[5]);
		break;
	case TROLLS:
		trollInit(trollArmy[5]);
		break;
	default:
		std::cout << "Error: An army type must be selected\n";
		numUnits = 0;
	}
}

void Player::orcInit(Orc** &orcArmy) {
	Orc* OrcUnit1 = new Orc(); OrcUnit1->Orc::Orc();
	Orc* OrcUnit2 = new Orc(); OrcUnit2->Orc::Orc();
	Orc* OrcUnit3 = new Orc(); OrcUnit3->Orc::Orc();
	Orc* OrcUnit4 = new Orc(); OrcUnit4->Orc::Orc();
	Orc* OrcUnit5 = new Orc(); OrcUnit5->Orc::Orc();
	orcArmy = new Orc * [5] { OrcUnit1, OrcUnit2, OrcUnit3, OrcUnit4, OrcUnit5 };
	numUnits = OrcUnit1->orcStartingUnits; //awkward workaround for keeping startingUnits part of orc class and it having to be related to an object
}

void Player::trollInit(Troll** &trollArmy) {
	Troll* TrollUnit1 = new Troll(); TrollUnit1->Troll::Troll();
	Troll* TrollUnit2 = new Troll(); TrollUnit2->Troll::Troll();
	Troll* TrollUnit3 = new Troll(); TrollUnit3->Troll::Troll();
	trollArmy = new Troll * [5] { TrollUnit1, TrollUnit2, TrollUnit3}; //two empty slots in the array to facilitate selectAction function (Don't reduce to size 3)
	numUnits = TrollUnit1->trollStartingUnits; //awkward workaround for keeping startingUnits part of troll class and it having to be related to an object
}

void Player::playerAction() {

	selectAction();

	switch (chosenAction)
	{
	case MELEE_ATK:
		std::cout << "temp msg: melee attack registered\n";
		break;

	case RANGED_ATK:
		std::cout << "temp msg: ranged attack registered\n";
		break;

	case SHIELD:
		std::cout << "temp msg: shield action registered\n";
		break;

	default:
		std::cout << "Error: You need to input an intended action.\n";
	}
}

void Player::selectAction() {
	if (armyType == ORCS)
	{
		for (short index = 0; index < 5; index++) //OrcUnit1->orcStartingUnits = 5
		{
			std::cout << "Please Select the type of action you would like " << orcArmy[index] << " to perform\n";
			outputActionKey();
			std::cin >> actionChoice[index];
		}
	}
	else if (armyType == TROLLS)
	{
		for (short index = 0; index < 3; index++) //TrollUnit1->trollStartingUnits = 3
		{
			std::cout << "Please Select the type of action you would like " << trollArmy[index] << " to perform\n";
			outputActionKey();
			std::cin >> actionChoice[index];
		}
	}
}

void Player::outputActionKey() {
	std::cout << "Melee Attack: 1\nRanged Attack: 2\nShield: 3\n";
}

void Player::playerTurnMsg() {
	if (playerTurnPhase == START_TURN)
	{
		std::cout << "~PLAYER TURN~\n";
	}
	else if (playerTurnPhase == END_TURN)
	{
		std::cout << "~END TURN~\n";
	}
}

void Player::confirmActionChoice() {
	//Local Variables
	bool actionsConfirmed = false;
	char yes_no;

	switch (armyType)
	{
	case Player::ORCS:
		for (short index = 0; index < largestPossibleArmySize; index++)
		{
			std::cout << "Unit " << (index + 1) << ": " << orcArmy[index] << " " << actionChoice[index] << "\n"; //Unit 1: URUKAI MELEE_ATK (Example of intended output)
		}
		std::cout << "Are you happy with your action choice? Y/N\n";
		std::cin >> yes_no;
		if (yes_no == 'Y' || yes_no == 'y')
		{
			actionsConfirmed = true;
		}
		else
		{
			std::cout << "Feature Yet To Be Implemented. Please select yes instead.\n";
			confirmActionChoice();
		}
		break;
	case Player::TROLLS:
		for (short index = 0; index < (largestPossibleArmySize-2); index++) //-2 because Troll armies are two units smaller for game balancing
		{
			std::cout << "Unit " << (index + 1) << ": " << trollArmy[index] << " " << actionChoice[index] << "\n"; //Unit 1: THICKSKIN RANGED_ATK (Example of intended output)
		}
		std::cout << "Are you happy with your action choice? Y/N\n";
		std::cin >> yes_no;
		if (yes_no == 'Y' || yes_no == 'y')
		{
			actionsConfirmed = true;
		}
		else
		{
			std::cout << "Feature Yet To Be Implemented. Please select yes instead.\n";
			confirmActionChoice();
		}
		break;
	default:
		std::cout << "Error: Army Type not selected.\n";
		break;
	}
	
}

void Player::DmgCalc() {
	//Objects not passing properly, evne after being created using new method. Don't understand why, but cannot progress with damage calculation using polymorphism because of this...
}

// Handle Players Turn:
/// Indicate to Player that it is their turn
/// Take input for actions of each unit
/// Confirm Action choice with Player
/// Act upon actions selected (Damage Calculation)
/// End Turn Button
void Player::playerUpdate() {
	playerTurnMsg();
	playerAction(); //Handles selection and storage of players choice of action for each of their units
	confirmActionChoice();
	DmgCalc(); //Damage Calculation
	playerTurnPhase = END_TURN;
	playerTurnMsg();
}
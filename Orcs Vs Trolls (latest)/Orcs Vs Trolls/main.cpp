//Name: James Murray C00272116
//Date: 10/10/23
//Programme Purpose: Create a Turn Based Game where you can play as an Orc or Troll. For specifics See: GDD
//Known Bugs/Errors: 
// 1) When User presses a non-number key on the StartGame Menu, the game loops indefinitely (BUG)
// 2) Objects of type Orc and Troll are flagged as unidentified if used in other functions, when they are clearly identified [going out of scope, even when on the heap..?] (ERROR)

//#includes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include "Troll.h"
#include "Orc.h"
#include "Enemy.h"
#include "Player.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Project Structure - in relation to main.cpp:
// main.cpp: Handles setup(), run() and update()
// setup(): Menu with Start Game Option, sets the GAMESTATE to START_GAME
// run(): Setup Functions, Game object creation
// update(): Prompt Player Input, adjust gamestate based on player input, output feedback to player

//Core Function Declarations
void setup(enum GAMESTATE &gamestate);
void run(enum GAMESTATE &gamestate);
void update(enum GAMESTATE &gamestate);

//Sub-Function Declarations
void generateTerrain();
void printTerrainKey();
void generateRow(std::string &currentRow, short &srandGenerationCount);
char generateTile(short &srandGenerationCount);
void askIfHappy(bool& GenSucces);//checks if user is happy with the current game board or if they wish to generate a random new one

//Global Variables
enum GAMESTATE { START_GAME = 0, PLAYING = 1, GAME_OVER = 2 };
//Initialise Armies
Enemy enemyArmy;
Player playerArmy;

int main()
{
	GAMESTATE gamestate;

	setup(gamestate);

	if (gamestate == START_GAME)
	{
		run(gamestate);
	}
	
	while (gamestate == PLAYING)
	{
		update(gamestate);
	}

	return 0;
}

void setup(enum GAMESTATE &gamestate) {
	//Local Variables
	bool beginGame = false;

	while (beginGame == false)
	{
		std::cout << "When you are ready to begin playing, Press 1\n";
		std::cin >> beginGame; //1 represents true | Technically pressing any number other than 0 will result in a true state

		if (beginGame == true)
		{
			gamestate = START_GAME;
		}
		else
		{
			std::cout << "That's a shame. Whenever you are ready to play Orcs Vs Trolls come back and Press 1\n";
		}
	}
}

void run(enum GAMESTATE &gamestate) {
	//Local Variables
	bool happyWithTerrainGeneration = false;

	while (happyWithTerrainGeneration == false)
	{
		generateTerrain();
		askIfHappy(happyWithTerrainGeneration);
	}
	gamestate = PLAYING;
}

void update(enum GAMESTATE &gamestate) {
	//Local Variables
	Player player; //to allow player function calls
	Enemy enemy; //to allow enemy function calls

	player.playerUpdate();

	//if a team is dead, end the game
	if (enemyArmy.numUnits == 0 || playerArmy.numUnits == 0)
	{
		gamestate = GAME_OVER;
	}
}

void generateTerrain() {
	//Local Variables
	short srandGenerationCount = 0;
	std::string row1; std::string row2; std::string row3; std::string row4; std::string row5; std::string row6;

	generateRow(row1, srandGenerationCount);
	generateRow(row2, srandGenerationCount);
	generateRow(row3, srandGenerationCount);
	generateRow(row4, srandGenerationCount);
	generateRow(row5, srandGenerationCount);
	generateRow(row6, srandGenerationCount);

	std::string grid[6] = { row1, row2, row3, row4, row5, row6 };

	for (short index = 0; index < 6; index++)
	{
		std::cout << grid[index];
	}

	printTerrainKey();
}

void generateRow(std::string &currentRow, short &srandGenerationCount) {
	//Local Variables
	const short rowSize = 20; //x component of grid
	char currentTile;

	for (short tileCount = 0; tileCount < rowSize; tileCount++)
	{
		currentTile = generateTile(srandGenerationCount);
		currentRow += currentTile;
		srandGenerationCount++;
	}

	currentRow += "\n"; //To move to next line of the grid
}

char generateTile(short &srandGenerationCount) {
	//Local Variables
	char tile;
	int tileVal;
	enum TILE_TYPE { WATER, GRASS, MOUNTAIN };
	
	std::srand(time(nullptr) + srandGenerationCount + rand()); //generates a random seed based on current time

	tileVal = rand() %3; //random number between 0-2 (3 options)
	TILE_TYPE tileType = static_cast<TILE_TYPE>(tileVal); //So that enum names can be used rather than numbers in following switch()

	switch (tileType)
	{
	case WATER:
		tile = '~';
		break;
	case GRASS:
		tile = '#';
		break;
	case MOUNTAIN:
		tile = '^';
		break;
	default:
		tile = '_'; //Blank Tile | Note: If this occurs, there has been an error
	}
	
	return tile;
}

void printTerrainKey() {
	std::string waterKey = "~ = Water\n";
	std::string grassKey = "# = Grass\n";
	std::string mountainKey = "^ = Mountain\n";

	std::cout << waterKey << grassKey << mountainKey; //So that players know what each symbol represents on the game board
}

void askIfHappy(bool &GenSuccess) {
	//Local variables
	char yesORno;
	std::cout << "Generate New Gameboard? Y/N\n";
	std::cin >> yesORno;

	if (yesORno != 'y' && yesORno != 'Y')
	{
		GenSuccess = true;
	}
}
#pragma once

#include "Room.h"
#include "Player.h"

class Game
{
private:
	bool playerWon = false;
	bool playerQuit = false;

	Player* m_player;

	//1st floor rooms
	Room* m_playersRoom;
	Room* m_upperHall;
	Room* m_parentsRoom;
	Room* m_bathroom;

	//Main floor rooms
	Room* m_mainHall;
	Room* m_livingRoom;
	Room* m_kitchen;
	Room* m_garage;
	Room* m_mainYard;
	Room* m_backYard;

	//Basement rooms
	Room* m_basement;

	void WelcomePlayer() const;
	void CheckPlayerWon();

public:
	Game();

	virtual ~Game();

	void Initialize();

	void Run();

	void Finalize();
};

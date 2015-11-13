#pragma once

#include "Room.h"
#include "Player.h"

class Game
{
private:
	bool playerWon = false;
	bool playerQuit = false;

	Player* m_player;
	Room* m_room;

	void WelcomePlayer() const;

public:
	Game();

	virtual ~Game();

	void Initialize();

	void Run();

	void Finalize();
};

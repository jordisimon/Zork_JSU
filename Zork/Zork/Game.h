#pragma once

#include <vector>

#include "Room.h"
#include "Player.h"

class Game
{
private:
	bool playerWon = false;
	bool playerQuit = false;

	Player* m_player;

	std::vector<Room*> m_rooms;
	std::vector<Item*> m_items;

	void WelcomePlayer() const;
	void CheckPlayerWon();

public:
	Game();

	virtual ~Game();

	void Initialize();

	void Run();

	void Finalize();
};

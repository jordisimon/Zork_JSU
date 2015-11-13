#pragma once

#include <string>
#include <vector>
#include <map>

#include "Room.h"
#include "Player.h"
#include "Command.h"

class Game
{
private:
	bool playerWon = false;
	bool playerQuit = false;

	Player* m_player;

	using CommandsMap = std::map<std::string, Command*>;
	CommandsMap m_commands; //search purposes

	std::vector<Command*> m_commandVector; //clean purposes
	std::vector<Room*> m_rooms;
	std::vector<Item*> m_items;

	void WelcomePlayer() const;
	void ManageNewCommand(Command* command, const std::string& words);
	bool ParseCommand(const std::string& input) const;
	void CheckPlayerWon();

public:
	Game();

	virtual ~Game();

	void Initialize();

	void Run();

	void Finalize();
};

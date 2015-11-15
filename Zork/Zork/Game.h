#pragma once

#include <string>
#include <vector>
#include <map>

#include "Room.h"
#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "Command.h"

class Game
{
private:
	bool playerWon = false;
	bool playerQuit = false;

	Player* m_player;
	Room* m_winningRoom;

	using CommandsMap = std::map<std::string, Command*>;
	CommandsMap m_commands; //search purposes

	std::vector<Command*> m_commandVector; //clean purposes
	std::vector<Room*> m_rooms;
	std::vector<Item*> m_items;
	std::vector<Character*> m_characters;

	Room* CreateNewRoom(const std::string& name, const std::string& description);
	Item* CreateNewItem(const std::string& name, const std::string& description, bool pickable);
	void ManageNewCommand(Command* command, const std::string& words);

	void WelcomePlayer() const;
	void ParseCommand(const std::string& input) const;
	void CheckPlayerWon();

public:
	Game();

	virtual ~Game();

	void Initialize();

	void Run();

	void Finalize();
};

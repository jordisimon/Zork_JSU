#pragma once

#include "Command.h"

class CommandInventory : public Command
{
public:
	CommandInventory(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
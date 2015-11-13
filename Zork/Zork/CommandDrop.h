#pragma once

#include "Command.h"

class CommandDrop : public Command
{
public:
	CommandDrop(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

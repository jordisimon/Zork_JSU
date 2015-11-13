#pragma once

#include "Command.h"

class CommandPick : public Command
{
public:
	CommandPick(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

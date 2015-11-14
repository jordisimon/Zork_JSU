#pragma once

#include "Command.h"

class CommandUnlock : public Command
{
public:
	CommandUnlock(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
#pragma once

#include "Command.h"

class CommandQuit : public Command
{
public:
	CommandQuit(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
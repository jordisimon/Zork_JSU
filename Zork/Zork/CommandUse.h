#pragma once

#include "Command.h"

class CommandUse : public Command
{
public:
	CommandUse(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
#pragma once

#include "Command.h"

class CommandGoEast : public Command
{
public:
	CommandGoEast(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

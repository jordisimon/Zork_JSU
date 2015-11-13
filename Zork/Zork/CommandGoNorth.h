#pragma once

#include "Command.h"

class CommandGoNorth : public Command
{
public:
	CommandGoNorth(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

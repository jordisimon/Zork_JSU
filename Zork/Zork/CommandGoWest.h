#pragma once

#include "Command.h"

class CommandGoWest : public Command
{
public:
	CommandGoWest(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

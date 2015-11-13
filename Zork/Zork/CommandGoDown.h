#pragma once

#include "Command.h"

class CommandGoDown : public Command
{
public:
	CommandGoDown(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

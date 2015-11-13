#pragma once

#include "Command.h"

class CommandGoSouth : public Command
{
public:
	CommandGoSouth(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
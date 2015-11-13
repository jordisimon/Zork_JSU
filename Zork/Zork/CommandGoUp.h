#pragma once

#include "Command.h"

class CommandGoUp : public Command
{
public:
	CommandGoUp(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

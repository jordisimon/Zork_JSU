#pragma once

#include "Command.h"

class CommandExamine : public Command
{
public:
	CommandExamine(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};

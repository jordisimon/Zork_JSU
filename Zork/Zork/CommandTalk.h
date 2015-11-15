#pragma once

#include "Command.h"

class CommandTalk : public Command
{
public:
	CommandTalk(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
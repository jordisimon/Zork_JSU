#pragma once

#include "Command.h"

class CommandLook : public Command
{
public:
	CommandLook(Player* player) :
		Command(player)
	{}

	virtual void Execute(const std::vector<std::string>& commands);
};
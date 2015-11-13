#pragma once
#include <vector>

#include "Player.h"

class Command
{
protected:
	Player* m_player;

public:
	Command(Player* player) :
		m_player{ player }
	{}

	virtual void Execute(const std::vector<std::string>& commands) = 0;
};

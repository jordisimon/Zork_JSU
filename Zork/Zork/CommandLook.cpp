#include "stdafx.h"
#include "CommandLook.h"

void CommandLook::Execute(const std::vector<std::string>& commands)
{
	if (commands.size() > 1 && commands[1] == "me")
	{
		m_player->Describe();
	}
	else
	{
		m_player->Look();
	}
}

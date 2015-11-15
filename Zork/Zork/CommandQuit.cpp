#include "stdafx.h"
#include "CommandQuit.h"

void CommandQuit::Execute(const std::vector<std::string>& commands)
{
	m_player->Quit();
}

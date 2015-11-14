#include "stdafx.h"
#include "CommandInventory.h"

void CommandInventory::Execute(const std::vector<std::string>& commands)
{
	m_player->Inventory();
}

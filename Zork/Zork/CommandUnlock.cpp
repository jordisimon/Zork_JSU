#include "stdafx.h"
#include "CommandUnlock.h"

using namespace std;

void CommandUnlock::Execute(const std::vector<std::string>& commands)
{
	switch (commands.size())
	{
	case 3: //unlock direction X (assumming player didn't write "with")
		m_player->Unlock(commands[1], commands[2]);
		break;

	case 4: //unlock direction with X
		m_player->Unlock(commands[1], commands[3]);
		break;

	default:
		cout << "Unlock where with what?" << endl << endl;
	}
}

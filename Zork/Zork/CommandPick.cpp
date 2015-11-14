#include "stdafx.h"
#include "CommandPick.h"

using namespace std;

void CommandPick::Execute(const std::vector<std::string>& commands)
{
	switch (commands.size())
	{
	case 2: //pick X
		m_player->Pick(commands[1]);
		break;

	case 3: //pick X Y (assumming player didn't write "from")
		m_player->Pick(commands[1], commands[2]);
		break;

	case 4: //pick X from Y
		m_player->Pick(commands[1], commands[3]);
		break;

	default:
		cout << "Pick what?" << endl << endl;
	}
}

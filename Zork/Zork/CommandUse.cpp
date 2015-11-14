#include "stdafx.h"
#include "CommandUse.h"

using namespace std;

void CommandUse::Execute(const std::vector<std::string>& commands)
{
	switch (commands.size())
	{
	case 3: //use X Y
		m_player->Use(commands[1], commands[2]);
		break;

	case 4: //use X on Y, use X with Y
		m_player->Use(commands[1], commands[3]);
		break;

	default:
		cout << "Use what with what?" << endl << endl;
	}
}
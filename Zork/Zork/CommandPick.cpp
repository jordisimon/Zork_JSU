#include "stdafx.h"
#include "CommandPick.h"

using namespace std;

void CommandPick::Execute(const std::vector<std::string>& commands)
{
	if (commands.size() > 1)
	{
		m_player->Pick(commands[1]);
	}
	else
	{
		cout << "Pick what?" << endl << endl;
	}
}

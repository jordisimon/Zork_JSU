#include "stdafx.h"
#include "CommandExamine.h"

using namespace std;

void CommandExamine::Execute(const std::vector<std::string>& commands)
{
	if (commands.size() > 1)
	{
		m_player->Examine(commands[1]);
	}
	else
	{
		cout << "Examine what?" << endl << endl;
	}
}

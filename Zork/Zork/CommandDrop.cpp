#include "stdafx.h"
#include "CommandDrop.h"

using namespace std;

void CommandDrop::Execute(const std::vector<std::string>& commands)
{
	if (commands.size() > 1)
	{
		m_player->Drop(commands[1]);
	}
	else
	{
		cout << "Drop what?" << endl << endl;
	}
}

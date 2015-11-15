#include "stdafx.h"
#include "CommandTalk.h"

using namespace std;

void CommandTalk::Execute(const std::vector<std::string>& commands)
{
	switch (commands.size())
	{
	case 2: //talk X
		m_player->Talk(commands[1]);
		break;

	case 3: //talk to X
		m_player->Talk(commands[2]);
		break;

	default:
		cout << "Talk to who?" << endl << endl;
	}
}

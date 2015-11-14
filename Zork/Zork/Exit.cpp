#include "stdafx.h"
#include "Exit.h"

bool Exit::UnlockWith(Item* item)
{
	if (item == m_unlocksWith)
	{
		m_locked = false;
		return true;
	}
	else
	{
		return false;
	}
}

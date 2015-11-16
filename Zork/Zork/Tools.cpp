#include "stdafx.h"

#include <locale>
#include "Tools.h"

using namespace std;

void ToLowerCase(string& str)
{
	locale loc;
	for (string::size_type i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i], loc);
}
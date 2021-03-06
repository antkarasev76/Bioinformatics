// B Lab-3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string Pattern = "", revPattern = "";

	getline(std::cin, Pattern, '\n');
	revPattern = Pattern;

	int len_pat = Pattern.length();

	for (int i = 0; i < len_pat; i++)
	{
		if (Pattern[i] == 'A')
		{
			revPattern[i] = 'T';
		}
		else if (Pattern[i] == 'C')
		{
			revPattern[i] = 'G';
		}
		else if (Pattern[i] == 'G')
		{
			revPattern[i] = 'C';
		}
		else
		{
			revPattern[i] = 'A';
		}
	}

	std::reverse(revPattern.begin(), revPattern.end());

	std::cout << revPattern << std::endl;

	system("pause");
	return 0;
}


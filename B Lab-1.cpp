// B Lab-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	std::string Pattern = "", Genom = "";
	int len_pat = 0, len_gen = 0, k = 0, ch = 0, t = 0;

	getline(std::cin, Pattern, '\n');
	getline(std::cin, Genom, '\n');

	len_pat = Pattern.length();
	len_gen = Genom.length();

	for (int i = 0; i < len_gen - len_pat; i++)
	{
		ch = i;
		t = 0;
		for (int j = 0; j < len_pat; j++)
		{
			if (Pattern[j] != Genom[ch])
			{
				t = 1;
				break;
			}
			ch++;
		}
		if (t == 0)
		{
			k++;
		}
	}

	std::cout << k << std::endl;

	system("pause");
    return 0;
}


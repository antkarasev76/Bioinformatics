// B Lab-8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <fstream>
#include <vector>
#include <array>

int main()
{
	int control_mass = 0;

	std::cin >> control_mass;

	std::vector<int> mass_pept;

	mass_pept.push_back(57);
	mass_pept.push_back(71);
	mass_pept.push_back(87);
	mass_pept.push_back(97);
	mass_pept.push_back(99);
	mass_pept.push_back(101);
	mass_pept.push_back(103);
	mass_pept.push_back(113);
	mass_pept.push_back(114);
	mass_pept.push_back(115);
	mass_pept.push_back(128);
	mass_pept.push_back(129);
	mass_pept.push_back(131);
	mass_pept.push_back(137);
	mass_pept.push_back(147);
	mass_pept.push_back(156);
	mass_pept.push_back(163);
	mass_pept.push_back(186);

	std::map<int, unsigned long long int> count_pept;

	count_pept[0] = 1;

	for (int i = 57; i <= control_mass; ++i)
	{
		count_pept[i] = 0;
		for (int j = 0; j < 18; ++j)
		{
			auto k = count_pept.find(i - mass_pept[j]);
			if (k != count_pept.end())
			{
				count_pept[i] += count_pept[i - mass_pept[j]];
			}
		}
	}

	std::cout << count_pept[control_mass];

	system("pause");
	return 0;
}
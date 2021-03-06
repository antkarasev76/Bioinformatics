// B Lab-7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <fstream>
#include <vector>

int main()
{
	std::string pept = "", copy_pept = "", part = "";
	int sum = 0;

	getline(std::cin, pept, '\n');

	int len_pept = pept.length();

	std::map<char, int> mas_pept;
	std::vector<int> t_spec = { 0 };

	mas_pept['G'] = 57;
	mas_pept['A'] = 71;
	mas_pept['S'] = 87;
	mas_pept['P'] = 97;
	mas_pept['V'] = 99;
	mas_pept['T'] = 101;
	mas_pept['C'] = 103;
	mas_pept['I'] = 113;
	mas_pept['L'] = 113;
	mas_pept['N'] = 114;
	mas_pept['D'] = 115;
	mas_pept['K'] = 128;
	mas_pept['Q'] = 128;
	mas_pept['E'] = 129;
	mas_pept['M'] = 131;
	mas_pept['H'] = 137;
	mas_pept['F'] = 147;
	mas_pept['R'] = 156;
	mas_pept['Y'] = 163;
	mas_pept['W'] = 186;

	copy_pept = pept;
	copy_pept += pept;

	for (int k = 1; k < len_pept; k++)
	{
		for (int i = 0; i < len_pept; i++)
		{
			sum = 0;
			part = copy_pept.substr(i, k);
			for (int j = 0; j < k; j++)
			{
				sum += mas_pept[part[j]];
			}
			t_spec.push_back(sum);
		}
	}

	sum = 0;
	for (int i = 0; i < len_pept; i++)
	{
		sum += mas_pept[pept[i]];
	}
	t_spec.push_back(sum);

	sort(t_spec.begin(), t_spec.end());

	for (int i = 0; i < t_spec.size(); i++)
	{
		std::cout << t_spec[i] << " ";
	}

	system("pause");
	return 0;
}
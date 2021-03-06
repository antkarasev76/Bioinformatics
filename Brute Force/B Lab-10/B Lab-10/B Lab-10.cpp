// B Lab-10.cpp: определяет точку входа для консольного приложения.
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
#include <iterator>

std::map<char, int> mas_pept;

void createMasTable()
{
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
}

std::vector<int> CycloSpectrum(std::string peptide)
{
	std::string copy_pept = peptide, part = "";
	int sum = 0;

	int len_pept = copy_pept.length();

	std::vector<int> t_spec = { 0 };

	copy_pept += peptide;

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
		sum += mas_pept[peptide[i]];
	}
	t_spec.push_back(sum);

	sort(t_spec.begin(), t_spec.end());

	return t_spec;
}

int Score(std::vector<int>& sp_p, std::vector<int>& sp_t)
{
	int sum = 0;
	for (int i = 0; i < sp_t.size(); ++i)
	{
		if (std::find(sp_p.begin(), sp_p.end(), sp_t[i]) != sp_p.end())
		{
			if (sp_t[i] == sp_t[sp_t.size() - 1])
			{
				sum++;
				continue;
			}
			if (sp_t[i] == sp_t[i + 1])
			{
				int amount_t = std::count(sp_t.begin(), sp_t.end(), sp_t[i]);
				int amount_p = std::count(sp_p.begin(), sp_p.end(), sp_t[i]);

				if (amount_t <= amount_p)
				{
					sum += amount_t;
					i += amount_t - 1;
				}
				else
				{
					sum += amount_p;
					if (amount_p == 0)
					{
						continue;
					}
					i += amount_t - 1;
				}
			}
			else
			{
				sum++;
				continue;
			}
		}
	}
	return sum;
}

int main()
{
	createMasTable();

	std::string peptide = "";
	std::string source_sp = "";
	std::vector<int> spectrum_p, spectrum_t;
	int score = 0;

	std::getline(std::cin, peptide, '\n');
	std::getline(std::cin, source_sp);

	for (int i = 0; i < source_sp.size(); ++i)
	{
		if (isdigit(source_sp[i]))
		{
			int j = i;
			while (isdigit(source_sp[i]))
			{
				i++;
			}
			spectrum_p.push_back(atoi(source_sp.substr(j, i).c_str()));
		}
	}

	spectrum_t = CycloSpectrum(peptide);
	score = Score(spectrum_p, spectrum_t);

	std::cout << score << std::endl;

	system("pause");
	return 0;
}
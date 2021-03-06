// B Lab-11.cpp: определяет точку входа для консольного приложения.
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
#include <stdlib.h>
int comp1(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}


class SearchF {
public:
	SearchF(char s) : _s(s) {}
	bool operator()(std::pair<char, int> const & ref) {
		return ref.first == _s;
	}
	char _s;
};

class SearchF2 {
public:
	SearchF2(std::string s) : _s(s) {}
	bool operator()(std::pair<std::string, std::string> const & ref) {
		return ref.first == _s;
	}
	std::string _s;
};

std::vector<std::pair<char, int>> mas_pept;

void createMasTable()
{
	mas_pept.push_back(std::make_pair('G', 57));
	mas_pept.push_back(std::make_pair('A', 71));
	mas_pept.push_back(std::make_pair('S', 87));
	mas_pept.push_back(std::make_pair('P', 97));
	mas_pept.push_back(std::make_pair('V', 99));
	mas_pept.push_back(std::make_pair('T', 101));
	mas_pept.push_back(std::make_pair('C', 103));
	mas_pept.push_back(std::make_pair('I', 113));
	mas_pept.push_back(std::make_pair('L', 113));
	mas_pept.push_back(std::make_pair('N', 114));
	mas_pept.push_back(std::make_pair('D', 115));
	mas_pept.push_back(std::make_pair('K', 128));
	mas_pept.push_back(std::make_pair('Q', 128));
	mas_pept.push_back(std::make_pair('E', 129));
	mas_pept.push_back(std::make_pair('M', 131));
	mas_pept.push_back(std::make_pair('H', 137));
	mas_pept.push_back(std::make_pair('F', 147));
	mas_pept.push_back(std::make_pair('R', 156));
	mas_pept.push_back(std::make_pair('Y', 163));
	mas_pept.push_back(std::make_pair('W', 186));
}

int Mass(std::string peptide)
{
	int sum = 0;

	if (peptide != "")
	{
		for (auto i = 0; i < peptide.length(); i++)
		{
			auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(peptide[i]));
			sum += it->second;
		}
	}
	return sum;
}

int ParentMas(std::vector<int> &spec)
{
	if (spec[spec.size() - 1] < spec[spec.size() - 1])
	{
		std::sort(spec.begin(), spec.end());
	}
	return spec[spec.size() - 1];
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
				auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(part[j]));
				sum += it->second;
			}
			t_spec.push_back(sum);
		}
	}

	sum = 0;
	for (int i = 0; i < len_pept; i++)
	{
		auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(peptide[i]));
		sum += it->second;
	}
	t_spec.push_back(sum);

	sort(t_spec.begin(), t_spec.end());

	return t_spec;
}

std::vector<int> LinearSpectrum(std::string peptide)
{
	std::string copy_pept = peptide, part = "";
	int sum = 0;

	int len_pept = copy_pept.length();

	std::vector<int> t_spec = { 0 };

	copy_pept += peptide;

	for (int k = 1; k < len_pept; k++)
	{
		for (int i = 0; i < len_pept - k + 1; i++)
		{
			sum = 0;
			part = copy_pept.substr(i, k);
			for (int j = 0; j < k; j++)
			{
				auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(part[j]));
				sum += it->second;;
			}
			t_spec.push_back(sum);
		}
	}

	sum = 0;
	for (int i = 0; i < len_pept; i++)
	{
		auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(peptide[i]));
		sum += it->second;
	}
	t_spec.push_back(sum);

	sort(t_spec.begin(), t_spec.end());

	return t_spec;
}

std::string ShowEx(std::string peptide)
{
	std::string res = "";

	if (peptide != "")
	{
		for (auto i = 0; i < peptide.length(); i++)
		{
			auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(peptide[i]));
			res = res + std::to_string(it->second) + " ";
		}
		res.pop_back();
	}
	return res;
}

std::string ShowEx2(std::string peptide)
{
	std::string res = "";

	if (peptide != "")
	{
		for (auto i = 0; i < peptide.length(); i++)
		{
			auto it = std::find_if(mas_pept.begin(), mas_pept.end(), SearchF(peptide[i]));
			res = res + std::to_string(it->second) + "-";
		}
		res.pop_back();
	}
	return res;
}

int Score(std::vector<int>& sp_p, std::vector<int>& sp_t)
{
	int sum = 0;
	std::vector<int> p_spec = sp_p;

	for (auto i = p_spec.begin(); i != p_spec.end();)
	{
		auto it = std::find(sp_t.begin(), sp_t.end(), *i);
		if (it != sp_t.end())
		{
			sum++;
			i = p_spec.erase(i);
		}
		else
		{
			i++;
		}
	}

	return sum;
}

std::vector<std::pair<std::string, int>> expand(std::vector<std::pair<std::string, int>> var, std::vector<int> spec)
{
	std::vector<std::pair<std::string, int>> tab_var;
	for (auto i = var.begin(); i != var.end(); ++i)
	{
		std::string copy_pept = i->first;
		for (auto j = mas_pept.begin(); j != mas_pept.end(); j++)
		{
			std::string tmp_pept = copy_pept + j->first;
			std::vector<int> cs = LinearSpectrum(tmp_pept);
			tab_var.push_back(std::make_pair(tmp_pept, Score(cs, spec)));
		}
	}
	return tab_var;
}

std::vector<std::pair<std::string, int>> Trim(std::vector<std::pair<std::string, int>> tab_var, std::vector<int> spec, int n)
{
	std::vector<int> score;
	std::vector<std::pair<std::string, int>> var;

	for (int i = 0; i < tab_var.size(); i++)
	{
		score.push_back(tab_var[i].second);
	}

	std::sort(score.begin(), score.end());

	int HighestScore = -1;

	if (score.size() == 0) 
	{
		HighestScore = 0;
	}
	else if (score.size() >= n) 
	{
		HighestScore = score[score.size() - n];
	}
	else 
	{
	    HighestScore = score[0];
	}

	for (int i = 0; i < tab_var.size(); ++i) 
	{
		std::string curr = tab_var[i].first;
		std::vector<int> cs = LinearSpectrum(curr);

		if (Score(cs, spec) >= HighestScore) 
		{
			var.push_back(std::make_pair(tab_var[i].first, tab_var[i].second));
		}
	}
	return var;
}



std::string  CyclopeptideSequencing(std::vector<int> &spec, int n)
{
	std::vector<std::pair<std::string, int>> tab_var = { { "", 0 } };
	std::string leader_peptide = "", res_p = "";

	while (!tab_var.empty())
	{
		tab_var = expand(tab_var, spec);

		for (auto i = tab_var.begin(); i != tab_var.end();)
		{
			std::string copy_pept = i->first;
			if (Mass(i->first) == ParentMas(spec))
			{
				std::vector<int> cs = LinearSpectrum(i->first);
				std::vector<int> lcs = LinearSpectrum(leader_peptide);

				if (Score(cs, spec) > Score(lcs, spec))
				{
					leader_peptide = i->first;
				}
				i++;
			}
			else if (Mass(i->first) > ParentMas(spec))
			{
				i = tab_var.erase(i);
			}
			else
			{
				i++;
			}
		}

		tab_var = Trim(tab_var, spec, n);
	}

	res_p = ShowEx2(leader_peptide);

	return res_p;
}

int main()
{
	createMasTable();

	std::vector<int> spectrum;
	std::string source = "", s_c = "";
	int n = 0;

	std::getline(std::cin, s_c, '\n');

	for (int i = 0; i < s_c.size(); ++i)
	{
		if (isdigit(s_c[i]))
		{
			int j = i;
			while (isdigit(s_c[i]))
			{
				i++;
			}
			n = atoi(s_c.substr(j, i).c_str());
		}
	}

	std::getline(std::cin, source);

	for (int i = 0; i < source.size(); ++i)
	{
		if (isdigit(source[i]))
		{
			int j = i;
			while (isdigit(source[i]))
			{
				i++;
			}
			spectrum.push_back(atoi(source.substr(j, i).c_str()));
		}
	}

	std::string res = CyclopeptideSequencing(spectrum, n);

	std::cout << res;

	system("pause");
	return 0;
}
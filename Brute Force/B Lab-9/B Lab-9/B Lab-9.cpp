// B Lab-9.cpp: определяет точку входа для консольного приложения.
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

std::vector<std::pair<std::string, int>> expand(std::vector<std::pair<std::string, int>> var)
{
	std::vector<std::pair<std::string, int>> tab_var;
	for (auto i = var.begin(); i != var.end(); ++i)
	{
		std::string copy_pept = i->first;
		for (auto j = mas_pept.begin(); j != mas_pept.end(); j++)
		{
			std::string tmp_pept = copy_pept + j->first;
			tab_var.push_back(std::make_pair(tmp_pept, Mass(tmp_pept)));
		}
	}
	return tab_var;
}

std::vector<std::pair<std::string, std::string>> CyclopeptideSequencing(std::vector<int> &spec)
{
	std::vector<std::pair<std::string, int>> tab_var = { { "", 0 } };
	std::vector<std::pair<std::string, std::string>> res;
	while (!tab_var.empty())
	{
		tab_var = expand(tab_var);

		for (auto i = tab_var.begin(); i != tab_var.end();)
		{
			if (i->second == ParentMas(spec))
			{
				std::vector<int> cs = LinearSpectrum(i->first);
				int count = Score(cs, spec);

				if (count == cs.size())
				{
					res.push_back(std::make_pair(ShowEx2(i->first), i->first));
				}
				i = tab_var.erase(i);
			}
			else
			{
				std::vector<int> cs = LinearSpectrum(i->first);
				int count = Score(cs, spec);

				if (count != cs.size())
				{
					i = tab_var.erase(i);
				}
				else
				{
					i++;
				}
			}
		}
	}
	return res;
}

int main()
{
	createMasTable();

	std::vector<int> spectrum;
	std::string source = "";

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

	std::vector<std::pair<std::string, std::string>> res = CyclopeptideSequencing(spectrum);
	std::vector<std::pair<std::string, std::string>> res_r;

	for (int i = 0; i < res.size(); i++)
	{
		auto it = std::find_if(res_r.begin(), res_r.end(), SearchF2(res[i].first));
		if (it == res_r.end())
		{
			res_r.push_back(std::make_pair(res[i].first, res[i].second));
		}
	}

	for (auto i : res_r)
	{
		std::cout << i.first << " ";
	}

	system("pause");
	return 0;
}
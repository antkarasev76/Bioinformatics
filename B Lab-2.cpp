// B Lab-2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

int PatternCount(std::string text, std::string pattern)
{
	int len_pat = 0, len_gen = 0, k = 0, ch = 0, t = 0;
	len_gen = text.length();
	len_pat = pattern.length();

	for (int i = 0; i < len_gen - len_pat; i++)
	{
		ch = i;
		t = 0;
		for (int j = 0; j < len_pat; j++)
		{
			if (pattern[j] != text[ch])
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

	return k;
}

int main()
{
	std::string text = "", pat = "", res = "";
	int k = 0, len_t = 0, mer = 0, ch = 0, max = 0;

	getline(std::cin, text, '\n');
	std::cin >> mer;

	len_t = text.length();

	std::map<std::string, int> freqPat;

	for (int i = 0; i < len_t - mer; i++)
	{
		pat = "";
		ch = i + mer;
		for (int j = i; j < ch; j++)
		{
			pat += text[j];
		}
		k = PatternCount(text, pat);
		freqPat[pat] = k;
	}

	auto max_ch = *std::max_element(freqPat.begin(), freqPat.end(), [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2)
	{return p1.second < p2.second; });

	std::for_each(freqPat.begin(), freqPat.end(), [&](const std::pair<std::string, int>& p) 
	{
		if (p.second == max_ch.second)
		{
			if (res == "")
			{
				res += p.first;
			}
			else
			{
				res += " ";
				res += p.first;
			}
		}
	});

	std::cout << res << std::endl;

	system("pause");
	return 0;
}

// B Lab-4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <fstream>

int main()
{
	std::string Pattern = "", part = "", f_p = "", l_p = "", res = "";

	getline(std::cin, Pattern, '\n');

	int len_pat = Pattern.length();

	std::map<std::string, std::string> rna_t;
	rna_t["AAA"] = "K"; 
	rna_t["AAC"] = "N";
	rna_t["AAG"] = "K";
	rna_t["AAU"] = "N";
	rna_t["ACA"] = "T";
	rna_t["ACC"] = "T";
	rna_t["ACG"] = "T";
	rna_t["ACU"] = "T";
	rna_t["AGA"] = "R";
	rna_t["AGC"] = "S";
	rna_t["AGG"] = "R";
	rna_t["AGU"] = "S";
	rna_t["AUA"] = "I";
	rna_t["AUC"] = "I";
	rna_t["AUG"] = "M";
	rna_t["AUU"] = "I";
	rna_t["CAA"] = "Q";
	rna_t["CAC"] = "H";
	rna_t["CAG"] = "Q";
	rna_t["CAU"] = "H";
	rna_t["CCA"] = "P";
	rna_t["CCC"] = "P";
	rna_t["CCG"] = "P";
	rna_t["CCU"] = "P";
	rna_t["CGA"] = "R";
	rna_t["CGC"] = "R";
	rna_t["CGG"] = "R";
	rna_t["CGU"] = "R";
	rna_t["CUA"] = "L";
	rna_t["CUC"] = "L";
	rna_t["CUG"] = "L";
	rna_t["CUU"] = "L";
	rna_t["GAA"] = "E";
	rna_t["GAC"] = "D";
	rna_t["GAG"] = "E";
	rna_t["GAU"] = "D";
	rna_t["GCA"] = "A";
	rna_t["GCC"] = "A";
	rna_t["GCG"] = "A";
	rna_t["GCU"] = "A";
	rna_t["GGA"] = "G";
	rna_t["GGC"] = "G";
	rna_t["GGG"] = "G";
	rna_t["GGU"] = "G";
	rna_t["GUA"] = "V";
	rna_t["GUC"] = "V";
	rna_t["GUG"] = "V";
	rna_t["GUU"] = "V";
	rna_t["UAA"] = "";
	rna_t["UAC"] = "Y";
	rna_t["UAG"] = "";
	rna_t["UAU"] = "Y";
	rna_t["UCA"] = "S";
	rna_t["UCC"] = "S";
	rna_t["UCG"] = "S";
	rna_t["UCU"] = "S";
	rna_t["UGA"] = "";
	rna_t["UGC"] = "C";
	rna_t["UGG"] = "W";
	rna_t["UGU"] = "C";
	rna_t["UUA"] = "L";
	rna_t["UUC"] = "F";
	rna_t["UUG"] = "L";
	rna_t["UUU"] = "F";

	for (int i = 0; i < len_pat; i += 3)
	{
		part = Pattern.substr(i, 3);
		res += rna_t[part];
	}

	std::cout << res << std::endl;

	system("pause");
	return 0;
}

// B Lab-6.cpp: определяет точку входа для консольного приложения.
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
	unsigned long int length_c_p = 0, count_pept = 0;
	std::cin >> length_c_p;

	count_pept = length_c_p * (length_c_p - 1);

	std::cout << count_pept << std::endl;

	system("pause");
	return 0;
}
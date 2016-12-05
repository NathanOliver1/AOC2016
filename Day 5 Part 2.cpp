#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <cctype>
#include <set>
#include "md5.h"

int main()
{
	std::string input = "ugkcyxxp";
	std::string builder(8, 0);
	std::set<int> found;

	for (std::size_t i = 0; found.size() != 8; ++i)
	{
		std::string hex = md5(input + std::to_string(i));
		if (hex[0] == '0' && hex[1] == '0' && hex[2] == '0' && hex[3] == '0' && hex[4] == '0')
		{
			if (isdigit(hex[5]) && hex[5] < '8')
			{
				if (found.insert(hex[5]).second)
					builder[hex[5] - '0'] = hex[6];
			}
		}
	}
	std::cout << builder;
}
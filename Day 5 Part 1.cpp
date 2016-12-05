#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include "md5.h"

int main()
{
	std::string input = "ugkcyxxp";
	std::string builder;

	for (std::size_t i = 0; builder.size() != 8; ++i)
	{
		std::string hex = md5(input + std::to_string(i));
		if (hex[0] == '0' && hex[1] == '0' && hex[2] == '0' && hex[3] == '0' && hex[4] == '0')
		{
			builder += hex[5];
		}
	}
	std::cout << builder;
}
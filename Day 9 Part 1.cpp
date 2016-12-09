#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <cctype>
#include <set>
#include <stack>

int main()
{
	std::ifstream fin("file.txt");
	std::string line;
	std::getline(fin, line);
	std::string builder;
	std::size_t pos = 0;
	while ((pos = line.find_first_of("(", pos)) != std::string::npos)
	{
		if (pos > 0)
		{
			builder += line.substr(0, pos);
			line.erase(0, pos);
		}
		std::stringstream ss(line);
		int length, times;
		char eater;
		ss >> eater >> length >> eater >> times;
		line.erase(0, line.find_first_of(")", 0) + 1);
		for (int i = 0; i < times; ++i)
		{
			builder += line.substr(0, length);
		}
		line.erase(0, length);
		pos = 0;
	}
	std::cout << builder.size();
}


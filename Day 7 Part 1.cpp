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

bool find_if_not_brackets(const std::string& line, std::size_t pos);

int main()
{
	std::ifstream fin("file.txt");
	std::string line;
	int counter = 0;
	while (std::getline(fin, line))
	{
		bool found = false;
		for (std::size_t i = 0; i < line.size() - 3; i++)
		{
			if (line[i] == line[i + 3] && line[i + 1] == line[i + 2] && line[i] != line[i + 1])
			{
				if (find_if_not_brackets(line, i))
				{
					found = true;
				}
				else
				{
					found = false;
					break;
				}
			}
		}
		if (found)
			counter++;
	}
	std::cout << counter;
}

bool find_if_not_brackets(const std::string& line, std::size_t pos)
{
	std::stack<char> brackets;
	for (std::size_t i = 0; i < pos; ++i)
	{
		if (line[i] == '[')
			brackets.push(line[i]);
		else if (line[i] == ']')
			brackets.pop();
	}
	return brackets.size() == 0;
}
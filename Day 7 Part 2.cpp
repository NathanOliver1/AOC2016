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
		bool found_ABA = false;
		bool found_BAB = false;
		for (std::size_t i = 0; i < line.size() - 2; i++)
		{
			if (line[i] == line[i + 2] && line[i] != line[i + 1])
			{
				if (find_if_not_brackets(line, i))
				{
					std::string bab(3, 0);
					std::size_t pos = 0;
					bab[0] = bab[2] = line[i + 1];
					bab[1] = line[i];
					while ((pos = line.find(bab, pos)) != std::string::npos)
					{
						if (!find_if_not_brackets(line, pos))
						{
							found_ABA = found_BAB = true;
						}
						pos++;
					}
				}
			}
		}
		if (found_ABA && found_BAB)
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
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <cctype>
#include <set>

int main()
{
	std::vector<std::map<char, int>> messages(8);
	std::ifstream fin("file.txt");
	std::string line;
	while (std::getline(fin, line))
	{
		for (std::size_t i = 0; i < line.size(); ++i)
		{
			messages[i][line[i]]++;
		}
	}
	std::string builder;
	for (std::size_t i = 0; i < messages.size(); ++i)
	{
		auto it = std::max_element(messages[i].begin(), messages[i].end(), [](const auto& lhs, const auto& rhs) {
			return lhs.second < rhs.second;
		});
		builder += it->first;
	}
	std::cout << builder;
}
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

std::map<char, int> get_letter_count(std::string line);

bool valid_checksum(const std::map<char, int>& letters, std::string checksum);

int main()
{
	std::ifstream fin("file.txt");
	std::map<char, int> letters;
	std::string line;
	long long sum = 0;
	while (std::getline(fin, line))
	{
		std::string checksum;
		std::size_t pos = line.find_last_of("-");
		letters = get_letter_count(line.substr(0, pos));
		int id = std::stoi(line.substr(pos + 1, line.find_first_of("[", pos) - pos));
		pos = line.find_first_of("[", pos);
		checksum = line.substr(pos + 1, 5);
		if (valid_checksum(letters, checksum))
			sum += id;
	}
	std::cout << sum;
}

std::map<char, int> get_letter_count(std::string line)
{
	std::map<char, int> letters;
	for (auto e : line)
		if (e != '-')
			letters[e]++;
	return letters;
}

bool valid_checksum(const std::map<char, int>& letters, std::string checksum)
{
	std::vector<std::pair<char, int>> max_letters;
	for (const auto& e : letters)
		max_letters.push_back(e);
	std::sort(max_letters.begin(), max_letters.end(), [](auto lhs, auto rhs) {
		if (lhs.second != rhs.second)
			return lhs.second > rhs.second;
		return lhs.first < rhs.first;
	});
	std::string builder;
	for (int i = 0; i < 5; ++i)
		builder += max_letters[i].first;
	return builder == checksum;
}


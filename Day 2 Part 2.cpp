#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <utility>
#include <fstream>

int main()
{
	std::ifstream fin("file.txt");
	std::string commands;
	char keypad[5][5] = { { '0','0','1','0','0' },{ '0','2','3','4','0' },{ '5','6','7','8','9' },{ '0','A','B','C','0' },{ '0','0','D','0','0' } };
	std::pair<int, int> position{ 2, 1 };
	std::string passcode;
	while (std::getline(fin, commands))
	{
		for (auto direction : commands)
		{
			if (keypad[position.first][position.second] == '0')
				std::cout << "\n";
			switch (direction)
			{
			case 'U':
				if (position.first == 0 || keypad[position.first - 1][position.second] == '0')
					break;
				else
					position.first -= 1;
				break;
			case 'D':
				if (position.first == 4 || keypad[position.first + 1][position.second] == '0')
					break;
				else
					position.first += 1;
				break;
			case 'L':
				if (position.second == 0 || keypad[position.first][position.second - 1] == '0')
					break;
				else
					position.second -= 1;
				break;
			case 'R':
				if (position.second == 4 || keypad[position.first][position.second + 1] == '0')
					break;
				else
					position.second += 1;
				break;
			}
		}
		passcode += keypad[position.first][position.second];
	}
	std::cout << passcode;
}
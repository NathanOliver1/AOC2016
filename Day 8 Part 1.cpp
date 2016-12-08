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

void column_rotate(std::vector<std::vector<int>>& screen, int column, int amount);

int main()
{
	std::ifstream fin("file.txt");
	std::string line;
	std::vector<std::vector<int>> screen(6, std::vector<int>(50, 0));
	while (std::getline(fin, line))
	{
		std::string command, row_or_column;
		int row_or_column_number, value;
		std::stringstream ss(line);
		ss >> command;
		if (command == "rect")
		{
			int x, y;
			char eater;
			ss >> x >> eater >> y;
			for (int i = 0; i < y; ++i)
				for (int j = 0; j < x; ++j)
					screen[i][j] = 1;
		}
		else
		{
			char eater;
			ss >> row_or_column >> eater >> eater >> row_or_column_number >> eater >> eater >> value;
			if (row_or_column == "row")
			{
				auto& row = screen[row_or_column_number];
				std::rotate(row.rbegin(), row.rbegin() + value, row.rend());
			}
			else
			{
				column_rotate(screen, row_or_column_number, value);
			}
		}
	}
	int counter = 0;
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 50; ++j)
			if (screen[i][j] == 1)
				counter++;
	std::cout << counter;
}

void column_rotate(std::vector<std::vector<int>>& screen, int column, int amount)
{
	std::vector<int> col;
	for (int i = 0; i < 6; i++)
		col.push_back(screen[i][column]);
	std::rotate(col.rbegin(), col.rbegin() + amount, col.rend());
	for (int i = 0; i < 6; i++)
		screen[i][column] = col[i];
}
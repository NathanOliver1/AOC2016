#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <utility>
#include <map>

enum Direction { North, East, South, West };

struct Position
{
	Position(int x, int y, Direction d) : x(x), y(y), direction(d) {}
	int x;
	int y;
	Direction direction;
};

struct Line
{
	int x1;
	int y1;
	int x2;
	int y2;
};

int main()
{
	std::string directions = "R3, L2, L2, R4, L1, R2, R3, R4, L2, R4, L2, L5, L1, R5, R2, R2, L1, R4, R1, L5, L3, R4, R3, R1, L1, L5, L4, L2, R5, L3, L4, R3, R1, L3, R1, L3, R3, L4, R2, R5, L190, R2, L3, R47, R4, L3, R78, L1, R3, R190, R4, L3, R4, R2, R5, R3, R4, R3, L1, L4, R3, L4, R1, L4, L5, R3, L3, L4, R1, R2, L4, L3, R3, R3, L2, L5, R1, L4, L1, R5, L5, R1, R5, L4, R2, L2, R1, L5, L4, R4, R4, R3, R2, R3, L1, R4, R5, L2, L5, L4, L1, R4, L4, R4, L4, R1, R5, L1, R1, L5, R5, R1, R1, L3, L1, R4, L1, L4, L4, L3, R1, R4, R1, R1, R2, L5, L2, R4, L1, R3, L5, L2, R5, L4, R5, L5, R3, R4, L3, L3, L2, R2, L5, L5, R3, R4, R3, R4, R3, R1,";
	std::istringstream ss(directions);
	char direction, comma;
	int distance;
	Position pos(0, 0, North);
	while (ss >> direction >> distance >> comma)
	{
		Position previous = pos;
		switch (pos.direction)
		{
		case North:
			if (direction == 'R')
			{
				pos.x += distance;
				pos.direction = East;
			}
			else
			{
				pos.x -= distance;
				pos.direction = West;
			}
			break;
		case East:
			if (direction == 'R')
			{
				pos.y -= distance;
				pos.direction = South;
			}
			else
			{
				pos.y += distance;
				pos.direction = North;
			}
			break;
		case South:
			if (direction == 'R')
			{
				pos.x -= distance;
				pos.direction = West;
			}
			else
			{
				pos.x += distance;
				pos.direction = East;
			}
			break;
		case West:
			if (direction == 'R')
			{
				pos.y += distance;
				pos.direction = North;
			}
			else
			{
				pos.y -= distance;
				pos.direction = South;
			}
			break;
		}
	}
	std::cout << std::abs(pos.x) + std::abs(pos.y);
}

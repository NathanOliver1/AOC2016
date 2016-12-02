#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <utility>
#include <map>

enum Direction { North, East, South, West};

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

Position find_intersections(std::vector<Line>& lines);

int main()
{
	std::string directions = "R3, L2, L2, R4, L1, R2, R3, R4, L2, R4, L2, L5, L1, R5, R2, R2, L1, R4, R1, L5, L3, R4, R3, R1, L1, L5, L4, L2, R5, L3, L4, R3, R1, L3, R1, L3, R3, L4, R2, R5, L190, R2, L3, R47, R4, L3, R78, L1, R3, R190, R4, L3, R4, R2, R5, R3, R4, R3, L1, L4, R3, L4, R1, L4, L5, R3, L3, L4, R1, R2, L4, L3, R3, R3, L2, L5, R1, L4, L1, R5, L5, R1, R5, L4, R2, L2, R1, L5, L4, R4, R4, R3, R2, R3, L1, R4, R5, L2, L5, L4, L1, R4, L4, R4, L4, R1, R5, L1, R1, L5, R5, R1, R1, L3, L1, R4, L1, L4, L4, L3, R1, R4, R1, R1, R2, L5, L2, R4, L1, R3, L5, L2, R5, L4, R5, L5, R3, R4, L3, L3, L2, R2, L5, L5, R3, R4, R3, R4, R3, R1,";
	std::istringstream ss(directions);
	char direction, comma;
	int distance;
	Position pos(0, 0, North);
	std::vector<Line> lines;
	Position intersect(-99999999, -99999999, North);
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
		lines.push_back({ previous.x, previous.y, pos.x, pos.y });
		intersect = find_intersections(lines);
		if (intersect.x != -99999999)
			break;
	}
	std::cout << std::abs(intersect.x) + std::abs(intersect.y);
}

char get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
	float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
{
	float s1_x, s1_y, s2_x, s2_y;
	s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
	s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

	float s, t;
	s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
	t = (s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

	if (s > 0 && s < 1 && t > 0 && t < 1)
	{
		// Collision detected
		if (i_x != NULL)
			*i_x = p0_x + (t * s1_x);
		if (i_y != NULL)
			*i_y = p0_y + (t * s1_y);
		return 1;
	}

	return 0; // No collision
}

Position find_intersections(std::vector<Line>& lines)
{
	float x, y;
	for (int i = 0; i < lines.size(); ++i)
	{
		for (int j = i + 1; j < lines.size(); j++)
		{
			if (get_line_intersection(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2,
				lines[j].x1, lines[j].y1, lines[j].x2, lines[j].y2,
				&x, &y))
				return Position(static_cast<int>(x), static_cast<int>(y), North);
		}
	}
	return Position(static_cast<int>(-99999999), static_cast<int>(-99999999), North);
}


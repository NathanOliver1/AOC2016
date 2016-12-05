#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main()
{
	std::ifstream fin("file.txt");
	int possible = 0;
	std::vector<int> first, second, third;
	int a, b, c;
	while (fin >> a >> b >> c)
	{
		first.push_back(a);
		second.push_back(b);
		third.push_back(c);
	}
	std::vector<int> sides(first.begin(), first.end());
	sides.insert(sides.end(), second.begin(), second.end());
	sides.insert(sides.end(), third.begin(), third.end());
	for (std::size_t i = 0; i < sides.size() - 2; i +=3)
	{
		a = sides[i], b = sides[i + 1], c = sides[i + 2];
		int max = std::max({ a, b, c});
		if (a + b + c - max > max)
			possible++;
	}
	std::cout << possible;
}



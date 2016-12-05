#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
	std::ifstream fin("file.txt");
	int a, b, c;
	int possible = 0;
	while (fin >> a >> b >> c)
	{
		int max = std::max({ a, b, c });
		if (a + b + c - max > max)
			possible++;
	}
	std::cout << possible;
}



#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	int ia[3][4];

	int count = 0;
	for (auto& row : ia)
	{
		for (auto& val : row)
		{
			val = count++;
			cout << val;
		}
		cout << endl;
	}
}

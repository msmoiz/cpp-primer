#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <list>

bool equal(std::vector<int>& a, std::list<int>& b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	else
	{
		auto i = a.begin();
		auto j = b.begin();
		for (; i != a.end(); ++i, ++j)
		{
			if (*i != *j)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	std::vector<int> a = {0};
	std::cout << *a.begin() << a.front() << a[0] << a.at(0) << std::endl;
}

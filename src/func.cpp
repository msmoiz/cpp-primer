#include <iostream>
#include <vector>

#include "func.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void foo()
{
	cout << "foo" << endl;
}

void bar()
{
	cout << "bar" << endl;
}

void swap(int& a, int& b) noexcept
{
	const int temp = a;
	a = b;
	b = temp;
}

void reset(int& a)
{
	a = 0;
}

int main(int argc, char** argv)
{
	for (int i = 0; i < argc; ++i)
	{
		cout << argv[i] << endl;
	}
}
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
int compare(const T& v1, const T& v2)
{
	return v1 < v2 ? -1 : v2 < v1 ? 1 : 0;
}

template<int I>
int val()
{
	return I;
}

int main()
{
	cout << compare(1, 2) << endl;
	cout << val<5>() << endl;
}
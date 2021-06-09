#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int fact(int i)
{
	int res = 1;
	while (i > 1)
	{
		res *= i--;
	}
	return res;
}

unsigned absolute(int i) // automatic, dropped at end of scope
{
	return i > 0 ? i : -i;
}

int lol();

int calls()
{
	static int x = 0;
	return ++x;
}

int main()
{
	int val; // automatic, dropped at end of scope
	static int bal = 0; // global lifetime, inaccessible outside scope
	cin >> val;
	calls();
	calls();
	calls();
	calls();
	calls();
	calls();
	cout << absolute(val) << endl;
}

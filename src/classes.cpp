#include <iostream>

#include "SalesData.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class X
{
	class Y* y;
};

class Y
{
	X x;
};

int main()
{
	SalesData total;
	if (read(cin, total))
	{
		while (cin)
		{
			const SalesData trans(cin);
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}

			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total);
	}

	else
	{
		cerr << "No data?!" << endl;
	}
}
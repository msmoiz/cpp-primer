#include <iostream>
#include "Sales_item.h"

/*
 * Simple main function:
 * Read two numbers and write their sum.
 */
int main()
{
	Sales_item total;

	if (std::cin >> total) // Ensure valid data
	{
		Sales_item trans;
		while (std::cin >> trans)
		{
			if (total.isbn() == trans.isbn())
			{
				total += trans;
			}

			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}

		std::cout << total << std::endl;
	}

	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	
	return 0;
}

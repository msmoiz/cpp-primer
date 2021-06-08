#pragma once

#include <string>

struct SalesData // default initialized
{
	std::string book_no;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

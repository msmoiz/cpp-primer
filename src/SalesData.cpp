#include "SalesData.h"
#include <iostream>

int SalesData::rate = 0;

SalesData::SalesData()
	: units_sold(0)
	, revenue(0)
{
	
}

SalesData::SalesData(const std::string& s)
	: book_no(s)
{
	
}

SalesData::SalesData(const std::string& s, unsigned n, double p)
	: book_no(s)
	, units_sold(n)
	, revenue(p * n)
{
	
}

SalesData::SalesData(std::istream& is)
{
	read(is, *this);
}

std::string SalesData::isbn() const
{
	return book_no;
}

SalesData& SalesData::combine(const SalesData& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double SalesData::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

std::istream& read(std::istream& is, SalesData& item)
{
	double price = 0;
	is >> item.book_no >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream& os, const SalesData& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

SalesData add(const SalesData& lhs, const SalesData& rhs)
{
	SalesData sum = lhs;
	sum.combine(rhs);
	return sum;
}

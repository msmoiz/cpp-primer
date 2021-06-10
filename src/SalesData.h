#pragma once

#include <string>

class SalesData
{
	std::string book_no;
	unsigned units_sold{0};
	double revenue{0.0};
	static int rate;

public:
	
	SalesData();
	explicit SalesData(const std::string& s);
	SalesData(const std::string& s, unsigned n, double p);
	explicit SalesData(std::istream& is);
	
	std::string isbn() const;
	SalesData& combine(const SalesData& rhs);
	double avg_price() const;

	friend std::istream& read(std::istream& is, SalesData& item);
	friend std::ostream& print(std::ostream& os, const SalesData& item);
	friend SalesData add(const SalesData& lhs, const SalesData& rhs);
};

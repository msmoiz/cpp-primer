#pragma once

#include <string>

class Person
{
	std::string name;
	std::string address;

public:
	
	std::string get_name() const;
	std::string get_address() const;
	
	friend std::istream& read(std::istream& is, Person& person);
	friend std::ostream& print(std::ostream& os, const Person& person);
};

#include <functional>
#include <map>
#include <string>
#include <iostream>

using std::string;
using std::function;
using std::map;

class Calc
{
private:

	int a;
	int b;
	char op;

public:
	
	std::map<char, std::function<int(int, int)>> ops;

	friend std::istream& operator>>(std::istream& is, Calc& c)
	{
		is >> c.a >> c.b >> c.op;
		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, Calc& c)
	{
		os << "Calculation: " << c.a << " " << c.op << " " << c.b << " = " << c.ops[c.op](c.a, c.b);
		return os;
	}
};

int main()
{
	Calc calc;
	calc.ops['+'] = [](int a, int b) {return a + b;};
	calc.ops['-'] = [](int a, int b) {return a - b;};
	calc.ops['*'] = [](int a, int b) {return a * b;};
	calc.ops['/'] = [](int a, int b) {return a / b;};

	do
	{
		std::cout << "Please provide two operands and an operator (+, -, *, /)." << std::endl;
		std::cin >> calc;
		std::cout << calc << std::endl;
		
	} while (std::cin);
}
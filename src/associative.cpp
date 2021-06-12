#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

auto build_map(std::ifstream& rule_file)
{
	std::map<std::string, std::string> ret;
	
	std::string line;
	while(getline(rule_file, line))
	{
		ret[line.substr(0, line.find(' '))]
			= line.substr(line.find(' ') + 1, line.size());
	}

	return ret;
}

void transform(std::ifstream& rule_file, std::ifstream& input_file)
{
	auto rules = build_map(rule_file);
	std::string text;
	while (getline(input_file, text))
	{
		std::istringstream stream(text);
		std::string word;
		while (stream >> word)
		{
			if (rules.find(word) != rules.end())
			{
				std::cout << rules[word] << " ";
			}

			else
			{
				std::cout << word << " ";
			}
		}

		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
	const char* rule_file = argv[1];
	const char* text_file = argv[2];

	std::ifstream r(rule_file);
	std::ifstream i(text_file);

	transform(r, i);
}
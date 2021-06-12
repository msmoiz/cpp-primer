#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::string;

int main()
{
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	std::sort(words.begin(), words.end());
	words.erase(std::unique(words.begin(), words.end()), words.end());
	std::for_each(words.begin(), words.end(), [](string& word)
	{
		cout << word << endl;
	});
}
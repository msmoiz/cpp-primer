// The base types for dealing with a stream
// are istream (input), ostream (output)
// and iostream (input/output). <iostream>
// To stream files, use ifstream, ofstream,
// and fstream. <fstream>
// And to stream strings, use istringstream,
// ostringstream, and stringstream. <sstream>
// The *stream depends internally on a
// streambuf which contains the buffered data
// to be manipulated.
// The most familiar streams -- cin, cout,
// clog, and cerr -- are static instances
// of the base stream types, residing in the
// std:: namespace.

#include <iostream>
#include <fstream>
#include <sstream>

using std::ostream;
using std::istream;
using std::iostream;

using std::ofstream;
using std::ifstream;
using std::fstream;

using std::ostringstream;
using std::istringstream;
using std::stringstream;

using std::cin;
using std::cout;
using std::endl;

istream& read_data(istream& i)
{
	int val = 0;
	while (i >> val) // terminates on eof, error (bad read, etc.)
	{
		cout << val << " ";
	}
	i.clear();
	return i;
}

int main(int argc, char** argv)
{
	ifstream i(argv[1]); // closed automatically on destruct
	ofstream o(argv[2], fstream::app); // closed automatically on destruct
	std::string s;
	while (i >> s)
	{
		o << s;
	}
	// stringstream used for parsing strings that we have obtained elsewhere
	// cin >> getline
	// stringstream ss(line)
	// ss >> do work
}
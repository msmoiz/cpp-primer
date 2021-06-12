// When it comes to dynamic memory, the
// lifecycle is important to understand.
// The following is a general representation:
//
// allocate -> initialize -> use -> destroy -> free
//
// In C, the `malloc` function is used to allocate memory
// It must then be initialized. If referenced prior to
// initialization, it will point to a junk value.
// The `new` operator combines these operations in C++.
// After allocation and initialization, the object
// may be used freely.
// For cleanup, the object must be destroyed using
// its destructor.
// It must then be `free`d to deallocate memory.
// In C++, the `delete` operator combines these
// operations.
//
// Failure to adhere to these guidelines may
// result in memory leaks. Such leaks are corrected
// only when the leaking program is terminated,
// at which point the operating system reclaims the
// memory. In some embedded contexts, it is possible
// that leaked memory will only be reclaimed on
// system shutdown.

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class StrBlob
{
public:
	
	using size_type = std::vector<std::string>::size_type;

	StrBlob()
		: data(std::make_shared<std::vector<std::string>>())
	{}

	StrBlob(std::initializer_list<std::string> il)
		: data(std::make_shared<std::vector<std::string>>(il))
	{}
	
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

private:
	
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const
	{
		if (i >= data->size())
		{
			throw std::out_of_range(msg);
		}
	}
};

std::vector<int>* get_vec()
{
	return new std::vector<int>();
}

void read(std::vector<int>* v)
{
	int i = 0;
	while (std::cin >> i)
	{
		v->push_back(i);
	}
}

void write(std::vector<int>* v)
{
	for (auto& i : *v)
	{
		std::cout << i << " ";
	}
}

int main()
{
	const auto v = get_vec();
	read(v);
	write(v);
	delete v;
}

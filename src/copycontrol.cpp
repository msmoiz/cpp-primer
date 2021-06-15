#include <iostream>
#include <string>

class HasPtr
{
public:

	// default
	HasPtr(const std::string& s = std::string())
		: ps(new std::string(s)), i(0)
	{
		std::cout << "direct" << std::endl;
	}

	// copy
	HasPtr(const HasPtr& other)
		: ps(new std::string(*other.ps)), i(other.i)
	{
		std::cout << "copy" << std::endl;
	}

	// copy-assign
	HasPtr& operator=(const HasPtr& other)
	{
		if (this == &other)
		{
			return *this;
		}
		
		std::cout << "assign" << std::endl;
		*ps = *other.ps;
		return *this;
	}

	// destruct
	~HasPtr()
	{
		std::cout << "delete" << std::endl;
		delete ps;
	} // destroyed in rev order

	friend void swap(HasPtr& lhs, HasPtr& rhs) noexcept
	{
		using std::swap;
		swap(lhs.ps, rhs.ps);
		swap(lhs.i, rhs.i);
	}

private:
	std::string* ps;
	int i;
};

class numbered
{
public:

	static int x;
	
	numbered()
	{
		mysn = x++;
	}

	numbered(const numbered& other)
	{
		mysn = x++;
	}

	int mysn;
};

int numbered::x = 0;

void f(numbered& s)
{
	std::cout << s.mysn << std::endl;
}

struct NoCopy
{
	NoCopy() = default;
	NoCopy(const NoCopy& n) = delete;
	NoCopy& operator=(const NoCopy& n) = delete;
};

class TreeNode
{
public:

	TreeNode(int v)
		: value(v)
		, left(nullptr)
		, right(nullptr)
	{
		
	}

	~TreeNode()
	{
		std::cout << "destroying " << value << std::endl;
		delete left;
		delete right;
	}
	
	int value;
	TreeNode* left;
	TreeNode* right;
};

int main()
{
	NoCopy n;
	//NoCopy o = n;
	//NoCopy p;
	//p = n;
	// copying can be valuelike or pointer like
	// valuelike: each copy has its own state, does not affect others
	// pointerlike: each copy shares state, affects others, e.g shared_ptr (using reference counting)
	TreeNode root{1};
	root.left = new TreeNode(2);
	root.right = new TreeNode(3);
}
#include "KString.h"
#include "iostream"

KString::KString(const char* str)
{
	if (str == nullptr)
	{
		this->data = nullptr;
		this->length = 0;
	}
	else 
	{
		this->length = this->strlen(str);
		this->data = new char[length];

		memcpy(data, str, length);
	}
}

int KString::len()
{
	return this->length;
}

void KString::append(const char* str)
{

}

int KString::find(const char* str)
{
	return 0;
}

KString KString::sub(int index, int num)
{
	auto header = this->data + index;

	return KString();
}

KString KString::split(const char* str)
{
	return KString();
}

int KString::strlen(const char* str)
{
	int len = 0;
	if (str == nullptr)
	{
		throw "Invalid input string!";
	}

	while (*str != '\0')
	{
		++str;
		++len;
	}
	return len;
}


KString& KString::operator=(const char* str)
{
	int len = this->strlen(str);

	if (length != len) 
	{
		delete[] data;
		data = new char[len];
		length = len;
	} 

	memcpy(data, str, length);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const KString& str)
{
	int num = str.length;
	auto tmp = str.data;
	while (num--)
	{
		os << *tmp;
		++tmp;
	}
	
	return os;
}

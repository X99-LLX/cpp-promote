#include "KString.h"
#include "iostream"
#include "cassert"

KString::KString()
{
	data = new char[1];
	data[0] = '\0';
	length = 0;
}

KString::KString(const char* str)
{
	length = this->kstrlen(str);
	data = new char[length + 1];
	kstrcpy(data, str, length);
}

KString::~KString()
{
	if (data != nullptr)
	{
		delete[] this->data;
		this->data = nullptr;
	}
}

int KString::len()
{
	return this->length;
}

void KString::append(const char* str)
{
	int len = this->kstrlen(str);
	int nlen = length + len;

	char* ndata = new char[nlen + 1];

	for (int i = 0; i < this->length; i++)
	{
		ndata[i] = data[i];
	}

	for (int i = 0; i < len; i++)
	{
		ndata[length + i] = str[i];
	}

	this->length = nlen;

	ndata[length] = '\0';

	delete[] this->data;
	this->data = nullptr;

	this->data = ndata;
}

int KString::find(const char* str, int startIndex)
{
	int len = kstrlen(str);

	if (len > length) 
	{
		return -1;
	}

	char temp = str[0];
	bool flag = false;

	for (int i = startIndex; i < length; i++)
	{
		if ( data[i] == temp)
		{
			flag = true;
			for (int j = 1; j < len; j++)
			{
				if (str[j] != data[j + i])
				{
					flag = false;
					break;
				}
			}
			if (flag) 
			{
				return i;
			}
		}
	}

	return -1;
}

KString* KString::sub(int index, int num)
{
	if (length == 0)
	{
		return new KString();
	}

	int nlen = num > length ? length : num;

	if (index < 0 || index >= length) 
	{
		return new KString();
	}

	char* result = new char[nlen + 1];

	for (int i = 0; i < nlen; i++)
	{
		result[i] = data[i + index];
	}

	result[nlen] = '\0';
 
	KString* kstr = new KString(result);

	delete[] result;
	result = nullptr;

	return kstr;
}

KString** KString::split(const char* str, int& size)
{
	KString** result = new KString*[length];
	int len = kstrlen(str);

	int start = 0;
	int count = 0;

	while (true)
	{
		int index = this->find(str, start);
		if (index == -1)
		{
			if (start <= length -1 )
			{
				result[count] = sub(start, length - start);
				++count;
			}
			break;
		}

		result[count] = sub(start, index - start);

		start = index + len;
		++count;
	}

	size = count;

	//delete (result + count);

	return result;
}

int KString::kstrlen(const char* str)
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

void KString::kstrcpy(char* nStr, const char* oStr, int len)
{
	for (int i = 0; i < len; i++)
	{
		nStr[i] = oStr[i];
	}

	nStr[len] = '\0';
}

char* KString::getData()
{
	return this->data;
}


KString& KString::operator=(const char* str)
{
	int len = this->kstrlen(str);

	if (length != len) 
	{
		delete[] this->data;
		data = nullptr;
		data = new char[len + 1];
		length = len;
	} 

	for (int i = 0; i < len; i++) 
	{
		data[i] = str[i];
	}

	data[len] = '\0';

	return *this;
}

bool KString::operator==(const KString& str)
{
	if (length != str.length)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (data[i] != str.data[i])
		{
			return false;
		}
	}
	return true;
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

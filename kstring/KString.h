#pragma once
#include "iostream"

class KString
{
private:
	char* data = nullptr;
	int length = 0;

public:
	KString(const char* str = nullptr);

	int len();
	void append(const char* str);
	int find(const char* str);

	KString sub(int index, int num);
	KString split(const char* str);

	int strlen(const char* str);

	// operator
	KString& operator=(const char* str);
	friend std::ostream& operator<<(std::ostream& os, const KString& s);
};




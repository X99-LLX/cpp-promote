#pragma once
#include "iostream"

class KString
{
private:
	char* data = nullptr;
	int length;

public:
	KString();
	KString(const char* str);
	~KString();

	int len();

	void append(const char* str);
	int find(const char* str, int startIndex = 0);
	KString* sub(int index, int num);
	KString** split(const char* str, int& size);

	int kstrlen(const char* str);
	void kstrcpy(char* nStr, const char* oStr, int len);
	char* getData();

	// operator
	KString& operator=(const char* str);
	bool operator==(const KString& str);
	friend std::ostream& operator<<(std::ostream& os, const KString& s);
};




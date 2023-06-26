#include "iostream"
#include "KString.h"


int main() 
{
	std::cout << "Hello kString!" << std::endl;

	KString test = KString();
	std::cout << "test is : " << test << std::endl;

	KString str1 = KString("123");
	std::cout << "str1 is : " <<  str1 << std::endl;

	str1 = "qwerty";
	std::cout << "str1 is : " << str1 << std::endl;

	int len = str1.len();
	std::cout << "str1 len is : " << len << std::endl;

	KString* sub1 = str1.sub(0, 2);
	std::cout << "sub(0, 2) is : " << *sub1 << std::endl;

	sub1->append("ape,,n,,d aa");
	std::cout << "append str1 is : " << *sub1 << std::endl;

	bool b1 = str1 == *sub1;
	std::cout << "str1 == sub1 is : " << std::boolalpha << b1 << std::endl;

	int index = sub1->find("nd");
	std::cout << "sub.find(\"nd\") index is : " << index << std::endl;

	int b = 0;
	auto a = sub1->split(",,", b);

	for (int i = 0; i < b; i++)
	{
		std::cout << *a[i] << std::endl;
	}

	return 0;
}
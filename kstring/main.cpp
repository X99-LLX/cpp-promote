#include "iostream"
#include "KString.h"


int main() 
{
	std::cout << "Hello kString!" << std::endl;

	KString str1 = KString("str1");
	std::cout << str1 << std::endl;

	str1 = "tes";
	std::cout << str1 << std::endl;

	int len = str1.len();
	std::cout << len << std::endl;

	KString sub1 = str1.sub(1, 2);

	return 0;
}
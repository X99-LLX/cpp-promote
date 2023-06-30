#include "iostream"
#include "KArray.h"


int main()
{
	std::cout << "Hello KArray and KList" << std::endl;

	auto a = KArray<int>();

	a.reserve(10);

	//a.print();

	return 0;
}
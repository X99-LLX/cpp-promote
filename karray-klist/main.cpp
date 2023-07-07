#include "iostream"
//#include "KArray.h"
#include "KList.h"

//void ArrayTest() 
//{
//	auto a = KArray<int>(1);
//
//	a.push(10);
//	a.push(20);
//	a.push(30);
//
//	a.insert(1, 100);
//	a.print();
//
//	a.remove(0);
//	a.print();
//
//	std::cout << "100 is index of " << a.findIndex(100) << std::endl;
//	std::cout << "pop is " << a.pop() << std::endl;
//	a.print();
//
//	a.clear();
//	a.print();
//}


void ListTest() 
{
	auto a = KList<int>();
	a.push(1);
	a.push(2);
	a.push(3);
	int b = a.size();
	std::cout << b << std::endl;
	a.print();
}


int main()
{
	std::cout << "Hello KArray and KList" << std::endl;

	ListTest();

	return 0;
}
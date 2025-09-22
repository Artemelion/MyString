#include "MyString.h"
#include <iostream>
using namespace std; 

int main()
{
	MyString obj1("Hello world!");
	obj1.Print();

	MyString obj2 = obj1; 
	obj2.Print();

	bool rez = obj1.MyStrStr("wo");
	cout << rez << endl; 

	MyString::PrintCount();

	return 0;
}
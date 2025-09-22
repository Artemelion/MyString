#include "MyString.h"
#include <iostream>
using namespace std; 

int main()
{
	MyString obj1("Hello world!");
	obj1.Print();

	MyString::PrintCount();

	MyString obj2 = obj1; 
	obj2.Print();

	MyString::PrintCount();

	bool rez = obj1.MyStrStr("wo");
	cout << "result: " << rez << endl;

	cout << "Total Objects: " << endl;
	MyString::PrintCount();

	return 0;
}

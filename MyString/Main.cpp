#include "MyString.h"
#include <iostream>
using namespace std; 

int main()
{
	/*
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
	*/

	MyString a("Hello");
	MyString b("World");

	a.Print();
	b.Print();
	cout << endl;

	MyString c = a.operator+(b); //Helloworld.
	c.Print();

	MyString c1 = a + "world"; //Helloworld
	c1.Print();

	MyString c2 = a.operator+(b) - 'l'; //heoword
	c2.Print();

	MyString d = a - "lo"; //hel
	d.Print();

	return 0;
}

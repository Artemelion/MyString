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

/*
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

	++a; // Hello+1space
	a.Print();
	MyString f = --a; // Hell
	f.Print();
	a += "world"; //Helloworld
	a.Print();
	a += b; //Helloworld
	a.Print();
	a -= "lo"; //Hel
	a.Print();
	cout << (a == b); // true or false
	cout << (a > b); // true or false

*/

	MyString obj("Hello World");
	obj.Print();

	for (int i = 0; i < obj.GetLength(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;


	string str = "Hello world";
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	return 0;
}



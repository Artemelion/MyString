#pragma once
class MyString
{
	char* str; 
	int length;
	static int count;
public: 
	static void PrintCount();
	MyString();
	MyString(int size);
	MyString(const char* _str);
	MyString(const MyString& obj); // copy constructor
	MyString(MyString&& obj); // move constuctor
	~MyString();
	
	void Print();

	void MyStrcpy(MyString& obj); // copy str
	bool MyStrStr(const char* str); // find str in str
	int MyChr(char c); // find symbol (index of it or -1)
	void MyDelChr(char c); // dell symbol
	int MyStrLen(); // length of str
	void MyStrCat(MyString& b); // concatenation of str
	int MyStrCmp(MyString& b); // compare str

	MyString operator+(MyString& obj);
	MyString operator+(const char* b);
	MyString operator-(char ch);
	MyString operator-(const char* sub);

	//перегрузка логических операций(через метод)

	bool operator>(MyString& obj);
	bool operator<(MyString& obj);
	bool operator==(MyString& obj);
	bool operator!=(MyString& obj);
	bool operator>=(MyString& obj);
	bool operator<=(MyString& obj);

	MyString& operator++(); // ++a prefix
	MyString& operator--(); // --a prefix

	MyString& operator+= (const char* a);
	MyString& operator+= (const MyString& obj);
	MyString& operator-= (const char* a);

	MyString& operator= (const MyString& obj); // copy assignment
	MyString& operator= (MyString&& obj); // move assignment



};



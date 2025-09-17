#pragma once
class MyString
{
	char* str; 
	int length;
public: 
	MyString();
	MyString(int size);
	MyString(const char* _str);
	MyString(const MyString& obj); // конструктор копирования
	MyString(MyString&& obj); // конструктор перемещения
	~MyString();
	
	void Print();

	void MyStrcpy(MyString& obj); // копирование строк
	bool MyStrStr(const char* str); // поиск подстроки в строке
	int MyChr(char c); // поиск символа в строке (индекс найденного символа, либо -1)
	void MyDelChr(char c); // удаляет указанный символ

	/*
	int MyStrLen(); // возвращает длину строки
	void MyStrCat(MyString& b); // объединение строк
	
	int MyStrCmp(MyString& b); // сравнение строк
	*/

};


























































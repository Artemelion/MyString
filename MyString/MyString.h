#pragma once
class MyString
{
	char* str; 
	int length;
public: 
	MyString();
	MyString(int size);
	MyString(const char* _str);
	MyString(const MyString& obj); // ����������� �����������
	MyString(MyString&& obj); // ����������� �����������
	~MyString();
	
	void Print();

	void MyStrcpy(MyString& obj); // ����������� �����
	bool MyStrStr(const char* str); // ����� ��������� � ������
	int MyChr(char c); // ����� ������� � ������ (������ ���������� �������, ���� -1)
	void MyDelChr(char c); // ������� ��������� ������

	/*
	int MyStrLen(); // ���������� ����� ������
	void MyStrCat(MyString& b); // ����������� �����
	
	int MyStrCmp(MyString& b); // ��������� �����
	*/

};


























































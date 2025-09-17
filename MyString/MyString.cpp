#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length] {};
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
}

MyString::MyString(const char* _str)
{
	length = strlen(_str);
	str = new char[length + 1] {};
	strcpy_s(str, length + 1, _str);
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;

	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
}

MyString::MyString(MyString&& obj)
{
    str = obj.str;
    obj.str = nullptr;
    length = obj.length;
    obj.length = 0;
    cout << "Move constructor!!\n";
}

MyString::~MyString()
{
	delete[] str;
	length = 0;
}

void MyString::Print()
{
	cout << str << endl;
}

//void MyString::MyStrcpy(MyString& obj)
//{
//	if (this->length > obj.length)
//	{
//		delete[] str;
//		for (int i = 0; i < length; i++)
//		{
//			obj.length[i] = length[i];
//		}
//		str = new char[strlen(obj.str) + 1];
//		strcpy_s(str, strlen(obj.str) + 1, obj.str);
//	}
//}

bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str, str);

	if (s != nullptr)
	{
		return true;
	}
	return false;
}

int MyString::MyChr(char c)
{

	return 0;
}


void MyString::MyDelChr(char c)
{
    int count = 0;
    for (int i = 0; i < length + 1; i++)
    {
        if (str[i] == c)
        {
            count++;
        }
    }

    int newsize = length - count;

    char* newstr = new char[newsize + 1];

    int j = 0; // index newstr
    for (int i = 0; i < length + 1; i++) // копирование строки
    {
        if (str[i] != c)
        {
            newstr[j] = str[i];
            j++;
        }
    }

    delete[] str;
    str = newstr;
    length = newsize;
}

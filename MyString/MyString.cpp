#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length+1] {};
    count++;
}
MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
    count++;
}
MyString::MyString(const char* _str)
{
	length = strlen(_str);
	str = new char[length + 1] {};
	strcpy_s(str, length + 1, _str);
    count++;
}
MyString::MyString(const MyString& obj)
{
	length = obj.length;

	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
    count++;
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

int MyString::count = 0;
void MyString::PrintCount()
{
    cout << "Count: " << count << endl;
}

void MyString::Print()
{
	cout << str << endl;
}


bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str, str);

	if (s != nullptr)
	{
		return true;
	}
	return false;
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
int MyString::MyStrLen()
{
    if (str == nullptr)
    {
        return 0;
    }
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }
    return n;
}
void MyString::MyStrcpy(MyString& obj)
{
    int srcSize = obj.MyStrLen();
    char* fresh = new char[srcSize + 1] {};

    for (int i = 0; i < srcSize; i++)
    {
        fresh[i] = obj.str[i];
    }

    delete[] str;
    str = fresh;
    length = srcSize;
}
int MyString::MyChr(char c)
{
    if (str == nullptr)
    {
        return -1;
    }

    int n = MyStrLen();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}
void MyString::MyStrCat(MyString& b)
{
    int n1 = MyStrLen();
    int n2 = b.MyStrLen();

    char* merged = new char[n1 + n2 + 1] {};

    for (int i = 0; i < n1; i++)
    {
        merged[i] = str[i];
    }
    for (int j = 0; j < n2; j++)
    {
        merged[n1 + j] = b.str[j];
    }

    delete[] str;
    str = merged;
    length = n1 + n2;
}
int MyString::MyStrCmp(MyString& b)
{
    int n1 = MyStrLen();
    int n2 = b.MyStrLen();

    int minLen = n1;
    if (n2 < minLen)
    {
        minLen = n2;
    }

    for (int i = 0; i < minLen; i++)
    {
        if (str[i] < b.str[i])
        {
            return -1;
        }
        if (str[i] > b.str[i])
        {
            return 1;
        }
    }

    if (n1 == n2)
    {
        return 0;
    }
    if (n1 < n2)
    {
        return -1;
    }
    return 1;
}

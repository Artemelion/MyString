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
}
MyString::~MyString()
{
	delete[] str;
	length = 0;
    count--;
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

int MyString::GetLength() { return length; }

char MyString::operator[](int index)
{
    if (index >= 0 || index < length)
    {
        return str[index];
    }
    throw exception("index error");
}

MyString MyString::operator+(MyString& obj)
{
    int leftLength = MyStrLen();
    int rightLength = obj.MyStrLen();

    char* buffer = new char[leftLength + rightLength + 1] {};

    for (int i = 0; i < leftLength; i++)
    {
        buffer[i] = str[i];
    }
    for (int j = 0; j < rightLength; j++)
    {
        buffer[leftLength + j] = obj.str[j];
    }

    MyString result(buffer);
    delete[] buffer;
    return result;
}
MyString MyString::operator+(const char* b)
{
    MyString rez(length + strlen(b)+1);
    strcpy_s(rez.str, length+1, str);
    strcat_s(rez.str, length + strlen(b) + 1, b);

    return rez;
}
MyString MyString::operator-(char ch)
{
    int sourceLength = MyStrLen();

    char* buffer = new char[sourceLength + 1] {};
    int writeIndex = 0;

    for (int i = 0; i < sourceLength; i++)
    {
        if (str[i] != ch)
        {
            buffer[writeIndex] = str[i];
            writeIndex++;
        }
    }

    MyString result(buffer);
    delete[] buffer;
    return result;
}
MyString MyString::operator-(const char* sub)
{
    if (sub == nullptr || *sub == '\0') 
    {
        return MyString(*this);
    }

    int sourceLength = MyStrLen();
    int subLength = strlen(sub);

    if (subLength > sourceLength) 
    {
        return MyString(*this);
    }

    char* buffer = new char[sourceLength + 1] {};
    int bufferIndex = 0;

    int i = 0;
    while (i < sourceLength) 
    {
        bool found = true;
        for (int j = 0; j < subLength; j++) {
            if (i + j >= sourceLength || str[i + j] != sub[j]) {
                found = false;
                break;
            }
        }

        if (found) 
        {
            i += subLength;
        }
        else 
        {
            buffer[bufferIndex] = str[i];
            bufferIndex++;
            i++;
        }
    }

    buffer[bufferIndex] = '\0';

    MyString result(buffer);
    delete[] buffer;
    return result;
}

MyString& MyString::operator++()
{
    char* newstr = new char[length + 2] {}; 
    strcpy_s(newstr, length + 2, str);
    delete[] str;
    str = newstr;
    length = length + 1;
    return *this;
}
MyString& MyString::operator--()
{
    if (length == 0)
    {
        return *this;
    }
    char* newstr = new char[length -1] {}; 
    for (int i = 0; i < length - 2; i++)
    {
        newstr[i] = str[i];
    }
    delete[] str;
    str = newstr;
    length = length - 1;
    return *this;
}

MyString& MyString::operator+=(const char* a)
{
    int addLength = strlen(a);
    char* newstr = new char[length + addLength + 1] {};
    strcpy_s(newstr, length + 1, str);
    strcat_s(newstr, length + addLength + 1, a);
    delete[] str;
    str = newstr;
    length = length + addLength;
    return *this;
}
MyString& MyString::operator+=(const MyString& obj)
{
	int addLength = obj.length;
    char* newstr = new char[length + addLength + 1] {};
    strcpy_s(newstr, length + 1, str);
    strcat_s(newstr, length + addLength + 1, obj.str);
    delete[] str;
    str = newstr;
    length = length + addLength;
    return *this;
}
MyString& MyString::operator-=(const char* a)
{
    if (a == nullptr || *a == '\0') 
    {
        return *this;
    }
    int subLength = strlen(a);
    if (subLength > length) 
    {
        return *this;
    }
    char* buffer = new char[length + 1] {};
    int bufferIndex = 0;
    int i = 0;
    while (i < length) 
    {
        bool found = true;
        for (int j = 0; j < subLength; j++) {
            if (i + j >= length || str[i + j] != a[j]) {
                found = false;
                break;
            }
        }
        if (found) 
        {
            i += subLength;
        }
        else 
        {
            buffer[bufferIndex] = str[i];
            bufferIndex++;
            i++;
        }
    }
    buffer[bufferIndex] = '\0';
    delete[] str;
    str = buffer;
    length = bufferIndex;
    return *this;
}

bool MyString::operator>(MyString& obj)
{
    return MyStrCmp(obj) > 0;
}
bool MyString::operator<(MyString& obj)
{
    return MyStrCmp(obj) < 0;
}
bool MyString::operator==(MyString& obj)
{
    return MyStrCmp(obj) == 0;
}
bool MyString::operator!=(MyString& obj)
{
    return MyStrCmp(obj) != 0;
}
bool MyString::operator>=(MyString& obj)
{
    return MyStrCmp(obj) >= 0;
}
bool MyString::operator<=(MyString& obj)
{
    return MyStrCmp(obj) <= 0;
}


MyString& MyString::operator=(const MyString& obj)
{
    if (this == &obj) 
    {
        return *this;
    }
    
    if (str != nullptr)
    {
		delete[] str;
    }
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
    return *this;
}

MyString& MyString::operator=(MyString&& obj)
{
    if (str != nullptr)
    {
        delete[] str;
    }
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = 0;
	return *this;

}



ostream& operator<<(ostream& os, const MyString& obj)
{
    os << obj.str;
	return os;
}

istream& operator>>(istream& is, const MyString& obj)
{
    is >> obj.str;
	return is;
}


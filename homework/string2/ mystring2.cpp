//File: mystring1.cpp
// ================
// Implementation file for user-defined String class.
#include "mystring2.h"
#pragma warning(disable:4996)   // disbale the unsafe warning message to use strcpy_s(), etc


String::String()
{
  contents = new char[1];
  contents[0] = '\0';
  len = 0;
}

// change this to dynamic
String::String(const char s[])
{
    len = strlen(s);
    contents = new char[len];
    for (int i = 0; i <= len; i++) {
      contents[i] = s[i];
    }
}
String::~String() {
    delete [] contents; 
}

void String::append(const String &str)
{
  strcat(contents, str.contents);
  len += str.len;
}

String & String::operator=(const String &str) {
    if (this != &str)    // check for list = list
   {
        delete[] contents;
        len = str.len;

        contents = new char[len];
   //--- Copy origList's array into this new array
        for(int i = 0; i < len; i++)
            contents[i] = str.contents[i];
   }
   return *this;
}

String::String(const String &str) {
    len = str.len; 
    contents = new char[len]; 
    for(int i = 0; i < len; i++) 
        contents[i] = str.contents[i]; 
}

bool String::operator ==(const String &str) const
{
  return strcmp(contents, str.contents) == 0;
}

bool String::operator !=(const String &str) const
{
  return strcmp(contents, str.contents) != 0;
}

bool String::operator >(const String &str) const
{
  return strcmp(contents, str.contents) > 0;
}

bool String::operator <(const String &str) const
{
  return strcmp(contents, str.contents) < 0;
}


bool String::operator >=(const String &str) const
{
  return strcmp(contents, str.contents) >= 0;
}

String String::operator +=(const String &str)
{
    append(str);
    return *this;
}

void String::print(ostream &out) const
{
  out << contents;
}

int String::length() const
{
return len;
}
char String::operator [](int i) const
{
if (i < 0 || i >= len) {
cerr << "can't access location " << i
<< " of string \"" << contents << "\"" << endl;
return '\0';
}
return contents[i];
}
ostream & operator<<(ostream &out, const String & s) // overload ostream operator "<<" - External!
{
s.print(out);
return out;
}

/*
str1 holds "" (length = 0)
str2 holds "init2" (length = 5)
str3 holds "init3" (length = 5)

Enter a value for str1 (no spaces): red

Enter a value for str2 (no spaces): yellow

Enter a value for str3 (no spaces): blue

After assignments...
str1 holds "red" (length = 3)
str2 holds "yellow" (length = 6)
str3 holds "blue" (length = 4)

Enter which element of str1 to display: 1
Element #1 of str1 is 'e'

Enter which element of str2 to display: 2
Element #2 of str2 is 'l'

Enter which element of str3 to display: 3
Element #3 of str3 is 'e'

Enter a value to append to str1 (no spaces): rose

Enter a value to append to str2 (no spaces): house

Enter a value to append to str3 (no spaces): sky

After appending...
str1 holds "redrose" (length = 7)
str2 holds "yellowhouse" (length = 11)
str3 holds "bluesky" (length = 7)

Comparing str1 and str2...
"redrose" is less than "yellowhouse"

test the = operator, after str1 = str2; 
str1 holds "yellowhouse" (length = 11)
str2 holds "yellowhouse" (length = 11)

After str1 = str1 + s1: 
str1 holds "yellowhouserose" (length = 15)
str2 holds "yellowhouse" (length = 11)

test the copy constructor, after str4(str3);
str3 holds "bluesky" (length = 7)
str4 holds "bluesky" (length = 7)

after appending str3 by str2
str3 holds "blueskyyellowhouse" (length = 18)
str4 holds "bluesky" (length = 7)

str2, str4 are not changed. Type any letter to quit.
*/
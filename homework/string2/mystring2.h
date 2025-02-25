#pragma once
#include <iostream>
#include <cstring>  // for strlen(), etc.
using namespace std;
#define MAX_STR_LENGTH  200


class String {
public:
  String();
  String(const char s[]);  // a conversion constructor   
  void append(const String &str);
  ~String();
  String & operator=(const String &str);
  String(const String &str);

  // Relational operators
  bool operator ==(const String &str) const;    
  bool operator !=(const String &str) const;   
  bool operator >(const String &str) const;    
  bool operator <(const String &str) const;    
  bool operator >=(const String &str) const; 
  String operator +=(const String &str);      

  void print(ostream &out) const;    
  int length() const;

  char operator [](int i) const;  // subscript operator  

private:
    char *contents;
    int len;
};

ostream & operator<<(ostream &out, const String & r); 

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
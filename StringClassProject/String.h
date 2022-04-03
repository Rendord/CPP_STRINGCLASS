#pragma once
#include <iostream>
#include <ostream>

class String {
private:
	int len;
	char* str = new char[len + 1];
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const String& s);
	String& operator+=(const String& s);
	char operator[](const int) const;
	void replace(const int begin, const int end, const String&);
	bool search(const String) const;
	String& toupper() const;
	String& tolower() const;

	char* toString() const;
	int length() const;
};

bool operator ==(const String&, const String&);
bool operator !=(const String&, const String&);
bool operator >(const String&, const String&);
bool operator <(const String&, const String&);
//String operator+(const String&, const String&);
//std::ostream& operator<<(std::ostream&, const String&);
#pragma once

class String {
private:
	int len;
	char* str = new char[len+1];
public:
	String();
	String(const char* s);
	String(String& s);
	String& operator=(String& s);
	~String();
	char* toString();
	int length();
};

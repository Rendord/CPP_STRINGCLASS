#include "String.h"
#include <iostream>


int len;
char* str;

String::String() {
	//cout << "  String::String() " <<
} 

String::String(const char* str) {
	while (*str != '\0') {
		
	}
	str = new char[len + 1]
} 

String::String(String& s) {
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		str[i] = s.str[i];
	}
}

String& String::operator=(String& s) {
	len = s.len;
	if (str != nullptr) 
		delete[] str;
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
		str[i] = s.str[i];
	return *this;
}

String::~String() {
	if (str != nullptr)
		delete[] str;
}
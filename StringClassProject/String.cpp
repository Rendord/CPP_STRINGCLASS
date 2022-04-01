#include <iostream>

#include "String.h"




String::String() {
	len = 0;
	str = new char[1];
	str[0] = '\0';
} 

String::String(const char* str) {
	len = 0;
	while (str[len] != '\0') {
		len++;
	}
	this->str = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		this->str[i] = str[i];
	}

	//std::cout << this->str << std::endl;


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

char* String::toString() {

	return str;
}

int String::length() {
	return len;
}
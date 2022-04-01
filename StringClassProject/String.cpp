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

String::String(const String& s) {
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		str[i] = s.str[i];
	}
}

String::~String() {
	if (str != nullptr)
		delete[] str;
}

String& String::operator=(const String& s) {
	len = s.len;
	if (str != nullptr) 
		delete[] str;
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
		str[i] = s.str[i];
	return *this;
}

String& String::operator+=(const String& s) {

	char* replace = new char[len + s.len + 1];
	for (int i = 0; i <= len; i++) {
		replace[i] = s.str[i];
	}	
	for (int i = len + 1; i < len + s.len; i++) {
		replace[i] = s.str[i - len];
	}
	len += s.len;
	if (str != nullptr) {
		delete[] str;
	}
	str = replace;
	return *this;
}

char String::operator[] (const int i) const {
	if (str != nullptr) {
		return str[i];
	}
	else {
		return '\0';
	}
}

void String::replace(const int begin, const int end, const String& s) {
	int replace_len = end - begin + 1;
	int new_len = len - replace_len + s.len;
	char* new_string = new char[new_len];
	for (int i = 0; i < begin -1; i++) {
		new_string[i] = str[i];
	}
	for (int i = 0; i < s.len; i++) {
		new_string[]
	}
}

char* String::toString() const{

	return str;
}

int String::length() const{
	return len;
}
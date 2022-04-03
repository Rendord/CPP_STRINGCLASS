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
	str = new char[len];
	for (int i = 0; i < len; i++) {
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
	char* new_string = new char[new_len + 1];
	for (int i = 0; i < new_len; i++) {
		if (i < begin - 1) {
			new_string[i] = str[i];
		}
		if (i >= begin - 1 && i < begin + s.len - 1) {
			new_string[i] = s.str[i - (begin - 1)];
		}
		if (i >= begin + s.len - 1 && i < new_len) {
			new_string[i] = str[i - (s.len - replace_len)];
		}

	}
	new_string[new_len] = '\0';
	//deprecated
	//for (int i = 0; i < begin - 1; i++) {
	//	new_string[i] = str[i];
	//}
	//for (int i = 0; i < s.len; i++) {
	//	new_string[begin - 1 + i] = s.str[i];
	//}
	//for (int i = 0; i < len - end; i++) {
	//	new_string[begin + replace_len - 1 + i] = str[end + i];
	//}
	if (str != nullptr) {
		delete[] str;
	}
	str = new_string;
	len = new_len;
}

bool String::search(const String s) const {
	bool haha_yes = false;
	int space_left = len;
	for (int i = 0; i < len; i++) 
	{
		if (space_left - s.len < 0)
			return false;
		if (str[i] == s.str[0]) 
		{
			for (int j = 0; j < s.len; j++) 
			{
				if (str[i + j] == s.str[j]) 
				{
					haha_yes = true;
				}
				else 
				{
					haha_yes = false;
					break;
				}
			}
		}
		if (haha_yes)
			return haha_yes;
		space_left--;
	}
	return haha_yes;
}

String& String::toupper() const {
	String upper = *this;
	for (int i = 0; i < len; i++) {
		//upper.str[i] = str[i];
		if(str[i] > 64 && str[i] < 123)
			str[i] -= 32;
	}
	return upper;
}

String& String::tolower() const {
	String lower = *this; 
	for (int i = 0; i < len; i++) {
		//lower.str[i] = str[i];
		if (str[i] > 64 && str[i] < 123)
			str[i] += 32;
	}
	return lower;
}

char* String::toString() const{

	return str;
}

int String::length() const{
	return len;
}

#include "String.h"

bool operator==(const String& lhs, const String& rhs) {
	if (lhs.length() != rhs.length()) {
		return false;
	}
	for (int i = 0; i < lhs.length(); i++) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}
//bool operator==(const String&, const String&)
//{
//	return true;
//}
bool operator!=(const String& lhs, const String& rhs) {
	/*return !(lhs == rhs);*/
	if (lhs.length() != rhs.length())
		return true;
	for (int i = 0; i < lhs.length(); i++)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}
bool operator>(const String& lhs, const String& rhs) {
	bool haha_yes = false; 
	for (int i = 0; i < lhs.length(); i++)
	{
		
		if (lhs[i] > rhs[i]) {
			haha_yes = true;
			break;
		}
		if (lhs[i] < rhs[i]) {
			haha_yes = false;
			break;
		}

	}
	return haha_yes;
}
bool operator<(const String& lhs, const String& rhs) {
	return !(lhs > rhs);
	//bool haha_yes = false; 
	//for (int i = 0; i < lhs.length(); i++)
	//{
	//	std::cout << "a";
	//	if (lhs[i] < rhs[i])
	//		haha_yes = true;
	//	if (lhs[i] > rhs[i])
	//		haha_yes = false;
	//}
	//return haha_yes;
}

String operator+(const String& lhs, const String& rhs) {
	char* innerstring = new char[lhs.length() + rhs.length() + 1];
	for (int i = 0; i < lhs.length() + rhs.length(); i++) {
		if (i < lhs.length()) {
			innerstring[i] = lhs[i];
		}
		if (i >= lhs.length()) {
			innerstring[i] = rhs[i - lhs.length()];
		}
	}
	innerstring[lhs.length() + rhs.length()] = '\0';

	return String(innerstring);
}


std::ostream& operator<<(std::ostream& stream, const String& rhs) {
	return stream << rhs.toString();
}





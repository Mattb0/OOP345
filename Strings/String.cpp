#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict {

	void String::deallocate() {
		data_ = nullptr;
		memSize_ = 0;
	}

	void String::allocate(int memsize) {
		deallocate();
		data_ = new char[memsize];
		data_[0] = '\0';
		memSize_ = memsize;
	}

	void String::resize(int memsize) {
		char* temp;
		temp = new char[memsize];

		if (data_ == nullptr)
		{
			temp[0] = '\0';

		}
		else
		{
			if (strlen(data_) >= memsize) {
				len_ = memsize - 1;
			}
			strncpy(data_, temp, len_);
			temp[len_] = '\0';
		}

		deallocate();
		memSize_ = memsize;
		data_ = temp;
	}

	String::String() {
		deallocate();
		len_ = 0;
	}

	void String::init(const char* str, int memSize) {
		int msize;
		len_ = strlen(str);
		if (memSize <= len_)
		{

			msize = len_ + 1;

		}
		else
		{
			msize = memSize;
		}
		memSize_ = msize;
		data_ = new char[msize];
		strncpy(data_, str, len_);
		data_[len_] = '\0';
	}

	String::String(const char* str, int memSize) {
		init(str, memSize);
	}

	String::String(const String& S) {
		init(S.data_, S.memSize_);
	}

	String& String::operator=(const String& S) {
		if (this != &S)
		{
			deallocate();
			init(S.data_, S.memSize_);

		}
		return *this;
	}

	String::~String() {
		deallocate();
	}

	int String::length()const {
		return len_;
	}

	int String::memSize()const {

		return memSize_;
	}

	String::operator const char *()const {
		return data_;
	}
	
	istream& String::read(istream& istr)
	{
		int i = 0;
		char c;
		c = istr.get();

		while (c != '\n') {

			if (i >= memSize()) {
				resize(memSize() + ExpansionSize);
			}

			data_[i] = c;

			i++;
			c = istr.get();
		}
		data_[i] = '\0';
		return istr;
	}

	// operator overloads
	String& String::operator+=(const char* str)
	{
		int strLen = strlen(str);
		if (strLen + len_ + 1 > memSize_) {
			resize(strLen + len_ + 1);
		}
		strcpy(data_, str);

		return *this;
	}

	String& String::operator+=(String& s)
	{
		this->operator+=(s.data_);
		return *this;
	}

	String String::operator+(const String & s) const
	{
		String *temp = new String(*this);
		temp->operator+=(s);
		return *temp;
	}

	String& String::operator++() {
		String *newString = new String(" ");
		*newString += *this;
		return *newString;
	}

	String String::operator++(int S)
	{
		String *newString = new String(*this);
		*newString += " ";
		return *newString;
	}

	char& String::operator[](int index)
	{
		if (index >= memSize())
		{
			resize(memSize() + ExpansionSize);

		}
		return data_[index];
	}

	String::operator int()const
	{
		int length;
		length = sizeof(data_);
		return length;
	}

	std::ostream& operator<<(std::ostream& ostr, const String &s) {
		const char* str = (const char*)s;
		if (str != nullptr) {
			int i = 0;
			while (str[i] != '\0') {
				cout << str[i];
				i++;
			}
		}
		else 
		{
			cout << "undefined";
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& ostr, String &s)
	{
		ostr >> s;
		return ostr;
	}
}
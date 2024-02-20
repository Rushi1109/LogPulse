#include<cstring>

#include "./String.h"
#include "../include/Exception.h"

using Type::String;

unsigned int String::getLength(const char* str) {		// working
	auto m_Size{ 0U };

	while (str[m_Size] != '\0') {
		m_Size++;
	}
	
	return m_Size;
}

const char* String::getRaw() const {
	char* rawCharPointer = new char[m_Size + 1];
	memcpy(rawCharPointer, m_Buffer.get(), m_Size + 1);
	return rawCharPointer;
}

String::String() {			// working
	m_Size = 0;
	m_Buffer = std::make_unique<char[]>(m_Size + 1);
	m_Buffer[m_Size] = '\0';
}

String::String(const char* str) {		// working
	m_Size = getLength(str);
	m_Buffer = std::make_unique<char[]>(m_Size + 1);
	memcpy(m_Buffer.get(), str, m_Size);
	m_Buffer[m_Size] = '\0';
}


String::String(const String& str) {		// working
	m_Size = str.m_Size;
	m_Buffer = std::make_unique<char[]>(m_Size + 1);
	memcpy(m_Buffer.get(), str.m_Buffer.get(), m_Size + 1);
}


String& String::operator=(const String& str) {		// working
	if (this != &str) {
		m_Size = str.m_Size;
		m_Buffer = std::make_unique<char[]>(m_Size + 1);
		memcpy(m_Buffer.get(), str.m_Buffer.get(), m_Size + 1);
	}

	return *this;
}

String::String(String&& str) noexcept {		// working
	m_Size = str.m_Size;
	m_Buffer = std::move(str.m_Buffer);

	// Very Important when using move semantic
	str.m_Size = 0;
	str.m_Buffer = nullptr;
}

String& String::operator=(String&& str) noexcept {		// working
	if (this != &str) {
		m_Size = str.m_Size;
		m_Buffer = std::move(str.m_Buffer);

		// Very Important when using move semantic
		str.m_Size = 0;
		str.m_Buffer = nullptr;
	}

	return *this;
}

char& String::at(unsigned int index) const {
	if (index < 0 || index >= m_Size) {
		throw Exception::IndexOutOfBoundException("String index " + std::to_string(index) + " is invalid");
	}
	return m_Buffer.get()[index];
}

char& String::operator[](unsigned int index) const {
	return m_Buffer.get()[index];
}

String& String::append(const String& str) {		// working
	auto newBuffer = std::make_unique<char[]>(m_Size + str.m_Size + 1);
	
	memcpy(newBuffer.get(), m_Buffer.get(), m_Size);
	memcpy(newBuffer.get() + m_Size, str.m_Buffer.get(), str.m_Size + 1);

	m_Size = m_Size + str.m_Size;
	m_Buffer = std::move(newBuffer);
	
	//Very important
	newBuffer = nullptr;

	return *this;
}

String& String::toLowerCase() {		// working
	for (auto i = 0U; i < m_Size; i++) {
		if (m_Buffer[i] >= 65 && m_Buffer[i] <= 90) {
			m_Buffer[i] += 32;
		}
	}
	return *this;
}

String& String::toUpperCase() {		// working
	for (auto i = 0U; i < m_Size; i++) {
		if (m_Buffer[i] >= 97 && m_Buffer[i] <= 122) {
			m_Buffer[i] -= 32;
		}
	}
	return *this;
}

String String::toString(int num) {		// working
	auto temp{ num };
	auto size{ 0U };
	auto isNegative{ (num < 0) };

	while (temp != 0) {
		temp /= 10;
		size++;
	}

	if (isNegative) {
		size++;
		temp = -num;
	}
	else {
		temp = num;
	}

	auto tempStr{ new char[size + 1] };
	tempStr[size] = '\0';

	if (isNegative) {
		tempStr[0] = '-';
	}

	for (auto i = size - 1; i >= 0 && temp != 0; i--) {
		auto digit = temp % 10;
		temp /= 10;
		tempStr[i] = digit + '0';
	}

	return String{ tempStr };
}

static void swap(char& a, char& b) noexcept {
	auto temp = a;
	a = b;
	b = temp;
}

void String::reverseString(String& str) {		// working
	auto start{ 0 };
	auto end{ str.length()-1 };

	while (start < end) {
		swap(str[start], str[end]);
		start++; end--;
	}

	return;
}
 
String Type::operator+(const String& str1, const String& str2) {		// working
	auto newBuffer = std::make_unique<char[]>(str1.m_Size + str2.m_Size + 1);

	memcpy(newBuffer.get(), str1.m_Buffer.get(), str1.m_Size);
	memcpy(newBuffer.get() + str1.m_Size, str2.m_Buffer.get(), str2.m_Size + 1);

	String tempStr{ newBuffer.get() };
	newBuffer = nullptr;

	return tempStr;
}

bool Type::operator==(const String& str1, const String& str2) {		// working
	if (str1.m_Size != str2.m_Size)	return false;

	for (unsigned int i = 0; i < str1.m_Size; i++) {
		if (str1[i] != str2[i])	return false;
	}

	return true;
}

std::ostream& Type::operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}
#ifndef _string_h_
#define _string_h_

#include <iostream>

namespace Type {
	class String {
	public:
		String();		// Default Constructor

		String(const char*);		// Parameterized Constrcutor

		String(const String&);		// Copy Constructor

		String& operator=(const String&);		// Copy Assignment

		String(String&&) noexcept;		// Move Constructor

		String& operator=(String&&) noexcept;		// Move Assignment

		~String() = default;

		int length() const {
			return m_Size;
		}

		const char* getRaw() const;

		char& at(unsigned int index) const;
		char& operator[](unsigned int index) const;
		
		String& append(const String&);
		String& toLowerCase();
		String& toUpperCase();

		static String toString(int);
		static void reverseString(String&);
		
		friend String operator+(const String&, const String&);
		friend bool operator==(const String&, const String&);
		friend std::ostream& operator<<(std::ostream&, const String&);

	private:
		static unsigned int getLength(const char*);

		std::unique_ptr<char[]> m_Buffer;
		unsigned int m_Size;
	};
}

#endif

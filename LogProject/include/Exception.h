#ifndef _exception_h_
#define _exception_h_

#include "String.h"
using Type::String;

namespace Exception {
	class MyException {
	protected:
		String m_Message;

	public:
		MyException(const String& message="Exception occured!!") : m_Message{message} {}

		virtual String getMessage() const {
			return m_Message;
		};

		virtual ~MyException() = default;
	};

	class InvalidDateException : public MyException {
	public:
		InvalidDateException(const String& message = "") : MyException{message} {}

		virtual String getMessage() const override {
			return "[InvalidDateException]: " + m_Message;
		}
	};

	class IndexOutOfBoundException : public MyException {
	public:
		IndexOutOfBoundException(const String& message = "") : MyException{message} {}

		virtual String getMessage() const override {
			return "[IndexOutOfBoundException]: " + m_Message;
		}
	};
}


#endif

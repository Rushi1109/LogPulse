#ifndef _exception_h_
#define _exception_h_

#include <string>

namespace Exception {
	using std::string;
	class MyException {
	public:
		MyException(const string& message="Exception occured!!") : m_Message{message} {}

		virtual string getMessage() const {
			return m_Message;
		};

		virtual ~MyException() = default;

	protected:
		string m_Message;
	};

	class InvalidDateException : public MyException {
	public:
		InvalidDateException(const string& message = "") : MyException{message} {}

		virtual string getMessage() const override {
			return "[InvalidDateException]: " + m_Message;
		}
	};

	class IndexOutOfBoundException : public MyException {
	public:
		IndexOutOfBoundException(const string& message = "") : MyException{message} {}

		virtual string getMessage() const override {
			return "[IndexOutOfBoundException]: " + m_Message;
		}
	};
}


#endif

#ifndef _date_h_
#define _date_h_

#include <string>

namespace Utility {
	class Date {
	public:
		explicit Date(int dd=1, int mm=1, int yy=1970) : m_Day{ dd }, m_Month{ mm }, m_Year{ yy }, m_IsCacheValid{ false }, m_StrDate{ computeStrDate() } {};

		
		int getDay() const {
			return m_Day;
		}

		
		int getMonth() const {
			return m_Month;
		}

		
		int getYear() const {
			return m_Year;
		}

		void setDay(const int& dd);
		void setMonth(const int& mm);
		void setYear(const int& yy);

		void setDate(int, int, int);
		Date& addYear(const int&);

		std::string getStrDate() const;

		static Date& getCurrentDate();

	private:
		std::string computeStrDate() const;


		int m_Day;
		int m_Month;
		int m_Year;
		mutable bool m_IsCacheValid;
		mutable std::string m_StrDate;

		bool isLeapYear(const int&) const;
		bool isDateValid(const int&, const int&, const int&) const;
	};
}


#endif
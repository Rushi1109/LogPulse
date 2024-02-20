#include<iostream>
#include "../include/Date.h"
#include "../include/Exception.h"

using Utility::Date;

bool Date::isLeapYear(const int& yy) const {
	return ((yy % 400) == 0) || ((yy % 4 == 0) && (yy % 100 != 0));
}

bool Date::isDateValid(const int& dd, const int& mm, const int& yy) const {
	if (yy < 1) {
		throw Exception::InvalidDateException{ "Year " + std::to_string(yy) + " is invalid" };
	};
	if (mm < 1 || mm > 12) {
		throw Exception::InvalidDateException{ "Month " + std::to_string(mm) + " is invalid" };
	};
	if (dd < 1 || dd > 31) {
		throw Exception::InvalidDateException{ "Day " + std::to_string(dd) + " is invalid" };
	};

	if (mm == 2) {
		if (isLeapYear(yy)) {
			if (dd > 29) throw Exception::InvalidDateException{ "Day " + std::to_string(dd) + " is invalid" };
		}
		else {
			if (dd > 28) throw Exception::InvalidDateException{ "Day " + std::to_string(dd) + " is invalid" };
		}
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		if (dd > 30) throw Exception::InvalidDateException{ "Day " + std::to_string(dd) + " is invalid" };
	};

	return true;
}

void Date::setDay(const int& dd) {
	if (isDateValid(dd, m_Month, m_Year)) {
		m_Day = dd;
		m_IsCacheValid = false;
	}
}

void Date::setMonth(const int& mm) {
	if (isDateValid(m_Day, mm, m_Year)) {
		m_Month = mm;
		m_IsCacheValid = false;
	}
}

void Date::setYear(const int& yy) {
	if (isDateValid(m_Day, m_Month, yy)) {
		m_Year = yy;
		m_IsCacheValid = false;
	}
}

void Date::setDate(int dd, int mm, int yy) {
	if (isDateValid(dd, mm, yy)) {
		m_Day = dd;
		m_Month = mm;
		m_Year = yy;
	}
}

Date& Date::addYear(const int& yy) {
	m_Year += yy;
	return *this;
}

std::string Date::getStrDate() const {
	if (!m_IsCacheValid) {
		m_StrDate = computeStrDate();
		m_IsCacheValid = true;
	}
	return m_StrDate;
}

std::string Date::computeStrDate() const {
	return (m_Day < 10 ? "0" : "") + std::to_string(m_Day) + "/" + (m_Month < 10 ? "0" : "") + std::to_string(m_Month) + "/" + std::to_string(m_Year);
}

Date& Date::getCurrentDate() {
	static Date date{ 20, 02, 2024 };
	return date;
}
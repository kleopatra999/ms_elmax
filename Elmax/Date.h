#pragma once

#include <ctime>
#include <string>

namespace Elmax
{
//! Simple rudimentary date class
//! Feel free to modify to your needs
//! Note: Regex is not used to validate the date string in SetString method
//! because regex could take a long time building the regex tree in
//! constructor if user instantiate many of this class.
class Date
{
public:
	//! Default constructor
	Date(void);
	//! Non-default constructor
	Date(std::time_t time_in_sec, bool utc);
	//! Non-default constructor
	Date(short year, short month, short day);
	//! Destructor
	~Date(void);

	void SetYear(short year) { m_nYear = year; }
	void SetMonth(short month) { m_nMonth = month; }
	void SetMonthDay(short day) { m_nMonthDay = day; }

	short GetYear() { return m_nYear; }
	short GetMonth() { return m_nMonth; }
	short GetMonthDay() { return m_nMonthDay; }

	//! Set date, note: throws std::logic_error when date is invalid!
	bool SetDate(short year, short month, short day);

	//! Set date, note: throws std::logic_error when strDate is invalid date string!
	void SetString(const std::wstring& strDate);

	//! Get the date string eg, "2010-10-01"
	std::wstring GetString() const;

private:
	static void GetTime(time_t time_in_sec, short& year, short& mon, short& mday);
	static void GetUTCTime(time_t time_in_sec, short& year, short& mon, short& mday);

	short m_nYear;
	short m_nMonth; // [1 - 12]
	short m_nMonthDay; // [1 - 31]
};

} // ns Elmax

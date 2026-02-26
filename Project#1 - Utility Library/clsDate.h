#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include "clsString.h"
#include <string>

using namespace std;
class clsDate
{

private:
	struct _stDate { short Day, Month, Year; };
	_stDate _Date;

	bool IsLeapYear(_stDate& Date) {
		return ((Date.Year % 400 == 0) || (Date.Year % 4 == 0 && Date.Year % 100 != 0));
	}


	short DaysInAMonth(_stDate& Date) {
		if (Date.Month > 12 || Date.Month < 1 || Date.Year < 0)
			return 0;

		short Months[12] = { 31,0,31,30,31,31,31,31,30,31,30,31 };

		return (Date.Month == 2) ? (IsLeapYear(Date) ? 29 : 28) : Months[Date.Month - 1];
	}

	bool IsLastDayInAMonth(_stDate& Date) {

		return Date.Day == DaysInAMonth(Date);

	}


	bool IsLastDayInAYear(_stDate& Date) {
		return Date.Month == 12 && IsLastDayInAMonth(Date);
	}

	void IncreaseDateByOneDay(_stDate& Date) {

		if (IsLastDayInAYear(Date)) {
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else if (IsLastDayInAMonth(Date)) {
			Date.Day = 1;
			Date.Month++;
		}
		else {
			Date.Day++;
		}

	}



	void DaysToDate(short NumberOfDays, _stDate& Date) {
		while (NumberOfDays > (IsLeapYear(Date) ? 366 : 365)) {
			NumberOfDays -= (IsLeapYear(Date) ? 366 : 365);
			Date.Year++;
		}
		while (NumberOfDays > DaysInAMonth(Date)) {

			NumberOfDays -= DaysInAMonth(Date);
			Date.Month++;

		}
		Date.Day = NumberOfDays;

	}
public:

	clsDate(short Day, short Month, short Year) : _Date{ Day,Month,Year } {}
	clsDate(short NumberOfDays, short Year) {
		_Date.Day = 1;
		_Date.Month = 1;
		_Date.Year = Year;
		DaysToDate(NumberOfDays, _Date);
	}

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Date.Day = now->tm_mday;
		_Date.Month = now->tm_mon + 1;
		_Date.Year = now->tm_year + 1900;
	}

	clsDate(const string& Date) {
		vector<string> vDate = clsString::SeperateWords(Date, "/");
		if (vDate.size() == 3)
		{
			_Date.Day = stoi(vDate[0]);
			_Date.Month = stoi(vDate[1]);
			_Date.Year = stoi(vDate[2]);
		}



	}
	void setDay(short Day) { _Date.Day = Day; }
	void setMonth(short Month) { _Date.Month = Month; }
	void setYear(short Year) { _Date.Year = Year; }

	void Print() {
		cout << _Date.Day << "/" << _Date.Month << "/" << _Date.Year << endl;
	}

	static void  SwapDates(clsDate& Date1, clsDate& Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

};

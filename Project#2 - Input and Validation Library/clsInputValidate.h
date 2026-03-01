#pragma once
#include "clsDate.h"

class clsInputValidate
{


public:

	static bool IsNumberBetween(short Number, short From, short To) {

		return (Number >= From && Number <= To);

	}

	static bool IsNumberBetween(int Number, int From, int To) {
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To) {
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To) {
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(const clsDate& Date, const clsDate& Date1, const clsDate& Date2) {
		return
			((clsDate::IsDate1AfterDate2(Date, Date1) || clsDate::IsDate1EqualsDate2(Date, Date1)) &&
				(clsDate::IsDate1BeforeDate2(Date, Date2) || clsDate::IsDate1EqualsDate2(Date, Date2)))
			||
			((clsDate::IsDate1AfterDate2(Date, Date2) || clsDate::IsDate1EqualsDate2(Date, Date2)) &&
				(clsDate::IsDate1BeforeDate2(Date, Date1) || clsDate::IsDate1EqualsDate2(Date, Date1)));
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}
};


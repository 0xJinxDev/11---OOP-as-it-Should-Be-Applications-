#pragma once
#include "clsPerson.h"
class clsBankClient : public clsPerson
{
private:
	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _AccountNumber;
	string _PINCode;
	float _Balance;

public:

    clsBankClient(enMode Mode,
        const string& FirstName,
        const string& LastName,
        const string& Email,
        const string& Phone,
        const string& AccountNumber,
        const string& PINCode,
        float Balance)
        : clsPerson(FirstName, LastName, Email, Phone),
        _Mode(Mode),
        _AccountNumber(AccountNumber),
        _PINCode(PINCode),
        _Balance(Balance) {}



};


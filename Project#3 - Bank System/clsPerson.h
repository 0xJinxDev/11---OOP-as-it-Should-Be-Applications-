#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{

private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(const string& FirstName, const string& LastName, const string& Email, const string& Phone) :
		_FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone){}


	void setFirstName(const string& FirstName) { _FirstName = FirstName; }
	void setLastName(const string& LastName) { _LastName = LastName; }
	void setEmail(const string& Email) { _Email = Email; }
	void setPhone(const string& Phone) { _Phone = Phone; }

	string getFirstName() const { return _FirstName; }
	string getLastName() const { return _LastName; }
	string getEmail() const { return _Email; }
	string getPhone() const { return _Phone; }

};


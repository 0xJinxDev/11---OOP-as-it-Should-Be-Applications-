#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
{

private:
	static void _ReadClientInfo(clsBankClient& Client) {

		Client.setFirstName(clsInputValidate::ReadString("Please enter first name:"));
		Client.setLastName(clsInputValidate::ReadString("Please enter last name:"));
		Client.setEmail(clsInputValidate::ReadString("Please enter email:"));
		Client.setPhone(clsInputValidate::ReadString("Please enter phone:"));
		Client.setPINCode(clsInputValidate::ReadString("Please enter PIN:"));
		Client.setBalance(clsInputValidate::ReadFloatNumber("Please enter balance:"));
	}

	static void _PrintClient(clsBankClient& Client) {
		cout << "\n\nClient Information:";
		cout << "\nFirst name:    " << Client.getFirstName();
		cout << "\nLast name:     " << Client.getLastName();
		cout << "\nEmail:         " << Client.getEmail();
		cout << "\nPhone:         " << Client.getPhone();
		cout << "\nAccount number:" << Client.getAccountNumber();
		cout << "\nPIN:           " << Client.getPINCode();
		cout << "\nBalance:       " << Client.getBalance();
		cout << endl;

	}

public:


	static void ShowAddNewClientScreen() {

		_DrawScreenHeader("Add new client");

		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString("Please enter the new account number:");
		while (clsBankClient::isClientExist(AccountNumber)) {
			cout << "Account number is already in use!\n";
			AccountNumber = clsInputValidate::ReadString("Please enter the new account number:");
		}

		clsBankClient NewClient = clsBankClient::getAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveStatus enStatus = NewClient.Save();

		switch (enStatus) {

		case clsBankClient::Success:
			cout << "Client Added successfully!" << endl;
			_PrintClient(NewClient);
			break;
		case clsBankClient::AccountAlreadyExist:
			cout << "Client with this id already in use" << endl; break;
		}

	}

};


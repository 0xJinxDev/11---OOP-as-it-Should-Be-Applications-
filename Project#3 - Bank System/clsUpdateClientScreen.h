#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
class clsUpdateClientScreen : protected clsScreen
{

private:


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

	static void _ReadClientInfo(clsBankClient& Client) {

		Client.setFirstName(clsInputValidate::ReadString("Please enter first name:"));
		Client.setLastName(clsInputValidate::ReadString("Please enter last name:"));
		Client.setEmail(clsInputValidate::ReadString("Please enter email:"));
		Client.setPhone(clsInputValidate::ReadString("Please enter phone:"));
		Client.setPINCode(clsInputValidate::ReadString("Please enter PIN:"));
		Client.setBalance(clsInputValidate::ReadFloatNumber("Please enter balance:"));
	}

public:


	static void ShowUpdateClientScreen() {
		_DrawScreenHeader("Update Client");

		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString("Please enter the account number to update:");
		while (!clsBankClient::isClientExist(AccountNumber)) {
			cout << "Account does not exist!\n";
			AccountNumber = clsInputValidate::ReadString("Please enter the account number to update:");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "Update Client Info" << endl;
		cout << "__________________" << endl;

		_ReadClientInfo(Client);

		clsBankClient::enSaveStatus enStatus = Client.Save();

		switch (enStatus) {

		case clsBankClient::Success:
			cout << "Client updated successfully!" << endl; break;
		case clsBankClient::FailedEmptyObject:
			cout << "Saving client failed due to empty object" << endl; break;
		}

	}
};


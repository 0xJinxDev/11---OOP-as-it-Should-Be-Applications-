#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
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
public:

	static void ShowDeleteClient() {

		_DrawScreenHeader("Delete Client");
		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString("Please enter the account number to delete:");
		while (!clsBankClient::isClientExist(AccountNumber)) {
			cout << "Client not found!!\n";
			AccountNumber = clsInputValidate::ReadString("Please enter the account number to delete:");
		}

		clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);

		_PrintClient(DeleteClient);

		cout << "Are you sure you want to delete the client ? (y/n)\n";
		char choice = 'n';

		cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			DeleteClient.Delete();
			if (DeleteClient.isDeleted())
			{
				cout << "Client deleted successfully!\n";
			}
			else
			{
				cout << "Client not deleted\n";
			}


		}
		else {
			cout << "You have choosen to not delete the client\n";
		}
	}
};


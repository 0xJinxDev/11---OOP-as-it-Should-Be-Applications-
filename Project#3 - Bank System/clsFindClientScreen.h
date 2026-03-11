#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsFindClientScreen : protected clsScreen
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


    static void ShowFindClientScreen() {

        _DrawScreenHeader("Find Client");

        string AccountNumber;
        char Flag = 'Y';

        while (Flag == 'Y' || Flag == 'y') {

            AccountNumber = clsInputValidate::ReadString("Please enter the account number:");

            if (clsBankClient::isClientExist(AccountNumber)) {

                clsBankClient Client = clsBankClient::Find(AccountNumber);
                _PrintClient(Client);
                return;
            }

            cout << "Client not found!\n";
            Flag = clsInputValidate::ReadChar("Do you want to try again? (Y/N)");
        }
    }
};


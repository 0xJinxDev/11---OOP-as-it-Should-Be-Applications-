#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("Please enter account number");
        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen() {

        _DrawScreenHeader("Withdraw");

        string AccountNumber = "";

        char Flag = 'Y';

        while (Flag == 'Y' || Flag == 'y') {

            AccountNumber = _ReadAccountNumber();

            if (clsBankClient::isClientExist(AccountNumber)) {
                clsBankClient Client = clsBankClient::Find(AccountNumber);
                _PrintClient(Client);

                double amount = 0;
                char Confirm = 'Y';

                amount = clsInputValidate::ReadDoubleNumberGreatertThan(0, "Please enter the amount you want to withdraw:");

                if (amount > Client.getBalance()) {
                    cout << "Insufficient balance! Your current balance is: " << Client.getBalance() << endl;
                    Flag = clsInputValidate::ReadChar("Do you want to try another amount? (Y/N)");
                    continue;
                }

                Confirm = clsInputValidate::ReadChar("Are you sure you want to withdraw " + to_string(amount) + " ? (Y/N)");

                if (Confirm == 'Y' || Confirm == 'y') {

                    cout << (Client.Withdraw(amount) ? "Withdrawal of amount " + to_string(amount) + " is successful. The new balance is: " + to_string(Client.getBalance())
                        : "Operation Failed");

                }
                else {
                    cout << "Operation cancelled" << endl;
                }

                return;

            }

            cout << "Client not found!\n";
            Flag = clsInputValidate::ReadChar("Do you want to try again? (Y/N)");
        }

    }
};
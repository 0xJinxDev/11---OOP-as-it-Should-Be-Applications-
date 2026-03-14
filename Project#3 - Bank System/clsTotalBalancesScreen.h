#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsTotalBalancesScreen
{
private:

	static void _PrintClientRecordBalanceLine(clsBankClient& Client)
	{

		cout << "| " << setw(15) << left << Client.getAccountNumber();
		cout << "| " << setw(40) << left << Client.getFullName();
		cout << "| " << setw(12) << left << Client.getBalance();

	}
public:

	static void ShowTotalBalances() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalances = clsBankClient::getTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient& Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	}
};


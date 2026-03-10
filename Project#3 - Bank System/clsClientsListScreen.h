#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include <string>
class clsClientsListScreen : protected clsScreen
{

private:

	static void  _PrintClientRecordLine(clsBankClient Client)
	{
	
			cout << "| " << setw(15) << left << Client.getAccountNumber();
			cout << "| " << setw(20) << left << Client.getFullName();
			cout << "| " << setw(12) << left << Client.getPhone();
			cout << "| " << setw(20) << left << Client.getEmail();
			cout << "| " << setw(10) << left << Client.getPINCode();
			cout << "| " << setw(12) << left << fixed << setprecision(2) << Client.getBalance();

		


	}
public:

	static void ShowClientsList()
	{

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		const string Title = "\t  List Clients";
		const string SubTitle = "\t  (" + to_string(vClients.size()) + ") Clients.";

		_DrawScreenHeader(Title, SubTitle);
	
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (const clsBankClient& Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};


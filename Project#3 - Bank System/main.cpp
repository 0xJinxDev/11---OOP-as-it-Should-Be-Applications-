#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

void ReadClientInfo(clsBankClient& Client) {

	Client.setFirstName(clsInputValidate::ReadString("Please enter first name:"));
	Client.setLastName(clsInputValidate::ReadString("Please enter last name:"));
	Client.setEmail(clsInputValidate::ReadString("Please enter email:"));
	Client.setPhone(clsInputValidate::ReadString("Please enter phone:"));
	Client.setPINCode(clsInputValidate::ReadString("Please enter PIN:"));
	Client.setBalance(clsInputValidate::ReadFloatNumber("Please enter balance:"));
}
void UpdateClient() {

	string AccountNumber = "";

	AccountNumber = clsInputValidate::ReadString("Please enter the account number to update:");
	while (!clsBankClient::isClientExist(AccountNumber)) {
		cout << "Account does not exist!\n";
		AccountNumber = clsInputValidate::ReadString("Please enter the account number to update:");
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber);

	Client.Print();

	cout << "Update Client Info" << endl;
	cout << "__________________" << endl;

	ReadClientInfo(Client);

	clsBankClient::enSaveStatus enStatus = Client.Save();

	switch (enStatus) {

	case clsBankClient::Success:
		cout << "Client updated successfully!" << endl; break;
	case clsBankClient::FailedEmptyObject:
		cout << "Saving client failed due to empty object" << endl; break;
	}


}

void AddNewClient() {

	string AccountNumber = "";

	AccountNumber = clsInputValidate::ReadString("Please enter the new account number:");
	while (clsBankClient::isClientExist(AccountNumber)) {
		cout << "Account number is already in use!\n";
		AccountNumber = clsInputValidate::ReadString("Please enter the new account number:");
	}

	clsBankClient NewClient = clsBankClient::getAddNewClientObject(AccountNumber);
	ReadClientInfo(NewClient);

	clsBankClient::enSaveStatus enStatus = NewClient.Save();

	switch (enStatus) {

	case clsBankClient::Success:
		cout << "Client Added successfully!" << endl; break;
	case clsBankClient::AccountAlreadyExist:
		cout << "Client with this id already in use" << endl; break;
	}


}

void DeleteClient() {

	string AccountNumber = "";

	AccountNumber = clsInputValidate::ReadString("Please enter the account number to delete:");
	while (!clsBankClient::isClientExist(AccountNumber)) {
		cout << "Client not found!!\n";
		AccountNumber = clsInputValidate::ReadString("Please enter the account number to delete:");
	}

	clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);

	DeleteClient.Print();

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

void PrintClientRecordLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.getAccountNumber();
	cout << "| " << setw(20) << left << Client.getFullName();
	cout << "| " << setw(12) << left << Client.getPhone();
	cout << "| " << setw(20) << left << Client.getEmail();
	cout << "| " << setw(10) << left << Client.getPINCode();
	cout << "| " << setw(12) << left << Client.getBalance();

}

void ShowClientsList()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
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

		for (const clsBankClient &Client : vClients)
		{

			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}
void PrintClientRecordBalanceLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.getAccountNumber();
	cout << "| " << setw(40) << left << Client.getFullName();
	cout << "| " << setw(12) << left << Client.getBalance();

}


void ShowTotalBalances()
{

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

		for (clsBankClient Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	
}

int main() {

	ShowTotalBalances();
	return 0;
}
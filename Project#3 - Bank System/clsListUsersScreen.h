#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include <vector>
#include <string>

class clsListUsersScreen : protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User)
	{

		cout << "| " << setw(15) << left << User.getUserName();
		cout << "| " << setw(20) << left << User.getFullName();
		cout << "| " << setw(12) << left << User.getPhone();
		cout << "| " << setw(20) << left << User.getEmail();
		cout << "| " << setw(10) << left << User.getPassword();
		cout << "| " << setw(12) << left << User.getPermissions();

	}

public:

	static void ShowListUsersScreen()
	{

		vector <clsUser> vUsers = clsUser::GetUsersList();

		const string Title = "\t  List Users";
		const string SubTitle = "\t  (" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (const clsUser& User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};
#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{
private:

	static short _ReadPrivileges()
	{
		short privileges = 0;
		int choice;

		cout << "\n=====================================================" << endl;
		cout << "                Select Permissions                   " << endl;
		cout << "=====================================================" << endl;
		cout << "[1] Show Client List\n";
		cout << "[2] Add New Client\n";
		cout << "[3] Delete Client\n";
		cout << "[4] Update Client Info\n";
		cout << "[5] Find Client\n";
		cout << "[6] Transactions\n";
		cout << "[7] Manage Users\n";
		cout << "[8] All Permissions\n";
		cout << "[0] Finish\n";
		cout << "=====================================================" << endl;

		do
		{
			choice = clsInputValidate::ReadIntNumber("Enter permission number (0 to finish): ");

			short permission = 0;

			switch (choice)
			{
			case 1: permission = clsUser::pShowClientList; break;
			case 2: permission = clsUser::pAddNewClient; break;
			case 3: permission = clsUser::pDeleteClient; break;
			case 4: permission = clsUser::pUpdateClient; break;
			case 5: permission = clsUser::pFindClient; break;
			case 6: permission = clsUser::pTransactions; break;
			case 7: permission = clsUser::pManageUsers; break;

			case 8:
				privileges =
					clsUser::pShowClientList |
					clsUser::pAddNewClient |
					clsUser::pDeleteClient |
					clsUser::pUpdateClient |
					clsUser::pFindClient |
					clsUser::pTransactions |
					clsUser::pManageUsers;

				cout << "All permissions granted!\n";
				return privileges;

			case 0:
				break;

			default:
				cout << "Invalid choice!\n";
				continue;
			}

			if (choice != 0 && choice != 8)
			{
				if (privileges & permission)
					cout << "Privilege already added!\n";
				else
				{
					privileges |= permission;
					cout << "Privilege added successfully.\n";
				}
			}

		} while (choice != 0);

		return privileges;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		User.setFirstName(clsInputValidate::ReadString("Please enter first name:"));
		User.setLastName(clsInputValidate::ReadString("Please enter last name:"));
		User.setEmail(clsInputValidate::ReadString("Please enter email:"));
		User.setPhone(clsInputValidate::ReadString("Please enter phone:"));
		User.setPassword(clsInputValidate::ReadString("Please enter password:"));

		User.setPermissions(_ReadPrivileges());
	}

	static void _PrintUser(clsUser& User)
	{
		cout << "\n\nUser Information:";
		cout << "\nFirst name:   " << User.getFirstName();
		cout << "\nLast name:    " << User.getLastName();
		cout << "\nEmail:        " << User.getEmail();
		cout << "\nPhone:        " << User.getPhone();
		cout << "\nUser Name:    " << User.getUserName();
		cout << "\nPassword:     " << User.getPassword();
		cout << "\nPermissions:  " << User.getPermissions();
		cout << endl;
	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User");

		string Username = clsInputValidate::ReadString("Please enter username:");

		while (!clsUser::isUserExist(Username))
		{
			cout << "User not found!\n";
			Username = clsInputValidate::ReadString("Please enter username:");
		}

		clsUser User = clsUser::Find(Username);

		cout << "\nCurrent User Info:\n";
		_PrintUser(User);

		cout << "\n\nEnter new information:\n";
		_ReadUserInfo(User);

		clsUser::enSaveResult SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::Success:
			cout << "\nUser Updated Successfully!\n";
			_PrintUser(User);
			break;

		case clsUser::FailedEmptyObject:
			cout << "\nError: Update failed.\n";
			break;
		}
	}
};
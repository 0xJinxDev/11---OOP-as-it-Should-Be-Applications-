#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include <iomanip>

class clsManageUsers : protected clsScreen
{

private:
  enum enManageUsersMenuOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static short _ReadManageUsersMenuOption() {
        cout << left << setw(37) << "Please choose what do you want to do ? 1 to 6\n";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 6, "Please enter number between 1 and 6:\n");
        return Choice;
    }
    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowListUsersScreen();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        system("pause>0");
        ShowManageUsersMenu();
    }
    static void _PerformManageUsersOption(enManageUsersMenuOptions Option) {

        switch (Option) {

        case eListUsers: system("cls"); _ShowListUsersScreen(); _GoBackToManageUsersMenu(); break;
        case eAddNewUser: system("cls"); _ShowAddNewUserScreen(); _GoBackToManageUsersMenu(); break;
        case eDeleteUser: system("cls"); _ShowDeleteUserScreen(); _GoBackToManageUsersMenu(); break;
        case eUpdateUser: system("cls"); _ShowUpdateUserScreen(); _GoBackToManageUsersMenu(); break;
        case eFindUser:system("cls"); _ShowFindUserScreen(); _GoBackToManageUsersMenu(); break;
        }

    }
public:

	static void ShowManageUsersMenu() {
		system("cls");
		_DrawScreenHeader("Manage Users");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}
};


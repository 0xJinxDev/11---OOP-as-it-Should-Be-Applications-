#pragma once
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsers.h"
#include "Global.h"
using namespace std;
class clsMainScreen  : protected clsScreen
{
private:

    enum enMainMenuOption {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
        eManageUsers = 7, eExit = 8
    };


    static short _ReadMainMenuOptions() {
        cout << left << setw(37) << "Please choose what do you want to do ? 1 to 8\n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Please enter number between 1 and 8:\n");
            return Choice;
    }
    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenu();
    }
    static void _ShowAllClientsScreen()
    {
        clsClientsListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionScreen::ShowTransactionsMenu();

    }

    static void _ShowManageUsersMenu()
    {
        clsManageUsers::ShowManageUsersMenu();

    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");

    }

    static void _PerformMainMenuOption(enMainMenuOption MainMenuOption) {

        switch (MainMenuOption) {

        case eListClients: system("cls"); _ShowAllClientsScreen(); _GoBackToMainMenu(); break;
        case eAddNewClient: system("cls"); _ShowAddNewClientsScreen(); _GoBackToMainMenu(); break;
        case eDeleteClient: system("cls"); _ShowDeleteClientScreen(); _GoBackToMainMenu(); break;
        case eUpdateClient: system("cls"); _ShowUpdateClientScreen(); _GoBackToMainMenu(); break;
        case eFindClient: system("cls"); _ShowFindClientScreen(); _GoBackToMainMenu(); break;
        case eShowTransactionsMenu: system("cls"); _ShowTransactionsMenu(); _GoBackToMainMenu(); break;
        case eManageUsers: system("cls"); _ShowManageUsersMenu(); _GoBackToMainMenu(); break;
        case eExit: system("cls"); _Logout(); break;
        }
    }

public:

	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOption)_ReadMainMenuOptions());

	}
};


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

    static void _PerformMainMenuOption(enMainMenuOption MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case eListClients:
            if (!CheckAccessRights(clsUser::pShowClientList)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowAllClientsScreen(); _GoBackToMainMenu(); break;

        case eAddNewClient:
            if (!CheckAccessRights(clsUser::pAddNewClient)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowAddNewClientsScreen(); _GoBackToMainMenu(); break;

        case eDeleteClient:
            if (!CheckAccessRights(clsUser::pDeleteClient)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowDeleteClientScreen(); _GoBackToMainMenu(); break;

        case eUpdateClient:
            if (!CheckAccessRights(clsUser::pUpdateClient)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowUpdateClientScreen(); _GoBackToMainMenu(); break;

        case eFindClient:
            if (!CheckAccessRights(clsUser::pFindClient)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowFindClientScreen(); _GoBackToMainMenu(); break;

        case eShowTransactionsMenu:
            if (!CheckAccessRights(clsUser::pTransactions)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowTransactionsMenu(); _GoBackToMainMenu(); break;

        case eManageUsers:
            if (!CheckAccessRights(clsUser::pManageUsers)) { _GoBackToMainMenu(); return; }
            system("cls"); _ShowManageUsersMenu(); _GoBackToMainMenu(); break;

        case eExit:
            system("cls"); _Logout(); break;
        }
    }

public:

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";

        if (CurrentUser.CheckAccessPermission(clsUser::pShowClientList))
        {
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        }
        if (CurrentUser.CheckAccessPermission(clsUser::pAddNewClient))
        {
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        }
        if (CurrentUser.CheckAccessPermission(clsUser::pDeleteClient))
        {
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        }
        if (CurrentUser.CheckAccessPermission(clsUser::pUpdateClient))
        {
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        }
        if (CurrentUser.CheckAccessPermission(clsUser::pFindClient))
        {
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        }
        if (CurrentUser.CheckAccessPermission(clsUser::pTransactions))
        {
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        }
        if (CurrentUser.CheckAccessPermission(clsUser::pManageUsers))
        {
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        }

        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOption)_ReadMainMenuOptions());

    }
};


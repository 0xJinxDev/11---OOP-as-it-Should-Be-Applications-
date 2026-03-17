#pragma once
#include <string>
#include <iostream>
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsScreen
{
protected:
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            system("cls");
            cout << "\n\n\t\t\t\t   =================================";
            cout << "\n\n\t\t\t\t\tAccess Denied! \n";
            cout << "\n\t\t\t\tYou dont have permission to do this, \n";
            cout << "\n\n\t\t\t\t   =================================\n";
            return false;
        }
        return true;
    }

	static void _DrawScreenHeader(const string& Title, const string& SubTitle = "") {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";


	}
};


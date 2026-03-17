#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser& User) {

        cout << "\n\nUser Information:";
        cout << "\nFirst name:   " << User.getFirstName();
        cout << "\nLast name:    " << User.getLastName();
        cout << "\nEmail:        " << User.getEmail();
        cout << "\nPhone:        " << User.getPhone();
        cout << "\nUsername:     " << User.getUserName();
        cout << "\nPassword:     " << User.getPassword();
        cout << "\nPermissions:  " << User.getPermissions();
        cout << endl;
    }

public:

    static void ShowFindUserScreen() {

        _DrawScreenHeader("Find User");

        string Username;
        char Flag = 'Y';

        while (Flag == 'Y' || Flag == 'y') {

            Username = clsInputValidate::ReadString("Please enter the username:");

            if (clsUser::isUserExist(Username)) {

                clsUser User = clsUser::Find(Username);
                _PrintUser(User);
                return;
            }

            cout << "User not found!\n";
            Flag = clsInputValidate::ReadChar("Do you want to try again? (Y/N)");
        }
    }
};
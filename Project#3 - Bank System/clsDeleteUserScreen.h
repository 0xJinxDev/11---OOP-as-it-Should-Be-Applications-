#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser& User) {

        cout << "\n\nUser Information:";
        cout << "\nFirst name:   " << User.getFirstName();
        cout << "\nLast name:    " << User.getLastName();
        cout << "\nEmail:        " << User.getEmail();
        cout << "\nPhone:        " << User.getPhone();
        cout << "\nUsername:     " << User.getUserName();
        cout << "\nPermissions:  " << User.getPermissions();
        cout << endl;
    }

public:

    static void ShowDeleteUserScreen() {

        _DrawScreenHeader("Delete User");

        string Username = clsInputValidate::ReadString("Please enter Username: ");

        while (!clsUser::isUserExist(Username)) {
            cout << "\nUser not found, try again.\n";
            Username = clsInputValidate::ReadString("Please enter Username: ");
        }

        clsUser User = clsUser::Find(Username);
        _PrintUser(User);

        char Answer = clsInputValidate::ReadChar("\nAre you sure you want to delete this user? (Y/N): ");

        if (Answer == 'Y' || Answer == 'y') {

            User.Delete();
            cout << "\nUser deleted successfully.\n";
        }
        else {
            cout << "\nOperation cancelled.\n";
        }
    }
};
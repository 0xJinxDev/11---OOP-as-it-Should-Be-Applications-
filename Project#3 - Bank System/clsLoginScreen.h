#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"
class clsLoginScreen : protected clsScreen
{
private:

	static bool _LoginScreen() {

		bool LoginFailed = false;
		short FailedLoginCount = 0;
		string Username, Password;

		do {

			if (LoginFailed) {
				FailedLoginCount++;
				cout << "\nInvalid Username/Password!\n\n";
				cout << ( (FailedLoginCount == 2) ? ("You have "+to_string(3 - FailedLoginCount) + " trial left\n")
					: ("You have "+to_string(3 - FailedLoginCount) + " trials left.\n"));
				
				if (FailedLoginCount == 3) {
					cout << "You are locked from using the system.\n";
					return false;
				}
					
			}
				

			Username = clsInputValidate::ReadString("Please enter the username:");
			Password = clsInputValidate::ReadString("Please enter the password:");
			
			CurrentUser = clsUser::Find(Username, Password);
			
			LoginFailed = CurrentUser.isEmpty();
		} while (LoginFailed);
		
		CurrentUser.LogLogin();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _LoginScreen();
		
	}
};


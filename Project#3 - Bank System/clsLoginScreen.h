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

	static void _LoginScreen() {

		bool LoginFailed = false;

		string Username, Password;

		do {

			if (LoginFailed)
				cout << "\nInvalid Username/Password!\n\n";

			Username = clsInputValidate::ReadString("Please enter the username:");
			Password = clsInputValidate::ReadString("Please enter the password:");
			
			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.isEmpty();
		} while (LoginFailed);
		

		clsMainScreen::ShowMainMenu();

	}

public:

	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("Login Screen");
		_LoginScreen();
		
	}
};


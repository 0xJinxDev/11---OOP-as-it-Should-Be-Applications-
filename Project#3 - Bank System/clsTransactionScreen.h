#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
class clsTransactionScreen : protected clsScreen
{

private:
	enum enTransactionsMenuOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eShowMainMenu = 4
	};

	static short _ReadTransactionMenuOption() {
		cout << left << setw(37) << "Please choose what do you want to do ? 1 to 4\n";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Please enter number between 1 and 4:\n");
		return Choice;
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}


	static void _PerformTransactionOption(enTransactionsMenuOptions TransactionOption) {

		switch (TransactionOption) {

		case eDeposit: system("cls"); _ShowDepositScreen(); _GoBackToTransactionsMenu();  break;
		case eWithdraw: system("cls"); _ShowWithdrawScreen(); _GoBackToTransactionsMenu();  break;
		case eShowTotalBalance: system("cls"); _ShowTotalBalanceScreen(); _GoBackToTransactionsMenu();  break;

		}
	}

	static void _GoBackToTransactionsMenu() {
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenu();
	}
public:
	static void ShowTransactionsMenu() {
		system("cls");
		_DrawScreenHeader("Transactions");


		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionOption((enTransactionsMenuOptions)_ReadTransactionMenuOption());


	}
};


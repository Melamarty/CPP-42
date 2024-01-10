#include "Account.hpp"


int main()
{
	Account account(0);
	account.makeDeposit(100);
	account.makeWithdrawal(50);
	account.makeDeposit(100);
	account.makeWithdrawal(50);

	Account::displayAccountsInfos();
	return 0;
}
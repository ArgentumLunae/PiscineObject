#include <iostream>
#include <vector>
#include <limits>

#define FEE_PERCENTAGE 5

#define ACC_NOTFOUND "Account not found in bank system."

struct Bank
{
	private:
		struct Account
		{		
			private:
				int id;
				int value;

			public:
				Account() :	id(-1), value(0) {}
				const int &getID() const { return id;}
				friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
				{
					p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
					return (p_os);
				}
				friend struct Bank;
		};

		int liquidity;
		std::vector<Account *> clientAccounts;

		int generateID()
		{
			int id = 0;
			while (true)
			{
				bool uniqueID = true;
				for (auto &clientAccount : clientAccounts)
				{
					if (id == clientAccount->id)
					{
						uniqueID = false;
						break;
					}
				}
				if (uniqueID)
					break;
			}
			if (id < 0)
			{
				std::cerr << "Account limit (" << __INT_MAX__ << ") reached." << std::endl << "Remove accounts before adding more." << std::endl;
				return -1;
			}
			return id;
		}

		Account * findAccount(int &id)
		{
			for (std::vector<Account *>::iterator iter = clientAccounts.begin(); iter != clientAccounts.end(); iter++)
			{
				if ((*iter)->id == id)
				{
					return *iter;
				}
			}
			return NULL;
		}

	public:
		Bank() :
			liquidity(0)
		{

		}

		~Bank()
		{
			for (auto clientAccount : clientAccounts)
				delete clientAccount;
		}

		const int&	createAccount()
		{
			Account	*newAccount = new Account();
			newAccount->id = generateID();
			newAccount->value = 0;
			clientAccounts.push_back(newAccount);
			return newAccount->id;
		}

		void	deleteAccount(int id)
		{
			for (std::vector<Account *>::iterator iter = clientAccounts.begin(); iter != clientAccounts.end(); iter++)
			{
				if ((*iter)->id == id)
				{
					clientAccounts.erase(iter);
					delete *iter;
					return ;
				}
			}
		}

		bool	depositToAccount(int id, int depositValue)
		{
			Account *depositAccount = findAccount(id);
			if (depositAccount)
			{
				int transferFee = depositValue * FEE_PERCENTAGE / 100;
				liquidity += transferFee;
				depositAccount->value += (depositValue - transferFee);
				return true;
			}
			std::cout << "Depostit failed: " << ACC_NOTFOUND << std::endl;
			return false;
		}

		bool	withdrawFromAccount(int id, int withdrawalValue)
		{
			Account *withdrawalAccount = findAccount(id);
			if (!withdrawalAccount)
			{
				std::cout << "Withdrawal failed: " << ACC_NOTFOUND << std::endl;
				return false;
			}
			if (withdrawalValue > withdrawalAccount->value)
			{
				std::cout << "Withdrawal failed: Not enough funds in account." << std::endl;
			}
			withdrawalAccount->value -= withdrawalValue;
			return true;
		}

		bool	loanToAccount(int id, int loanValue)
		{
			if (loanValue > liquidity)
			{
				std::cout << "Loan failed: not enough bank liquidity" << std::endl;
				return false;
			}
			Account *loanAccount = findAccount(id);
			if (loanAccount)
			{
				loanAccount->value += loanValue;
				liquidity -= loanValue;
				return true;
			}
			std::cout << "Loan failed: " << ACC_NOTFOUND << std::endl;
			return false;
		}

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.liquidity << std::endl;
			for (auto &clientAccount : p_bank.clientAccounts)
	        	p_os << *clientAccount << std::endl;
			return (p_os);
		}
};

int main()
{
	//Account accountA = Account();
	// accountA.id = 0;
	// accountA.value = 100;
	
	//Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;
	
	Bank bank = Bank();
	int accountA_ID = bank.createAccount();
	bank.depositToAccount(accountA_ID, 100);
	bank.loanToAccount(accountA_ID, 5);
	bank.withdrawFromAccount(accountA_ID, 100);
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);

	// bank.liquidity -= 200;
	// accountA.value += 400;

	//Account& accountC = bank.createAccount();
	//std::cout << &accountC << std::endl;

	std::cout << "Account : " << std::endl;
	// std::cout << accountA << std::endl;
	// std::cout << accountB << std::endl;
	// std::cout << accountC << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	bank.deleteAccount(accountA_ID);

	return (0);
}

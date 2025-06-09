#include <iostream>
#include <vector>
#include <limits>

#define FEE_PERCENTAGE 5

struct Account
{
	private:
		int id;
		int value;

		public:
		Account() :
		id(-1),
		value(0)
		{
			
		}
		
		const int &getID() const
		{
			return id;
		}
		
		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
		{
			p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
			return (p_os);
		}

		friend struct Bank;
};

struct Bank
{
	private:
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
				std::cerr << "Account limit (" << INTMAX_MAX << ") reached." << std::endl << "Remove accounts before adding more." << std::endl;
				return -1;
			}
			return id;
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

		Account	&createAccount()
		{
			Account	*newAccount = new Account();
			newAccount->id = generateID();
			newAccount->value = 0;
			clientAccounts.push_back(newAccount);
			return *newAccount;
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

		void	deleteAccount(Account &rmAccount)
		{
			for (std::vector<Account *>::iterator iter = clientAccounts.begin(); iter != clientAccounts.end(); iter++)
			{
				std::cout << *iter << "\t" << &rmAccount << std::endl;
				if (*iter == &rmAccount)
				{
					clientAccounts.erase(iter);
					delete &rmAccount;
					return ;
				}
			}
		}

		void	depositToAccount(Account &depositAccount, int depositValue)
		{
			int transferFee = depositValue * FEE_PERCENTAGE / 100;
			liquidity += transferFee;
			depositAccount.value += (depositValue - transferFee);
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
	Account accountA = Account();
	// accountA.id = 0;
	// accountA.value = 100;
	
	Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;
	
	Bank bank = Bank();
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);

	// bank.liquidity -= 200;
	// accountA.value += 400;

	Account& accountC = bank.createAccount();
	std::cout << &accountC << std::endl;
	bank.depositToAccount(accountC, 500);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;
	std::cout << accountC << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	bank.deleteAccount(accountC);

	return (0);
}

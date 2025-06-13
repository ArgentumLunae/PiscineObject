#include <iostream>
#include <map>
#include <limits>

#define FEE_PERCENTAGE 5
#define MAX_ACCOUNTS   999999999

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
				const int	&getID() const { return id; }
				const int	&getValue() const { return value; }
				void		setID(const int &newID) { id = newID; }
				void		setValue(const int &newValue) { value = newValue; }

				friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
				{
					p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
					return (p_os);
				}
		};

		int liquidity;
		std::map<int, Account *> clientAccounts;

		int generateID()
		{
			int id = 0;
			while (true)
			{
				if (!findAccount(id))
					break;
				if (id > MAX_ACCOUNTS || id < 0)
				{
					std::cerr << "Account limit (" << MAX_ACCOUNTS << ") reached." << std::endl << "Remove accounts before adding more." << std::endl;
					return -1;
				}
				id++;
			}
			return id;
		}

		Account *findAccount(const int &id)
		{
			std::map<int, Account*>::iterator iter = findAccountIter(id);
			if (iter != clientAccounts.end())
				return (*iter).second;
			return NULL;
		}

		std::map<int, Account*>::iterator findAccountIter(const int &id)
		{
			return clientAccounts.find(id);
		}

	public:
		Bank() :
			liquidity(0)
		{

		}

		~Bank()
		{
			for (auto clientAccount : clientAccounts)
				delete clientAccount.second;
		}

		const int&	createAccount()
		{
			static int badReturn = -1;
			Account	*newAccount = new Account();
			int newID = generateID();
			if (newID < 0)
				return badReturn;
			newAccount->setID(newID);
			clientAccounts.insert({newID, newAccount});
			return newAccount->getID();
		}

		void	deleteAccount(int id)
		{
			std::map<int, Account*>::iterator iter = findAccountIter(id);
			if (iter != clientAccounts.end())
			{
				clientAccounts.erase(iter);
				delete (*iter).second;
				return ;
			}
		}

		bool	depositToAccount(int id, int depositValue)
		{
			Account *depositAccount = findAccount(id);
			if (depositAccount)
			{
				int transferFee = depositValue * FEE_PERCENTAGE / 100;
				liquidity += transferFee;
				depositAccount->setValue(depositAccount->getValue() + (depositValue - transferFee));
				return true;
			}
			std::cout << "Depostit failed: " << ACC_NOTFOUND <<  " (ID:" << id << ')'  << std::endl;
			return false;
		}

		bool	withdrawFromAccount(int id, int withdrawalValue)
		{
			Account *withdrawalAccount = findAccount(id);
			if (!withdrawalAccount)
			{
				std::cout << "Withdrawal failed: " << ACC_NOTFOUND <<  " (ID:" << id << ')' <<  std::endl;
				return false;
			}
			if (withdrawalValue > withdrawalAccount->getValue())
			{
				std::cout << "Withdrawal failed: Not enough funds in account." << std::endl;
				return false;
			}
			withdrawalAccount->setValue(withdrawalAccount->getValue() - withdrawalValue);
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
				loanAccount->setValue(loanAccount->getValue() + loanValue);
				liquidity -= loanValue;
				return true;
			}
			std::cout << "Loan failed: " << ACC_NOTFOUND << std::endl;
			return false;
		}

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "\tLiquidity : " << p_bank.liquidity << std::endl;
			p_os << "\tAccounts:" << std::endl;
			for (auto &clientAccount : p_bank.clientAccounts)
	        	p_os << "\t\t" << *clientAccount.second << std::endl;
			return (p_os);
		}
};

int main()
{
	// ACCOUNTS CAN NO LONGER BE INSTANCED OUTSIDE OF BANK
	// UNCOMMENT BELOW TO SHOW
	// Account accountA = Account();
	
	Bank bank = Bank();
	const int accountA_ID = bank.createAccount();
	bank.depositToAccount(accountA_ID, 100);
	std::cout << bank << std::endl;
	
	
	bank.loanToAccount(accountA_ID, 10);	// not enough liquidity
	bank.loanToAccount(accountA_ID, 5);
	bank.withdrawFromAccount(accountA_ID, 100);
	
	const int accountB_ID = bank.createAccount();
	bank.depositToAccount(accountB_ID, 250);
	
	int accountC_ID = bank.createAccount();
	bank.depositToAccount(accountC_ID, 254486200);

	std::cout << bank << std::endl;
	
	bank.deleteAccount(accountB_ID);
	accountC_ID = 5;		//careful not to lose your account ID
	bank.withdrawFromAccount(accountC_ID, 5000);
	bank.depositToAccount(accountA_ID, 5000);
	bank.withdrawFromAccount(accountA_ID, 6);

	bank.depositToAccount(accountB_ID, 12);

	std::cout << bank << std::endl;


	return (0);
}

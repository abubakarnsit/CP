#include<bits/stdc++.h>
using namespace std;
 
class Bank1
{
public:
	virtual string withdraw(void) = 0;
	virtual ~Bank1(){}
};
 
class ActualBank : Bank1
{
public:
	string withdraw(void)
	{
		return "collect ur amount.\n\n";
	}
};
 
class Bank : public Bank1
{
	ActualBank* _bank;
	string _password;
public:
	Bank() :_bank(NULL), _password("12345"){}
 
	string withdraw(void)
	{
		if (_bank == NULL)
			return "\nAre you authenticated?\n";
		return _bank->withdraw();
	}
 
	void Authenticate(string passwd)
	{
		if (_password == passwd)
		{
			cout << "\nYou have been authenticated.Welcome to the bank\n\n";
			_bank = new ActualBank();
			cout<<_bank->withdraw();
		}
		else
		{
			cout << "\nSorry, wrong password Entered.\n";
		}
	}
 
	~Bank()
	{
		delete _bank;
	}
};
 
int main()
{
	Bank*bank = new Bank();
	cout << bank->withdraw();
	string str;
	cout<<"Enter Ur password "<<endl;
	cin>>str;
	bank->Authenticate(str);
 
	return 1;
}
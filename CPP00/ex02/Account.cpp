#include "Account.hpp"
#include "iostream"
using namespace std;

int setNbAccount(int value)
{
	static int send;
	if (value >= 0)
		send = value;
	return (send);
}
int setTotalAmount(int value)
{
	static int send;
	send += value;
	return (send);
}
int setNbDeposits(int value)
{
	static int send;
	if (value >= 0)
		send = value;
	return (send);
}
int setNbWithdrawals(int value)
{
	static int send;
	if (value >= 0)
		send = value;
	return (send);
}
int Account::getNbAccounts(void){
	return (setNbAccount(-1));
}

int Account::getTotalAmount(void){
	return (setTotalAmount(0));
}

int Account::getNbDeposits(void){
	return (setNbDeposits(-1));
}

int Account::getNbWithdrawals(void){
	return (setNbWithdrawals(-1));
}

void Account::_displayTimestamp(void){
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "["<<
		 now->tm_year + 1900<<
		 now->tm_mon + 1<<
		 now->tm_mday<<
		 "_"<<
		 now->tm_hour<<
		 now->tm_min<<
		 now->tm_sec<<"] ";
}
void Account::makeDeposit(int deposit){
	this->_amount += deposit;
	this->_nbDeposits++;
	setTotalAmount(deposit);
	setNbDeposits(getNbDeposits() + 1);
}

bool Account::makeWithdrawal(int withdrawal){
	if (withdrawal <= this->_amount) {
		this->_amount -= withdrawal;
		setTotalAmount(-withdrawal);
		setNbWithdrawals(getNbWithdrawals() + 1);
		this->_nbWithdrawals++;
		return (true);
	}
	_displayTimestamp();
	cout <<"index:"<<this->_accountIndex<<";p_amount"<<withdrawal<<";refused\n";
	return (false);
}

int Account::checkAmount(void) const{
	return (this->_amount);
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	cout <<"index:"<< this->_accountIndex << ";"
			<<"amount:"<< this->_amount << ";"
			<<"deposits:"<< this->_nbDeposits << ";"
			<<"withdrawals:"<< this->_nbWithdrawals << ";\n";
}

static int amount()
{
	static int n;

	return (n++);
}

Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_accountIndex = amount();
	setNbAccount(getNbAccounts() + 1);
	setTotalAmount(initial_deposit);
	_displayTimestamp();
	cout << "index:"<<this->_accountIndex<<";"<<
			"amount:"<< this->_amount<<";created\n";
}

void Account::displayAccountsInfos(void) {
	static int once;
	if (!once++)
		_displayTimestamp();
	cout <<"accounts:"<<getNbAccounts()<<";total:"<<getTotalAmount()<<";deposits:"<< getNbDeposits() << ";withdrawals:"<<getNbWithdrawals()<<endl;
	once = 0;
}
Account::~Account(){
	_displayTimestamp();
	setNbAccount(getNbAccounts() - 1);
	cout << "index:"<<this->_accountIndex<<";"<<
		 "amount:"<< this->_amount<<";closed\n";
}

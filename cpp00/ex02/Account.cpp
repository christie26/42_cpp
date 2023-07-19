
#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	Account account;

	return (account._nbDeposits);

}

int	Account::getNbWithdrawals( void ) {
	Account account;

	return (account._nbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "displayAccountsInfos" << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account() : _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << " amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp() {
	std::cout << "[time stamp] ";
}

void	Account::makeDeposit( int deposit ) {

}

bool	Account::makeWithdrawal( int withdrawal ) {
	return (withdrawal < _amount);

}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << " amount:" << _amount << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

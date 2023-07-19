
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

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
	_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
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
    std::time_t	now = std::time(nullptr);
    std::tm*	localTime = std::localtime(&now);

    std::cout << std::setfill('0')
		<< '['
        << std::setw(4) << localTime->tm_year + 1900
        << std::setw(2) << (localTime->tm_mon + 1)
        << std::setw(2) << localTime->tm_mday
        << "_"
        << std::setw(2) << localTime->tm_hour
        << std::setw(2) << localTime->tm_min
        << std::setw(2) << localTime->tm_sec
		<< "] ";
}

void	Account::makeDeposit( int deposit ) {
	_nbDeposits += 1;
    _totalNbDeposits++;
    _totalAmount += deposit;
    int p_amount = _amount;
    _amount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
            << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
            << ";withdrawal:";
    if (checkAmount() > withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << _amount 
            << ";nb_withdrawals:" << _nbWithdrawals
            << std::endl;
    }
    else
        std::cout << "refused" << std::endl;
	return (withdrawal < _amount);

}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
    std::cout   << "index:" << _accountIndex << " amount:" << _amount 
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}

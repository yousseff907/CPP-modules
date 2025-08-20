/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:36:02 by yitani            #+#    #+#             */
/*   Updated: 2025/08/20 18:14:05 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*timeinfo;

	now = std::time(0);
	timeinfo = std::localtime(&now);
	std::cout << "[" << (timeinfo->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_min
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			  << "] ";
}

void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = this->_amount;

	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

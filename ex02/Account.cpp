/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:16:53 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/10/24 10:53:16 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	Account::_nbAccounts += 1;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts -= 1;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;
	tm		*ltm;

	now = time(NULL);
	ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year<< 1 + ltm->tm_mon << ltm->tm_mday;
	std::cout << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
	// std::cout << "[19920104_091532] ";
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	this->_nbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:";
	std::cout << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:";
	std::cout << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
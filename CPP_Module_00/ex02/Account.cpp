/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:18:47 by aoussama          #+#    #+#             */
/*   Updated: 2025/11/17 02:29:39 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t  now = std::time(NULL);
    std::tm *ptm = std::localtime(&now);

    std::cout << '['
              << (ptm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << ptm->tm_mon + 1
              << std::setw(2) << ptm->tm_mday << '_'
              << std::setw(2) << ptm->tm_hour
              << std::setw(2) << ptm->tm_min
              << std::setw(2) << ptm->tm_sec
              << "] ";
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int previous = _amount;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previous
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused"
                  << std::endl;
        return false;
    }

    int previous = _amount;

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previous
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;

    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

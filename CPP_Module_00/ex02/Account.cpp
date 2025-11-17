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

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

void Account::displayAccountsInfos( void )
{
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals;
}

void Account::displayStatus( void) const
{
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
} 

void Account::makeDeposit( int deposit )
{
    _amount += deposit;
    _nbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_aount:" << _amount - deposit << "deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits;
}
bool Account::makeWithdrawal( int withdrawal )
{
    if(withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused";
        return false;
    }
    std::cout << "index:" << _accountIndex << ";p_aount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals;
    _amount -= withdrawal;
    return true;
}
int Account::checkAmount( void ) const
{
    
}
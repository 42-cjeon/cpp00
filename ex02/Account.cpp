/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:57:06 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/11 21:40:00 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
  return _nbAccounts;
}

int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << " accounts:"    << _nbAccounts;
  std::cout << ";total:"       << _totalAmount;
  std::cout << ";deposits:"    << _totalNbDeposits;
  std::cout << ";withdrawals:" << _totalNbWithdrawals;
  std::cout << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit) {
  _displayTimestamp();
  std::cout << " index:"  << _accountIndex;
  std::cout << ";amount:" << initial_deposit;
  std::cout << ";created" << std::endl;
  ++_nbAccounts;
  _totalAmount += initial_deposit;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << " index:"  << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";closed"  << std::endl;
  --_nbAccounts;
  _totalAmount -= _amount;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << " index:"     << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  std::cout << ";deposit:"  << deposit;
  _amount += deposit;
  _totalAmount += deposit;
  ++_totalNbDeposits;
  ++_nbDeposits;
  std::cout << ";amount:"      << _amount;
  std::cout << ";nb_deposits:" << _nbDeposits;
  std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << " index:"       << _accountIndex;
  std::cout << ";p_amount:"    << _amount;
  std::cout << ";withdrawal:";
  if (_amount < withdrawal) {
    std::cout << "refused" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= _amount;
  ++_totalNbWithdrawals;
  ++_nbWithdrawals;
  std::cout << withdrawal;
  std::cout << ";amount:"         << _amount;
  std::cout << ";nb_withdrawals:" << _nbWithdrawals;
  std::cout << std::endl;
  return true;
}

int Account::checkAmount(void) const {
  return _amount;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:"       << _accountIndex;
  std::cout << ";amount:"      << _amount;
  std::cout << ";deposits:"    << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals;
  std::cout << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t timestamp = std::time(NULL);
  std::tm *now = std::localtime(&timestamp);
  char prev_fill = std::cout.fill('0');

  std::cout << '[';
  std::cout << std::setw(4) << now->tm_year + 1900;
  std::cout << std::setw(2) << now->tm_mon + 1;
  std::cout << std::setw(2) << now->tm_mday;
  std::cout << '_';
  std::cout << std::setw(2) << now->tm_hour;
  std::cout << std::setw(2) << now->tm_min;
  std::cout << std::setw(2) << now->tm_sec;
  std::cout << ']';
  std::cout.fill(prev_fill);
}
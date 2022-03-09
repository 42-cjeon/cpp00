/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:50 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/09 20:21:48 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : cursor_(0), space_left_(max_contacts_) { }

bool PhoneBook::add(void)
{
  Contact &contact = contacts_[cursor_];
  std::string line;

  std::cout << "input firstname: ";
  std::getline(std::cin, line);
  if (!contact.set_firstname(line))
    return false;
  std::cout << "input lastname: ";
  std::getline(std::cin, line);
  if (!contact.set_lastname(line))
    return false;
  std::cout << "input nickname: ";
  std::getline(std::cin, line);
  if (!contact.set_nickname(line))
    return false;
  std::cout << "input phone number: ";
  std::getline(std::cin, line);
  if (!contact.set_phone_number(line))
    return false;
  std::cout << "input darkest secret: ";
  std::getline(std::cin, line);
  if (!contact.set_darkest_secret(line))
    return false;
  if (++cursor_ == max_contacts_)
    cursor_ = 0;
  if (space_left_)
    --space_left_;
  std::cout << "add success" << std::endl;
  return true;
}

void PhoneBook::search(void) {
  int end = space_left_ ? cursor_ : max_contacts_;

  for (int i = 0; i < end; ++i) {
    std::cout << std::setw(10) << i << '|';
    std::cout << contacts_[i] << std::endl;
  }
}
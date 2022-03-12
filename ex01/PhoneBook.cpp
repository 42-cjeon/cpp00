/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:50 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/12 14:40:05 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void) : cursor_(0), space_left_(max_contacts_) {}

bool PhoneBook::add(void) {
  Contact &contact = contacts_[cursor_];
  std::string line;

  lead::getline_prompt(std::cin, line, " - Enter firstname: ");
  if (!contact.set_firstname(line)) {
    return false;
  } 
  lead::getline_prompt(std::cin, line, " - Enter lastname: ");
  if (!contact.set_lastname(line)) {
    return false;
  }
  lead::getline_prompt(std::cin, line, " - Enter nickname: ");
  if (!contact.set_nickname(line)) {
    return false;
  }
  lead::getline_prompt(std::cin, line, " - Enter phone number: ");
  if (!contact.set_phone_number(line)) {
    return false;
  }
  lead::getline_prompt(std::cin, line, " - Enter darkest secret: ");
  if (!contact.set_darkest_secret(line)) {
    return false;
  }
  cursor_ = (cursor_ == max_contacts_ - 1) ? 0 : cursor_ + 1;
  space_left_ = space_left_ ? space_left_ - 1 : 0;
  return true;
}

void PhoneBook::search(void) {
  if (space_left_ == max_contacts_) {
    std::cout << " [!] empty contacts" << std::endl;
    return;
  }
  print_contacts();
  int index;
  lead::getline_prompt(std::cin, index, "- Enter index: ");
  if (std::cin.fail() || index < 0 || max_contacts_ - space_left_ <= index) {
    std::cout << " [!] invalid index" << std::cout;
    std::cin.clear();
    return;
  }
  
}

void PhoneBook::print_contacts(void) {
  size_t end = space_left_ ? cursor_ : max_contacts_;

  print_header();
  for (size_t i = 0; i < end; ++i)
    print_contact(i);
  print_hr();
}

void PhoneBook::print_contact(size_t index) {
  const Contact &contact = contacts_[index];

  std::cout << '|';
  std::cout << std::setw(10) << index;
  std::cout << '|';
  lead::print_with_width(contact.firstname(), 10);
  std::cout << '|';
  lead::print_with_width(contact.lastname(), 10);
  std::cout << '|';
  lead::print_with_width(contact.nickname(), 10);
  std::cout << '|' << std::endl;
}

void PhoneBook::print_header(void) {
  print_hr();
  std::cout << '|';
  lead::print_with_width("index", 10);
  std::cout << '|';
  lead::print_with_width("firstname", 10);
  std::cout << '|';
  lead::print_with_width("lastname", 10);
  std::cout << '|';
  lead::print_with_width("nickname", 10);
  std::cout << '|' << std::endl;
  print_hr();
}

void PhoneBook::print_hr(void) {
  char fill_char = std::cout.fill();
  std::cout << '|' << std::setfill('-') << std::setw(44) << '|' << std::endl;
  std::cout.fill(fill_char);
}
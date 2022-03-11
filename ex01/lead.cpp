/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lead.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:49 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/11 12:37:56 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "utils.hpp"
#include "PhoneBook.hpp"

int main(void) {
  std::string line;
  PhoneBook phonebook;

  lead::show_banner();
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, line);
    if (std::cin.eof()) {
      break;
    } else if (line == "EXIT") {
      break;
    } else if (line == "ADD") {
      if (phonebook.add()) {
        std::cout << " [-] successfully added" << std::endl;
      } else {
        std::cout << " [!] failed to update contact" << std::endl;
      }
    } else if (line == "SEARCH") {
      phonebook.search();
    }
  }
  return 0;
}
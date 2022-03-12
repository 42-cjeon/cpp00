/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lead.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:49 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/12 17:21:05 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"
#include "utils.hpp"

int main(void) {
  std::string line;
  PhoneBook phonebook;

  lead::show_banner();
  while (true) {
    lead::getline_prompt(std::cin, line, "> ");
    if (std::cin.eof() || line == "EXIT") {
      break;
    } else if (line == "ADD") {
      if (phonebook.add()) {
        std::cout << " [-] successfully added" << std::endl;
      } else if (std::cin.good()) {
        std::cout << " [!] failed to update contact" << std::endl;
      }
    } else if (line == "SEARCH") {
      phonebook.search();
    }
  }
  return 0;
}
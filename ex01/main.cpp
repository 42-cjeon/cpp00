/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:49 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/09 19:27:41 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
  std::string line;
  PhoneBook phonebook;

  while (true) {
    std::getline(std::cin, line);
    if (line == "EXIT") {
      break ;
    } else if (line == "ADD") {
      phonebook.add();
    } else if (line == "SEARCH") {
      phonebook.search();
    }
  }
  return 0;
}
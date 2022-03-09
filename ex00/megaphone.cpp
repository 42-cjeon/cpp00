/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:55 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/08 15:24:28 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string &str_toupper(std::string &str) {
  for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    *it = toupper(*it);
  return str;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (int i = 1; i < argc; ++i) {
      std::string str(argv[i]);
      std::cout << str_toupper(str);
    }
    std::cout << std::endl;
  }
  return 0;
}
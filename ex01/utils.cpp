/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:17 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/10 23:43:32 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "utils.hpp"

void lead::show_banner(void) { std::cout << lead::banner << std::endl; }

void lead::print_with_width(const std::string &str, size_t width) {
  if (width == 0) {
    return;
  } else if (str.length() > width) {
    std::cout << str.substr(0, width - 1) << '.';
  } else {
    std::cout << std::setw(width) << str;
  }
}

std::istream &lead::getline_prompt(std::istream &stream, std::string &str, const std::string &prompt) {
  std::cout << prompt;
  return std::getline(stream, str);
}
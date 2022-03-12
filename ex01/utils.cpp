/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:17 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/12 19:11:54 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#include <iomanip>
#include <sstream>

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

std::istream &lead::getline_prompt(std::istream &stream, std::string &str,
                                   const std::string &prompt) {
  if (!stream.good()) return stream;
  std::cout << prompt;
  return std::getline(stream, str);
}

std::istream &lead::getline_prompt(std::istream &stream, int &k,
                                   const std::string &prompt) {
  if (!stream.good()) return stream;
  std::cout << prompt;
  std::string str;
  std::getline(stream, str);
  if (!stream.good()) {
    return stream;
  }
  std::istringstream int_stream(str);
  int_stream >> k;
  if (int_stream.fail()) {
    stream.setstate(std::ios::failbit);
  }
  return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:20 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/12 19:11:57 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

namespace lead {
static const char *const banner =
    "*-------------------------------------------*\n"
    "|    _                   _                  |\n"
    "|   | |    ___  __ _  __| |                 |\n"
    "|   | |   / _ \\/ _` |/ _` |  - simple       |\n"
    "|   | |__|  __/ (_| | (_| |   - PhoneBook   |\n"
    "|   |_____\\___|\\__,_|\\__,_|    - manager    |\n"
    "|                                           |\n"
    "*-------------------------------------------*";

void show_banner(void);
void print_with_width(const std::string &str, size_t width);
std::istream &getline_prompt(std::istream &stream, std::string &str,
                             const std::string &prompt);
std::istream &getline_prompt(std::istream &stream, int &k,
                             const std::string &prompt);
}  // namespace lead

#endif

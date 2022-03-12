/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:12:31 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/12 19:11:43 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>

/* disable error for unused parameater */
#define UNUSED(expr) \
  do {               \
    (void)expr;      \
  } while (false)

typedef bool (*CharChecker)(size_t i, const char &c);

class Contact {
 public:
  const std::string &firstname(void) const;
  bool set_firstname(const std::string &firstname);
  const std::string &lastname(void) const;
  bool set_lastname(const std::string &lastname);
  const std::string &nickname(void) const;
  bool set_nickname(const std::string &nickname);
  const std::string &phone_number(void) const;
  bool set_phone_number(const std::string &phone_number);
  const std::string &darkest_secret(void) const;
  bool set_darkest_secret(const std::string &darkest_secret);

 private:
  static const int min_name_len_ = 3;
  static const int max_name_len_ = 16;
  static const int min_phone_number_len_ = 13;
  static const int max_phone_number_len_ = 13;
  static const int min_darkest_secret_len_ = 1;
  static const int max_darkest_secret_len_ = 256;

  std::string firstname_;
  std::string lastname_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;

  static bool is_valid_name_char(size_t i, const char &c);
  static bool is_valid_nickname_char(size_t i, const char &c);
  static bool is_valid_phone_number_char(size_t i, const char &c);
  static bool is_valid_darkest_secret_char(size_t i, const char &c);
  bool is_valid_format(const std::string &str, CharChecker checker) const;
  bool is_valid_name(const std::string &name) const;
  bool is_valid_nickname(const std::string &nickname) const;
  bool is_valid_phone_number(const std::string &phone_number) const;
  bool is_valid_darkest_secret(const std::string &darkest_secret) const;
};

#endif

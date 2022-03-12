/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:18:08 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/12 17:20:44 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iomanip>
#include <iostream>

/* char checker ------------------------------------------------------------ */

bool Contact::is_valid_name_char(size_t i, const char &c) {
  UNUSED(i);
  return (std::isalpha(c));
}

bool Contact::is_valid_nickname_char(size_t i, const char &c) {
  if (i == 0) {
    return (std::isalpha(c));
  }
  return (std::isalnum(c));
}

bool Contact::is_valid_phone_number_char(size_t i, const char &c) {
  if (i == 3 || i == 8) return (c == '-');
  return (std::isdigit(c));
}

bool Contact::is_valid_darkest_secret_char(size_t i, const char &c) {
  UNUSED(i);
  return (std::isprint(c));
}

/* format checker ---------------------------------------------------------- */

bool Contact::is_valid_format(const std::string &str,
                              CharChecker checker) const {
  for (size_t i = 0; i < str.length(); ++i) {
    if (!checker(i, str[i])) {
      return false;
    }
  }
  return true;
}

bool Contact::is_valid_name(const std::string &name) const {
  if (name.length() < Contact::min_name_len_ ||
      Contact::max_name_len_ < name.length()) {
    return false;
  }
  return is_valid_format(name, Contact::is_valid_name_char);
}

bool Contact::is_valid_nickname(const std::string &nickname) const {
  if (nickname.length() < Contact::min_name_len_ ||
      Contact::max_name_len_ < nickname.length()) {
    return false;
  }
  return is_valid_format(nickname, Contact::is_valid_nickname_char);
}

bool Contact::is_valid_phone_number(const std::string &phone_number) const {
  if (phone_number.length() < Contact::min_phone_number_len_ ||
      Contact::max_phone_number_len_ < phone_number.length()) {
    return false;
  }
  return is_valid_format(phone_number, Contact::is_valid_phone_number_char);
}

bool Contact::is_valid_darkest_secret(const std::string &secret) const {
  if (secret.length() < Contact::min_darkest_secret_len_ ||
      Contact::max_darkest_secret_len_ < secret.length()) {
    return false;
  }
  return is_valid_format(secret, Contact::is_valid_darkest_secret_char);
}

/* accessor ---------------------------------------------------------------- */

const std::string &Contact::firstname(void) const { return firstname_; }

const std::string &Contact::lastname(void) const { return lastname_; }

const std::string &Contact::nickname(void) const { return nickname_; }

const std::string &Contact::phone_number(void) const { return phone_number_; }

const std::string &Contact::darkest_secret(void) const {
  return darkest_secret_;
}

bool Contact::set_firstname(const std::string &firstname) {
  bool is_valid = is_valid_name(firstname);
  if (is_valid) {
    firstname_ = firstname;
  }
  return is_valid;
}

bool Contact::set_lastname(const std::string &lastname) {
  bool is_valid = is_valid_name(lastname);
  if (is_valid) {
    lastname_ = lastname;
  }
  return is_valid;
}

bool Contact::set_nickname(const std::string &nickname) {
  bool is_valid = is_valid_nickname(nickname);
  if (is_valid) {
    nickname_ = nickname;
  }
  return is_valid;
}

bool Contact::set_phone_number(const std::string &phone_number) {
  bool is_valid = is_valid_phone_number(phone_number);
  if (is_valid) {
    phone_number_ = phone_number;
  }
  return is_valid;
}

bool Contact::set_darkest_secret(const std::string &secret) {
  bool is_valid = is_valid_darkest_secret(secret);
  if (is_valid) {
    darkest_secret_ = secret;
  }
  return is_valid;
}
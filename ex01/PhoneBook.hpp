/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:58:24 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/11 12:39:16 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H_
#define PHONE_BOOK_H_

#include "Contact.hpp"

class PhoneBook {
 public:
  bool add(void);
  void search(void);
  PhoneBook(void);

 private:
  const static int max_contacts_ = 8;
  Contact contacts_[max_contacts_];
  int cursor_;
  int space_left_;
  
  void print_header(void);
  void print_hr(void);
  void print_contact(size_t index);
};

#endif
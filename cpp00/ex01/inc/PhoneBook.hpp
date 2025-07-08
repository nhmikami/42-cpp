/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:58:55 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 15:58:55 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

class PhoneBook {
	private:
		Contact	_contacts[8];
		int		_contactCount;

		std::string	_truncateData(const std::string str) const;
		
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact() const;
};

#endif

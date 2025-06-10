

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

		std::string	_getInputData(std::string field) const;

	public:
		Contact();
		~Contact();

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;

		void	setContactInfo();
		void	displayContactInfo() const;
};

#endif

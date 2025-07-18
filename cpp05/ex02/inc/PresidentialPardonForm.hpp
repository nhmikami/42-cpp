/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:22:20 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:22:20 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	
	protected:
		void	beExecuted(void) const;
};

#endif

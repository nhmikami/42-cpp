/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:22:44 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:22:44 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class	RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		
	protected:
		void	beExecuted(void) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:07:56 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:07:56 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

	public:
		Harl();
		~Harl();
		
		void	complain(std::string level);
};

#endif

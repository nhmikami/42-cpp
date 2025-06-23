/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:20:10 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:20:10 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	protected:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);

		Brain&	operator=(const Brain& other);
		
		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string idea);
};

#endif

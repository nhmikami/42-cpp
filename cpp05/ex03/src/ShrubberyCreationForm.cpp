/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:24:50 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:24:50 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137, "undefined target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::beExecuted(void) const {
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	if (outfile.is_open()) {
		outfile << "         &&& &&  & &&\n";
		outfile << "     && &\\/&\\|& ()|/ @, &&\n";
		outfile << "     &\\/(/&/&||/& /_/)_&/_&\n";
		outfile << "  &() &\\/&|()|/&\\/ '%\" & ()\n";
		outfile << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		outfile << "&&   && & &| &| /& & % ()& /&&\n";
		outfile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
		outfile << "     &&     \\|||\n";
		outfile << "             |||\n";
		outfile << "             |||\n";
		outfile << "             |||\n";
		outfile << "       , -=-~  .-^- _\n";
		outfile.close();
		std::cout << "File " << filename << " created successfully!" << std::endl;
		return ;
	}
	std::cout << "Failed to create file " << filename << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:20:32 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/14 21:21:44 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTSFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <cstdlib>
#include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &f);
		virtual ~RobotomyRequestForm();

		std::string getTarget() const;

		RobotomyRequestForm		&operator=(const RobotomyRequestForm &f);

		virtual void			execute(const Bureaucrat &executor) const;
};//!RobotomyRequestForm

#endif
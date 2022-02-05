/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 21:12 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) { std::cout << "Bureaucrat default constructor called" << std::endl; }

Bureaucrat::Bureaucrat(Bureaucrat const &b) : _name(b.getName()), _grade(b.getGrade())
{ std::cout << "Bureaucrat copy constructor called" << std::endl; }

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : _name(name) 
{
	std::cout << "Bureaucraft string and int parameters called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called" << std::endl; }

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &b)
{
	this->setGrade(b.getGrade());
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b)

{
	os << "Bureaucrat named " << b.getName() << " has grade " << b.getGrade();
	return (os);
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Error: grade too high (< 1)"); }

char const	*Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Error: grade too low (> 150)"); }

std::string const	&Bureaucrat::getName(void) const { return (this->_name); }

int					Bureaucrat::getGrade(void) const { return (this->_grade); }

void				Bureaucrat::setGrade(int const grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	this->_grade = grade;
}

void				Bureaucrat::gradeUp(void) { this->setGrade(this->getGrade() - 1); }

void				Bureaucrat::gradeDown(void) { this->setGrade(this->getGrade() + 1); }
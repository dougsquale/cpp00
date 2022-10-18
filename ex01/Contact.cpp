/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:28:58 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/10/18 14:10:20 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
}
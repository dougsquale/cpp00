/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:35:10 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/10/20 12:08:03 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
	this->_idx = 0;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::_printContact(int idx)
{
	std::cout << std::endl << "--------------------" << std::endl;
	std::cout << "Full name	: " << this->_contacts[idx].getFirstName() + " " + this->_contacts[idx].getLastName()<< std::endl;
	std::cout << "Nickname	: " << this->_contacts[idx].getNickname() << std::endl;
	std::cout << "Phone number 	: " << this->_contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret	: " << this->_contacts[idx].getDarkestSecret() << std::endl;
	std::cout << "--------------------" << std::endl << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	str;
	
	str = "";
	if (this->_idx >= 8)
		std::cout << "/!\\ PhoneBook is full, overwriting the oldest contact" << std::endl;
		
	while (!std::cin.eof() && str == "")
	{
		std::cout << "First name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_idx % 8].setFirstName(str);
	}
	str = "";
	
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_idx % 8].setLastName(str);
	}
	str = "";

	while (!std::cin.eof() && str == "")
	{
		std::cout << "Nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_idx % 8].setNickname(str);
	}
	str = "";
	
	while ((!std::cin.eof() && str == "") || str.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_idx % 8].setPhoneNumber(str);
	}
	str = "";

	while (!std::cin.eof() && str == "")
	{
		std::cout << "Darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_idx % 8].setDarkestSecret(str);
	}

	this->_idx++;
}

void	PhoneBook::search(void)
{
	std::string str;

	if (this->_idx == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	
	for (int i = 0; i < this->_idx && i < 8; i++)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|";

		str = this->_contacts[i].getFirstName();
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str;
		std::cout << "|";

		str = this->_contacts[i].getLastName();
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str;
		std::cout << "|";

		str = this->_contacts[i].getNickname();
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str;
		std::cout << std::endl;
	}
	str = "";
	while ((!std::cin.eof() && str == "" || str.find_first_not_of("0123456789") != std::string::npos) || std::stoi(str) >= this->_idx || std::stoi(str) > 7 || std::stoi(str) < 0)
	{
		std::cout << "Enter the index of the contact you want to display: ";
		if (std::getline(std::cin, str) && str != "")
			;
		if (std::cin.eof())
			return ;
	}
	this->_printContact(std::stoi(str));
}
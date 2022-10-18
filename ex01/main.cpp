/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:14:31 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/10/18 14:49:32 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	std::string command;
	PhoneBook phbk;

	command = "";
	while (command != "EXIT")
	{
		std::cout << "Enter command:" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (std::cout << std::endl, 0);
		if (command == "ADD")
			phbk.add();
		else if (command == "SEARCH")
			phbk.search();
	}
	return (0);
}
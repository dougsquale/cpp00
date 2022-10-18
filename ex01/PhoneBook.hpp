/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:34:22 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/10/18 15:11:49 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:

	Contact _contacts[8];
	int		_idx;
	void	_printContact(int idx);

public:

	PhoneBook(void);
	~PhoneBook(void);
	void	add(void);
	void	search(void);
	
};

#endif
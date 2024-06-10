/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:57:07 by waziz             #+#    #+#             */
/*   Updated: 2024/05/12 20:52:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>


class PhoneBook
{
    private:
        Contact _Contacts[8];
        int     index;
    
    public:
        void    init_pb();
        void    add_contact();
        void    search_contact();
};

#endif
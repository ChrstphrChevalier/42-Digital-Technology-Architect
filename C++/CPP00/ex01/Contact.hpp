/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:59:47 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 14:27:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCTACT_HPP
# define CONCTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <string>

class Contact
{
    private:
        int index;
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    
    public:
        void    init_c(int index);
        void    view_contact() const;
        void    display() const;
};

#endif

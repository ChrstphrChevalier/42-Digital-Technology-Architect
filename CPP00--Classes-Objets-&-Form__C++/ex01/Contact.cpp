/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:34:45 by waziz             #+#    #+#             */
/*   Updated: 2024/05/20 12:33:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static bool valid_pn(std::string pn)
{
    for(int i = 0; pn[i]; i++)
        if (!std::isdigit(pn[i]) && pn[i] != '.' && pn[i] != '+')
        {
            std::cout << "Invalid Number -> Only : Digit / '.' / '+'" << std::endl;
            return false;
        }
    return true;
}


static  std::string get_Input(std::string s, int phone)
{
    std::string msg = "";
    bool valid = false;
    do
    {
        do
        {
            std::cout << s;
            std::getline(std::cin, msg);
        }
        while (msg.empty() && !std::cin.eof());
        if (std::cin.good() && !msg.empty())
        {
            if (phone == 0 || (phone == 1 && valid_pn(msg)))
                valid = true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (!std::cin.eof())
                std::cout << "Incorrect entry.. :(" << std::endl;
        }
    } while (!valid && !std::cin.eof());
    return (msg);
}

void    Contact::init_c(int index)
{
    // std::cin.ignore();
    this->index = index;
    if (!std::cin.eof())
        _firstName = get_Input("Enter Contact firstName : ", 0);
    if (!std::cin.eof())
        _lastName = get_Input("Enter Contact lastName : ", 0);
    if (!std::cin.eof())
        _nickName = get_Input("Enter Contact nickName : ", 0);
    if (!std::cin.eof())   
        _phoneNumber = get_Input("Enter Contact phoneNumber : ", 1);
    if (!std::cin.eof())
        _darkestSecret = get_Input("Enter Contact darkestSecret : ", 0);
}

static std::string    only_ten(std::string s)
{
    if (s.length() > 9)
        return (s.substr(0, 9) + ".");
    return (s);
}

void    Contact::view_contact() const
{
    if (_firstName.empty())
        return ;
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << only_ten(_firstName);
    std::cout << "|" << std::setw(10) << only_ten(_lastName);
    std::cout << "|" << std::setw(10) << only_ten(_nickName) << "|" << std::endl;
}

void    Contact::display() const
{
    if (_firstName.empty())
    {
        std::cout << "Void Contact" << std::endl;
        return ;
    }
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << std::endl;
    std::cout << "First Name : " << _firstName << std::endl;
    std::cout << "Last Name : " << _lastName << std::endl;
    std::cout << "Nickname : " << _nickName << std::endl;
    std::cout << "PhoneNumber : " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret : " << _darkestSecret << std::endl;
    std::cout << std::endl;
}
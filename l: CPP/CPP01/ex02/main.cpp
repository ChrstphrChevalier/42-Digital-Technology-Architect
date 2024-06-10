/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:42:29 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 14:27:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << std::endl;
    std::cout << "ADRESS OF VARIABLE -> &string : VALUE OF VARIABLE -> string" << std::endl;
    std::cout << &string << " : " << string << std::endl;
    std::cout << std::endl;
    std::cout << "ADRESS OF POINTER -> &stringPTR : VALUE OF VARIABLE -> stringPTR : VALUE OF THE POINTED VARIABLE -> *stringPTR" << std::endl;
    std::cout << &stringPTR << " : " << stringPTR << " : " << *stringPTR << std::endl;
    std::cout << std::endl;
    std::cout << "REFERENCE ADDRESS -> &stringREF : VALUE OF THE REFERENCED CHARACTER STRING -> stringREF" << std::endl;
    std::cout << &stringREF << " : " << stringREF << std::endl;
    std::cout << std::endl;

    return (0);
}
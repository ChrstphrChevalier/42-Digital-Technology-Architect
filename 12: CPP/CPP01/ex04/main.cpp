/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:50:42 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 15:09:44 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newFile.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage : './Sed <filename> <to_find> <replace>'" << std::endl;
        return (EXIT_FAILURE);
    }
    else
    {
        newFile nF = newFile(av[1], av[2], av[3]);
        nF.new_File();
    }
    return (0);
}
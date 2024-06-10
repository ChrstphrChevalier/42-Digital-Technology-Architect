/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:33:27 by waziz             #+#    #+#             */
/*   Updated: 2024/05/19 16:38:13 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int j = 0; argv[i][j]; j++)
                std::cout << (char)toupper(argv[i][j]);
            if (i < argc - 1)
                std::cout << ' ';
        }
    }
    std::cout << std::endl;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:14:56 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 18:41:58 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
    ClapTrap CT("Sasuke");
    ClapTrap ct("Itachi");
    ClapTrap Ct;
    Ct = ct;
    Ct.setName("Naruto");

    std::cout << std::endl;
    CT.getProfil();
    ct.getProfil();

    std::cout << std::endl;   
    ct.attack(CT.getName());
    CT.takeDamage(8);
    std::cout << std::endl;

    CT.getProfil();
    ct.getProfil();

    std::cout << std::endl;
    CT.beRepaired(5);
    CT.attack(ct.getName());
    ct.takeDamage(5);
    std::cout << std::endl;
    
    CT.getProfil();
    ct.getProfil();
    std::cout << std::endl;

    std::cout << Ct.getName() << " tries to protect Sasuke..." << std::endl;
    ct.attack(Ct.getName());
    Ct.takeDamage(100);
    Ct.beRepaired(500);
    Ct.attack(ct.getName());
    std::cout << std::endl;
    
    return (0);
}
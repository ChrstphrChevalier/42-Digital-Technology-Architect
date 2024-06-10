/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:14:56 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 21:35:40 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main()
{
    ScavTrap Gojo("Gojo");
    std::cout << std::endl;

    ScavTrap Itadori;
    Itadori = Gojo;
    Itadori.setName("Itadori");
    std::cout << std::endl;

    ScavTrap Jujutsu;
    Jujutsu.setName("Sukuna");
    std::cout << std::endl;

    Gojo.getProfil();
    Itadori.getProfil();
    Jujutsu.getProfil();
    std::cout << std::endl;

    Jujutsu.attack(Itadori.getName());
    Itadori.takeDamage(30);
    std::cout << std::endl;

    Gojo.getProfil();
    Itadori.getProfil();
    Jujutsu.getProfil();
    std::cout << std::endl;

    Jujutsu.attack(Itadori.getName());
    Itadori.takeDamage(30);
    std::cout << std::endl;

    Gojo.getProfil();
    Itadori.getProfil();
    Jujutsu.getProfil();
    std::cout << std::endl;

    Itadori.beRepaired(15);
    Itadori.attack(Jujutsu.getName());
    Jujutsu.takeDamage(3);
    Gojo.attack(Jujutsu.getName());
    Gojo.guardGate();
    Jujutsu.takeDamage(97);
    Jujutsu.beRepaired(100);
    Jujutsu.guardGate();
    
    return (0);
}
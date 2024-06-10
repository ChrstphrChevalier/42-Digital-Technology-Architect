/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:14:56 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 22:03:29 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

int main()
{
    FragTrap Gojo("Gojo");
    std::cout << std::endl;

    FragTrap Itadori;
    Itadori = Gojo;
    Itadori.setName("Itadori");
    std::cout << std::endl;

    FragTrap Jujutsu;
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
    Jujutsu.takeDamage(97);
    Jujutsu.beRepaired(100);
    Jujutsu.highFivesGuys();
    std::cout << std::endl;
    
    return (0);
}
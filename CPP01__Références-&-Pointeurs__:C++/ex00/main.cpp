/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieland.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:22:23 by waziz             #+#    #+#             */
/*   Updated: 2024/05/13 21:32:32 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string stack;

    std::cout << "A Zombie comes to life in the stack." << std::endl;
    std::cout << "What name do you want to give it?" << std::endl;
    std::cout << "> ";
    std::cin >> stack;
    std::cout << std::endl;

    Zombie stacker;
    stacker.setName(stack);
    stacker.announce();
    std::cout << std::endl;

    std::string heap;

    std::cout << "A Zombie comes to life in the heap." << std::endl;
    std::cout << "What name do you want to give it?" << std::endl;
    std::cout << "> ";
    std::cin >> heap;
    std::cout << std::endl;

    Zombie *heaper = newZombie(heap);
    heaper->announce();
    destroyer(heaper);
    std::cout << std::endl;

    std::cout << "A random zombie shows up" << std::endl;
    std::cout << "Michael Jackson comes back to thriller life" << std::endl;
    randomChump("Mickeal Jackson");
    std::cout << std::endl;

    std::cout << stack << " is eliminated." << std::endl;
    return (0);
}
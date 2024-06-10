/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:38:46 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 13:58:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *Volt = new Dog();
    const Animal *Garfield = new Cat();
    std::cout << std::endl;

    std::cout << Volt->getType() << " is alive" << std::endl;
    std::cout << Garfield->getType() << " is alive" << std::endl;
    std::cout << std::endl;

    Garfield->makeSound();
    Volt->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete Volt;
    delete Garfield;
    std::cout << std::endl;

    std::cout << " - WRONGTEST - " << std::endl;
    std::cout << std::endl;

    WrongAnimal *wAnimal = new WrongAnimal();
    WrongCat *wCat = new WrongCat();
    std::cout << std::endl;

    std::cout << wCat->getType() << " is alive " << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    wAnimal->makeSound();
    wCat->makeSound();
    std::cout << std::endl;

    std::cout << "_isFalse = false;" << std::endl;
    std::cout << std::endl;

    wCat->set_isFalse(false);
    wCat->makeSound();
    std::cout << std::endl;

    std::cout << "_isFalse = true;" << std::endl;
    std::cout << std::endl;

    wCat->set_isFalse(true);
    wCat->makeSound();
    std::cout << std::endl;
    
    delete wCat;
    delete wAnimal;
    
    return (0);
}
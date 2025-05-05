/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:19:11 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 20:31:10 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string     Type;

    public:
        Animal();
        Animal(std::string newType);
        Animal(const Animal& other);
        Animal& operator=(const Animal& affect);
        virtual ~Animal();

        virtual void                makeSound() const;
        virtual std::string getType() const;
        virtual void        setType(std::string newType);
};

#endif

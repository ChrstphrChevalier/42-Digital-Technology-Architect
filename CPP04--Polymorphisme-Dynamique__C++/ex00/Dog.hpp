/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:35:44 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:36:23 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string newType);
        Dog(const Dog& other);
        Dog& operator=(const Dog& affect);
        ~Dog();

        void        makeSound() const;
        std::string getType() const;
        void        setType(std::string newType);
};

#endif

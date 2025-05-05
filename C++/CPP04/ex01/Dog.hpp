/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:35:44 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 18:32:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*   _brain;

    public:
        Dog();
        Dog(std::string newType);
        Dog(const Dog& other);
        Dog& operator=(const Dog& affect);
        ~Dog();

        void        makeSound() const;
        Brain*       getBrain() const;
};

#endif

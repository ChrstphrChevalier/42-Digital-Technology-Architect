/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:19:11 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 20:34:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected:
        std::string     Type;

    public:
        AAnimal();
        AAnimal(std::string newType);
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& affect);
        virtual ~AAnimal();

        virtual void                makeSound() const = 0;
        virtual std::string getType() const;
        virtual void        setType(std::string newType);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:51:12 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:34:53 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string newType);
        Cat(const Cat& other);
        Cat& operator=(const Cat& affect);
        ~Cat();

        void        makeSound() const;
        std::string getType() const;
        void        setType(std::string newType);
};

#endif

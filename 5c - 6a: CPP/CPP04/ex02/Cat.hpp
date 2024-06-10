/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:51:12 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 20:38:46 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain*  _brain;

    public:
        Cat();
        Cat(std::string newType);
        Cat(const Cat& other);
        Cat& operator=(const Cat& affect);
        ~Cat();

        void        makeSound() const;
        Brain*      getBrain() const;
};

#endif

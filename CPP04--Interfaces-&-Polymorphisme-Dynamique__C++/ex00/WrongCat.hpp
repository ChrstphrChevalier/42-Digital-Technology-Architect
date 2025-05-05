/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:49:21 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:38:47 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private:
        bool        _isFalse;

    public:
        WrongCat();
        WrongCat(std::string newType);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& affect);
        ~WrongCat();

        void        makeSound() const;
        std::string getType() const;
        void        setType(std::string newType);
        void        set_isFalse(bool iF); 
};

#endif

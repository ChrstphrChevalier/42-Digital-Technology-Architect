/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:07:42 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 21:12:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class   ClapTrap
{
    protected:
        std::string             _name;
        unsigned int            _hitPoint;
        int                     _Energy;
        int                     _attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& base);
        virtual ~ClapTrap();
        ClapTrap&       operator=(const ClapTrap& affect);
        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);

        void            setName(std::string newName);
        std::string     getName()   const;
        void            getProfil() const;
};

#endif

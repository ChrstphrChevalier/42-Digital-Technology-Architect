/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:16:05 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 14:27:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string name;

    public:
        void            announce();
        void            setName(std::string n);
        std::string     getName() const;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);
void    destroyer(Zombie *z);

#endif
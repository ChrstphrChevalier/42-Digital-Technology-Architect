/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:42:10 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 14:27:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <limits>

class Zombie
{
    private:
        std::string name;

    public:
        void            announce(int i);
        void            setName(std::string n);
        std::string     getName() const;
};

void    comes_out(int n);

#endif
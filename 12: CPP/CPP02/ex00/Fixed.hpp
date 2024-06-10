/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:54:01 by waziz             #+#    #+#             */
/*   Updated: 2024/05/18 18:13:50 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 _fixed;
        static const int    _bit = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& affect);
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(const int raw);
};

#endif
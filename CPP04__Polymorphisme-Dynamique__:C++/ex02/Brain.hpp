/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:36:07 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 19:40:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    private:
        std::string _name;
        std::string _ideas[100];
        int         _index;


    public:
        Brain();
        Brain(std::string name);
        Brain(const Brain& other);
        Brain& operator=(const Brain& affect);
        ~Brain();

        std::string getName() const;
        void        getIdea(long long n) const;
        void        setIdea(std::string idea);
};

#endif

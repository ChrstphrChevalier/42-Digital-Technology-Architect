/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newFile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:40:26 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 14:57:02 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWFILE_HPP
# define NEWFILE_HPP

# include <iostream>
# include <string>
# include <fstream>

class newFile
{
    private:
        std::string _filename;
        std::string _replace;
        std::string _s1;
        std::string _s2;

    public:
        newFile(std::string filename, std::string to_find, std::string replace);
        void    new_File();
};

#endif
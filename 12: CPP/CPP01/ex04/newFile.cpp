/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newFile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:44:00 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 15:19:11 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newFile.hpp"

newFile::newFile(std::string filename, std::string to_find, std::string replace) :
    _filename(filename),
    _replace(filename + ".replace"),
    _s1(to_find),
    _s2(replace)
{}

void    newFile::new_File()
{
    std::ifstream ifs(_filename);
    if (ifs.is_open())
    {
        std::string content;
        if (std::getline(ifs, content, '\0'))
        {
            size_t pos = content.find(_s1);
            while (pos != std::string::npos)
            {
                content.erase(pos, _s1.length());
                content.insert(pos, _s2);
                pos = content.find(_s1);
            }
            std::ofstream ofs(_replace);
            ofs << content;
            ofs.close();
        }
        else
            std::cout << "Empty file." << std::endl;
        ifs.close();
    }
    else
    {
        std::cout << "Unable to open the file." << std::endl;
        exit(EXIT_FAILURE);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:13:05 by waziz             #+#    #+#             */
/*   Updated: 2024/06/05 10:57:39 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#pragma once

# include "colors.hpp"

# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange {
	private:
		BitcoinExchange();
		
		std::multimap<std::string, std::string>	_price;
		std::multimap<std::string, std::string>	_quantity;

		void	dcDate(std::string key);
		void	setMaps(std::string filename);
		bool	icDate(std::string key);
		bool	icValue(std::string key, std::string value);
		void	bitEx();

	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& affect);
		~BitcoinExchange();

};

#endif
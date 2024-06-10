/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:21:40 by waziz             #+#    #+#             */
/*   Updated: 2024/06/05 10:59:49 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange : Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::cout << "BitcoinExchange : Custom constructor called" << std::endl;
	std::cout << std::endl;
	bool c = true;
	try {
		setMaps(filename);
	} catch (std::exception& e) {
		c = false;
		std::cout << REDD << e.what() << RST << std::endl;
	}
	if (c) {
		bitEx();
		std::cout << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _price(other._price), _quantity(other._quantity) {
	std::cout << "BitcoinExchange : Copy constructor called" << std::endl;
	bool valid = false;
	if (_quantity.empty()) {
		std::cout << std::endl;
		std::cout << REDD << "No investments registered ..." << RST << std::endl;
	}
	if (_price.empty()) {
		std::cout << std::endl;
		std::cout << REDD << "Empty data file ..." << RST << std::endl;
	}
	else
		valid = true;
	if (valid) {
		std::cout << std::endl;
		bitEx();
		std::cout << std::endl;
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& affect) {
	if (this != &affect) {
		_price = affect._price;
		_quantity = affect._quantity;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange : Destructor called" << std::endl;
}

void	BitcoinExchange::dcDate(std::string key) {
	if (key.length() != 10)
		throw std::logic_error("Invalid 'data' date");
	if (key[4] != '-' || key[7] != '-'
		|| !isdigit(key[0]) || !isdigit(key[1]) || !isdigit(key[2]) || !isdigit(key[3])
		|| !isdigit(key[5]) || !isdigit(key[6]) || !isdigit(key[8]) || !isdigit(key[9]))
		throw std::logic_error("Invalid 'data' date");

	std::string year = key.substr(0, 4);
	int y = std::stoi(year);
	if (y < 2009 || y > 2024)
		throw std::logic_error("Invalid 'data' year");
	std::string month = key.substr(5, 2);
	int m = std::stoi(month);
	if (m < 1 || m > 12)
		throw std::logic_error("Invalid 'data' month");
	std::string day = key.substr(8);
	int d = std::stoi(day);
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		if (d < 1 || d > 31)
			throw std::logic_error("Invalid 'data' day");
	if (m == 4 || m == 6 || m == 9 || m == 11)
		if (d < 1 || d > 30)
			throw std::logic_error("Invalid 'data' day");
	if (m == 2) {
		if (y == 2024 || y == 2020 || y == 2016 || y == 2014 || y == 2010) {
			if (d < 0 || d > 29)
				throw std::logic_error("Invalid 'data' day");
		} else {
			if (d < 0 || d > 28)
				throw std::logic_error("Invalid 'data' day");
		}
	}
	if (y == 2009 && m == 1 && d < 3)
		throw std::logic_error("Invalid 'data' date : bitcoin did not exist");
}


void	BitcoinExchange::setMaps(std::string filename) {
	// DATA.CSV
	std::ifstream ifs("data/data.csv");
	if (!ifs)
		throw std::runtime_error("Error: could not open file.");
	
	std::string line;
	if (!std::getline(ifs, line)) {
		std::cout << REDD << "Empty data file ..." << RST << std::endl;
		return;
	}

	while (std::getline(ifs, line)) {
		std::size_t pos = line.find(',');
		if (pos == 0 || pos == line.size() - 1 || pos == std::string::npos)
			throw std::logic_error("Invalid 'data.csv' line.");

		std::string key = line.substr(0, pos);
		dcDate(key);

		std::string value = line.substr(pos + 1);
		bool		point = false;
		for (size_t i = 0; i < value.size(); i++) {
			if (value[i] == '.' && point)
				throw std::logic_error("Invalid 'data' value");
			if (value[i] == '.') {
				point = true;
				continue;
			}
			if (!isdigit(value[i]))
				throw std::logic_error("Invalid 'data' value");
		}
		double v = std::stod(value);
		if (v > 75000)
			throw std::logic_error("Invalid 'data' value : Bitcoin never reached its peak");
		_price.insert(std::make_pair(key, value));
	}
	ifs.close();

	// INPUT.TXT
	std::ifstream ifst(filename);
	if (!ifst)
		throw std::runtime_error("Error: could not open file.");
	
	std::string iline;
	if (!std::getline(ifst, iline)) {
		std::cout << REDD << "No investments registered ..." << RST << std::endl;
		return;
	}

	while (std::getline(ifst, iline)) {
		std::size_t pos = iline.find('|');
		if (pos == 0)
			throw std::logic_error("Invalid 'input.txt' line.");

		std::string key = iline.substr(0, pos);
		std::string value = iline.substr(pos + 1);
		
		_quantity.insert(std::make_pair(key, value));
	}
	ifst.close();
}

bool	BitcoinExchange::icDate(std::string key) {
	if (key.length() != 10) {
		std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
		return false;
	}
	if (key[4] != '-' || key[7] != '-'
		|| !isdigit(key[0]) || !isdigit(key[1]) || !isdigit(key[2]) || !isdigit(key[3])
		|| !isdigit(key[5]) || !isdigit(key[6]) || !isdigit(key[8]) || !isdigit(key[9])) {
		std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
		return false;
	}
	std::string year = key.substr(0, 4);
	int y = std::stoi(year);
	if (y < 2009 || y > 2024) {
		std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
		return false;
	}
	std::string month = key.substr(5, 2);
	int m = std::stoi(month);
	if (m < 1 || m > 12) {
		std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
		return false;
	}
	std::string day = key.substr(8);
	int d = std::stoi(day);
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		if (d < 1 || d > 31) {
			std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
			return false;
		}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		if (d < 1 || d > 30) {
			std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
			return false;
		}
	if (m == 2) {
		if (y == 2024 || y == 2020 || y == 2016 || y == 2014 || y == 2010) {
			if (d < 0 || d > 29) {
				std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
				return false;
			}
		} else {
			if (d < 0 || d > 28) {
				std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
				return false;
			}
		}
	}
	if (y == 2009 && m == 1 && d < 3) {
		std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << RST << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::icValue(std::string key, std::string value) {
	if (value.empty()) {
		std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << " : empty value" << RST << std::endl;
		return false;
	}
	bool	point = false;
	for (size_t i = 0; i < value.size(); i++) {
		if (value[i] == '.' && point) {
			std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << " : " << value << RST << std::endl;
			return false;
		}
		if (value[i] == '.') {
			point = true;
			continue;
		}
		if (!isdigit(value[i])) {
			if (value[i] == '-')
				std::cout << REDD << "Error:" << YLLW << " not a positive number" << REDD << " -> " << MAGN << value << RST << std::endl;
			else
				std::cout << REDD << "Error:" << YLLW << " bad input" << REDD << " => " << MAGN << key << " : " << value << RST << std::endl;
			return false;
		}
	}
	double v = std::stod(value);
	if (v > 75000) {
		std::cout << REDD << "Error:" << YLLW << " bad input :" << ORNG << " Bitcoin never reached its peak" << REDD << " => " << MAGN << value << RST << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::bitEx() {
	std::multimap<std::string, std::string>::iterator itbpr = _price.begin();
	std::multimap<std::string, std::string>::iterator itepr = _price.end();

	std::multimap<std::string, std::string>::iterator itbqu = _quantity.begin();
	std::multimap<std::string, std::string>::iterator itequ = _quantity.end();

	while (itbqu != itequ) {
		std::string qkey = itbqu->first;
		std::string qvalue = itbqu->second;

		if (!icDate(qkey) || !icValue(qkey, qvalue)) {
			itbqu++;
			continue;
		}

		double vq = std::stod(qvalue);
		bool	found = false;
		while (itbpr != itepr) {
			std::string pkey = itbpr->first;
			std::string pvalue = itbpr->second;

			if (pkey == qkey) {
				double vp = std::stod(pvalue);
				std::cout << qkey << CYAN << " => " << RST << qvalue << CYAN << " = " << RST << (vq * vp) << std::endl;
				found = true;
				break ;
			}
			itbpr++;
		}
		if (!found) {
			itbpr = _price.begin();
			std::multimap<std::string, std::string>::iterator itpr;
			std::string qcompact = qkey.substr(0, 4) + qkey.substr(5, 2) + qkey.substr(8);
			long long int qc = std::stoll(qcompact);
			long long int gap = UINT_MAX;
			long long int calcul;
			while (itbpr != itepr) {
				std::string pkey = itbpr->first;
				std::string pcompact = pkey.substr(0, 4) + pkey.substr(5, 2) + pkey.substr(8);
				long long int pc = std::stoll(pcompact);
				if (pc > qc)
					calcul = pc - qc;
				else
					calcul = qc - pc;
				if (calcul < gap) {
					gap = calcul;
					itpr = itbpr; 
				}
				itbpr++;
			}
			std::string pvalue = itpr->second;
			double vp = std::stod(pvalue);
			std::cout << qkey << CYAN << " => " << RST << qvalue << CYAN << " = " << RST << (vq * vp) << std::endl;
		}
		itbqu++;
	}
}
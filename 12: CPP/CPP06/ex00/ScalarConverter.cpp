/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:09:53 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 21:17:11 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& affect) {
	(void)affect;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

// SCALARCONVERTER

enum _Type {
	C,
	I,
	F,
	D,
	Err,
};

// CONVERTERS

static int		str_int(const std::string& input) {
	int					iinput;
	std::stringstream	ss(input);

	ss >> iinput;
	return iinput;
}

static float	str_float(const std::string& input) {
	float				finput;
	std::stringstream	ss(input.substr(0, input.length() - 1));

	ss >> finput;
	return finput;
}

static double	str_double(const std::string& input) {
	double				dinput;
	std::stringstream	ss(input);

	ss >> dinput;
	return dinput;
}

// CHECKERS

static bool isChar(const std::string& input) {
	if (input.length() != 1)
		return false;
	if (input[0] < std::numeric_limits<char>::min()
		|| input[0] > std::numeric_limits<char>::max()
		|| isdigit(input[0]))
		return false;
	return true;
}

static bool isInt(const std::string& input) {
	size_t i = 0;
	for (i = input[i] == '-' ? 1 : 0; i < input.length(); i++)
		if (!isdigit(input[i]))
			return false;
	return true;
}

static bool isFloat(const std::string& input) {
	if (input == "+inff" || input == "-inff" || input == "nanf")
		return true;

	size_t	end = input.length() - 1;
	if (input[end] != 'f')
		return false;
		
	bool point = false;
	bool soustract = false;
	for (size_t i = 0; i < end; i++) {
		if (input[i] == '.' && point)
			return false;
		else if (input[i] == '.') {
			point = true;
			continue;
		}
		if (input[i] == '-' && soustract)
			return false;
		else if (input[i] == '-') {
			soustract = true;
			continue;
		}
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

static bool isDouble(const std::string& input) {
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
		
	bool point = false;
	bool soustract = false;
	size_t	end = input.length();
	for (size_t i = 0; i < end; i++) {
		if (input[i] == '.' && point)
			return false;
		else if (input[i] == '.') {
			point = true;
			continue;
		}
		if (input[i] == '-' && soustract)
			return false;
		else if (input[i] == '-') {
			soustract = true;
			continue;
		}
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

static bool	specialCasef(const std::string& input) {
	return (input == "-inff" || input == "+inff" || input == "nanf");
}

static bool	specialCased(const std::string& input) {
	return (input == "-inf" || input == "+inf"  || input == "nan");
}

static bool hasPoint(const std::string& input) {
    for (size_t i = 0; i < input.size(); i++)
        if (input[i] == '.')
            return true;
	return false;
}

// PRINTER

static void	character(char c) {
	std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}

static void	integer(int i) {
	if (isprint(i))
		std::cout << "char : '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char : Non Displayable" << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << i << ".0f" << std::endl;
	std::cout << "double : " << i << ".0" << std::endl;
}

static void	floater(const std::string& input, float f) {
	std::stringstream ss;
	ss << f;
    std::string hP = ss.str();

	if (specialCasef(input)) {
		std::cout << "char : Impossible" << std::endl;
		std::cout << "int : Impossible" << std::endl;
		std::cout << "float : " << input << std::endl;
		std::cout << "double : " << input.substr(0, input.length() - 1) << std::endl;
	} else {
		if (isprint(f))
			std::cout << "char : '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char : Non Displayable" << std::endl;
		std::cout << "int : " << static_cast<int>(f) << std::endl;
		if (hasPoint(hP)) {
			std::cout << "float : " << f << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(f) << std::endl;
		} else {
			std::cout << "float : " << f << ".0f" << std::endl;
			std::cout << "double : " << static_cast<double>(f) << ".0" << std::endl;
		}
	}
}

static void	doubler(const std::string& input, double d) {
	std::stringstream ss;
	ss << d;
    std::string hP = ss.str();

	if (specialCased(input)) {
		std::cout << "char : Impossible" << std::endl;
		std::cout << "int : Impossible" << std::endl;
		std::cout << "float : " << input + "f" << std::endl;
		std::cout << "double : " << input << std::endl;
	} else {
		if (isprint(d))
			std::cout << "char : '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char : Non Displayable" << std::endl;
		std::cout << "int : " << static_cast<int>(d) << std::endl;
		if (hasPoint(hP)) {
			std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double : " << d << std::endl;
		} else {
			std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
			std::cout << "double : " << d << ".0" << std::endl;
		}
	}
}

// SCALARCONVERTER

static _Type	getType(const std::string& input) {
	if (isChar(input))
		return C;
	if (isInt(input))
		return I;
	if (isFloat(input) || specialCasef(input))
		return F;
	if (isDouble(input) || specialCased(input))
		return D;
	return Err;
}

static bool	limitExercise(const std::string input)
{
	
	for (size_t i = 0; i < input.length(); i++)
		if (!isdigit(input[i]) && input[i] != '-')
		{
			if (input[i] == '.')
				continue;
			else
				return false;
		}
	
	std::stringstream ss(input);
	long long int number;
	ss >> number;
	if (number > 2147483647 || number < -2147483648)
		return true;
	return false;
}

void	ScalarConverter::convert(const std::string& input) {
	if (limitExercise(input)) {
		std::cout << "In this exercise we work between the max and min limits of the int.";
		std::cout << " Thank you for your understanding." << std::endl;
		return ;
	}
	
	switch (getType(input)) {
		case C:
			character(input[0]);
			break;
		case I:
			integer(str_int(input));
			break;
		case F:
			floater(input, str_float(input));
			break;
		case D:
			doubler(input, str_double(input));
			break;
		default:
			std::cout << "Wait wait wait.. Are you kidding me !? 🤨" << std::endl;
            break;
	}
}
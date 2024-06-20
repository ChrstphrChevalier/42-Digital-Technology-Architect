/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:38:53 by waziz             #+#    #+#             */
/*   Updated: 2024/06/20 13:55:38 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Webserv.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		cout << REDD << "Usage : " << RST << "./webserv <config.ini>" << endl;
		return (0);
	}
	cout << endl;
	try {
		Webserv ws = Webserv(av[1]);
	} catch (exception& e) {
		cout << REDD << e.what() << RST << endl;
	}
	cout << endl;
	cout << LIME << "Exiting ..." << RST << endl;
	cout << endl;
	return (0);
}
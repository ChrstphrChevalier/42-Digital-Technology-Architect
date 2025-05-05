/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:00:59 by waziz             #+#    #+#             */
/*   Updated: 2024/05/31 14:43:50 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template <typename T1, typename T2>
static void    try_catch(typename T1::const_iterator (*f)(const T1&, T2), const T1& container, T2 checker)
{
    try {
        (*f)(container, checker);
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
}

int main() {
	std::vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);

	std::list<int> myList;
	myList.push_back(6);
	myList.push_back(7);
	myList.push_back(8);
	myList.push_back(9);
	myList.push_back(10);

	std::deque<int> myDeque;
	myDeque.push_back(11);
	myDeque.push_back(12);
	myDeque.push_back(13);

	std::set<int> mySet;
	mySet.insert(14);
	mySet.insert(15);
	mySet.insert(16);
	mySet.insert(17);
	mySet.insert(18);
	
	std::unordered_set<int> myUS; // Tableau d'int non trié vide. 

	std::cout << LAVN << " -- EASYFIND in myVector -- " << RST << std::endl;
	try_catch(easyfind, myVector, 1);
	try_catch(easyfind, myVector, 6);
	std::cout << std::endl;

	std::cout << LAVN << " -- EASYFIND in myList -- " << RST << std::endl;
	try_catch(easyfind, myList, 6);
	try_catch(easyfind, myList, 11);
	std::cout << std::endl;

	std::cout << LAVN << " -- EASYFIND in myDeque -- " << RST << std::endl;
	try_catch(easyfind, myDeque, 11);
	try_catch(easyfind, myDeque, 14);
	std::cout << std::endl;

	std::cout << LAVN << " -- EASYFIND in mySet -- " << RST << std::endl;
	try_catch(easyfind, mySet, 14);
	try_catch(easyfind, mySet, 19);
	std::cout << std::endl;

	std::cout << LAVN << " -- EASYFIND DANS myUS -- " << RST << std::endl;
	try_catch(easyfind, myUS, 19);
	try_catch(easyfind, myUS, 21);
	std::cout << std::endl;

	return (0);
}

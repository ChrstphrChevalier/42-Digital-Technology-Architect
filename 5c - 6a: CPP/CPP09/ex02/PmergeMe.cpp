/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:15:58 by waziz             #+#    #+#             */
/*   Updated: 2024/07/23 22:35:19 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

template <typename Container, typename Iterator>
void PmergeMe::insertionSort(Container& container, Iterator start, Iterator end) {
	(void)container;
    for (Iterator it = start; it != end; ++it) {
        typename Container::value_type temp = *it;
        Iterator it2 = it;
        while (it2 != start && *(std::prev(it2)) > temp) {
            *it2 = *(std::prev(it2));
            --it2;
        }
        *it2 = temp;
    }
}

template <typename Container, typename Iterator>
void PmergeMe::merge(Container& container, Iterator left, Iterator mid, Iterator right) {
	(void)container;
    std::vector<typename Container::value_type> leftVec(left, mid);
    std::vector<typename Container::value_type> rightVec(mid, right);

    Iterator it = left;
    typename std::vector<typename Container::value_type>::iterator itLeft = leftVec.begin();
    typename std::vector<typename Container::value_type>::iterator itRight = rightVec.begin();

    while (itLeft != leftVec.end() && itRight != rightVec.end()) {
        if (*itLeft <= *itRight) {
            *it = *itLeft;
            ++itLeft;
        } else {
            *it = *itRight;
            ++itRight;
        }
        ++it;
    }

    while (itLeft != leftVec.end()) {
        *it = *itLeft;
        ++itLeft;
        ++it;
    }

    while (itRight != rightVec.end()) {
        *it = *itRight;
        ++itRight;
        ++it;
    }
}


template <typename Container, typename Iterator>
void PmergeMe::_FordJohnsonSort(Container& container, Iterator left, Iterator right) {
    if (std::distance(left, right) <= 10) {
        insertionSort(container, left, right);
    } else {
        Iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        _FordJohnsonSort(container, left, mid);
        _FordJohnsonSort(container, mid, right);
        merge(container, left, mid, right);
    }
}

template <typename Container>
void PmergeMe::FordJohnson(Container& container) {
    _FordJohnsonSort(container, container.begin(), container.end());
}

template <typename T>
void PmergeMe::display(const T& container, int option)
{
	std::cout << std::endl;
	std::cout << LIME << "INSIDE" << std::endl;
	if (option == 0)
		std::cout << YLLW << ITAL << "List" << RST << ITAL << " container" << GRY1 << " -> " << RST;
	else
		std::cout << YLLW << ITAL << "Deque" << RST << ITAL << " container" << GRY1 << " -> " << RST;
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << PURP << *it << RST << " ";
    std::cout << std::endl;
}

PmergeMe::PmergeMe(int ac, char **av) {
	std::list<int>		arrayList;
	std::deque<int> 	arrayDeque;


	srand(time(NULL));
	for (int i = 1; i < ac; i++) {
		int value = atoi(av[i]);
		if (value <= 0) {
			std::cerr << REDD << "Invalid input" << GRY1 <<  " -> " << ORNG << av[i] << GRY1 << " - " << RST << ITAL << "Only positive integers within the limits of INT_MAX are allowed" << std::endl;
            exit(1);
		}
		arrayList.push_back(value);
		arrayDeque.push_back(value);
	}
	
	std::cout << CYAN << "Before" << GRY1 << " : " << RST << std::endl;
	display(arrayList, 0);
	display(arrayDeque, 1);
	std::cout << std::endl;

	clock_t start = clock();
	FordJohnson(arrayList);
	clock_t end = clock();
	double timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	start = clock();
	FordJohnson(arrayDeque);
	end = clock();
	double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << CYAN << "After" << GRY1 << " : " << RST << std::endl;
	display(arrayList, 0);
	display(arrayDeque, 1);
	std::cout << std::endl;

	assert(std::is_sorted(arrayList.begin(), arrayList.end()));
    assert(std::is_sorted(arrayDeque.begin(), arrayDeque.end()));

	std::cout << ITAL << "Sorting of " << YLLW << ITAL << arrayDeque.size() << RST << ITAL << " elements with " << YLLW << ITAL << "std::deque" << RST << ITAL << " in : " << CYAN << ITAL << timeDeque << RST << ITAL << " us" << RST << std::endl;
    std::cout << ITAL << "Sorting of " << YLLW << ITAL << arrayList.size() << RST << ITAL << " elements with " << YLLW << ITAL << "std::list" << RST << ITAL << " in : " << CYAN << ITAL << timeList << RST << ITAL << " us" << RST << std::endl;
	std::cout << std::endl;
    if (arrayDeque == std::deque<int>(arrayList.begin(), arrayList.end()))
        std::cout << "- " << LIME << ITAL << "The sorted sequences are equal" << RST << " -" << std::endl;
    else
        std::cout << "- " << REDD << ITAL << "The sorted sequences are not equal" << RST << " -" << std::endl;
}
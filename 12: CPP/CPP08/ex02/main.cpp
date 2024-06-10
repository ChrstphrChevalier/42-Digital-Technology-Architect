/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:15:18 by waziz             #+#    #+#             */
/*   Updated: 2024/06/03 11:55:37 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <list>

void 	subject_test() {
	std::cout << LIME << "-> SUBJECT TEST" << RST << std::endl;
	MutantStack<int> mstack;
	
	std::cout << ORNG << "PUSH 5" << RST << std::endl;
	mstack.push(5);
	std::cout << ORNG << "PUSH 17" << RST << std::endl;
	mstack.push(17);
	std::cout << std::endl;
	
	std::cout << CYAN << "AFFICHAGE DU TOP DE LA STACK" << RST << std::endl;
	std::cout << LIME << mstack.top() << RST << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "SUPPRESSION DU TOP DE LA STACK" << RST << std::endl;
	mstack.pop();
	std::cout << "... ... ..." << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "AFFICHAGE DE LA TAILLE DE LA STACK" << RST << std::endl;
	std::cout << LIME << mstack.size() << RST << std::endl;
	std::cout << std::endl;
	
	std::cout << ORNG << "PUSH 3" << RST << std::endl;
	mstack.push(3);
	std::cout << ORNG << "PUSH 5" << RST << std::endl;
	mstack.push(5);
	std::cout << ORNG << "PUSH 737" << RST << std::endl;
	mstack.push(737);
	std::cout << ORNG << "PUSH 0" << RST << std::endl;
	mstack.push(0);
	std::cout << std::endl;

	std::cout << PURP << "INITIALISATION ITERATOR DEBUT" << RST << std::endl;
	MutantStack<int>::it itb = mstack.begin();
	std::cout << PURP << "INITIALISATION ITERATOR FIN" << RST << std::endl;
	MutantStack<int>::it ite = mstack.end();
	std::cout << std::endl;
	
	std::cout << PURP << "++DEBUT" << RST << std::endl;
	++itb;
	std::cout << PURP << "--DEBUT" << RST << std::endl;
	--itb;
	std::cout << std::endl;

	std::cout << CYAN << "TANT QUE DEBUT N'EST PAS FIN" << RST << std::endl;
	std::cout << CYAN << "AFFICHE LA VALEUR POINTÉ PAR DEBUT" << RST << std::endl;
	while (itb != ite) {
		std::cout << LIME << *itb << RST << std::endl;
		std::cout << PURP << "DEBUT++" << RST << std::endl;
		++itb; }

	std::cout << GRY1 << "COPY DE NOTRE STACK DANS UNE STACK<INT>" << RST << std::endl;
	std::stack<int> s(mstack);
}

void 	list_test() {
	std::cout << LIME << " -> LIST TEST" << RST << std::endl;
	std::list<int> mlist;
	
	std::cout << ORNG << "PUSH 5" << RST << std::endl;
	mlist.push_back(5);
	std::cout << ORNG << "PUSH 17" << RST << std::endl;
	mlist.push_back(17);
	std::cout << std::endl;
	
	std::cout << CYAN << "AFFICHAGE DU DERNIER ELEMENT DE LIST" << RST << std::endl;
	std::cout << LIME << mlist.back() << RST << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "SUPPRESSION DE L'ELEMENT DE FIN DE LIST" << RST << std::endl;
	mlist.pop_back();
	std::cout << "... ... ..." << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "AFFICHAGE DE LA TAILLE DE LA LIST" << RST << std::endl;
	std::cout << LIME << mlist.size() << RST << std::endl;
	std::cout << std::endl;
	
	std::cout << ORNG << "PUSH 3" << RST << std::endl;
	mlist.push_back(3);
	std::cout << ORNG << "PUSH 5" << RST << std::endl;
	mlist.push_back(5);
	std::cout << ORNG << "PUSH 737" << RST << std::endl;
	mlist.push_back(737);
	std::cout << ORNG << "PUSH 0" << RST << std::endl;
	mlist.push_back(0);
	std::cout << std::endl;

	std::cout << PURP << "INITIALISATION ITERATOR DEBUT" << RST << std::endl;
	std::list<int>::iterator itb = mlist.begin();
	std::cout << PURP << "INITIALISATION ITERATOR FIN" << RST << std::endl;
	std::list<int>::iterator ite = mlist.end();
	std::cout << std::endl;
	
	std::cout << PURP << "++DEBUT" << RST << std::endl;
	++itb;
	std::cout << PURP << "--DEBUT" << RST << std::endl;
	--itb;
	std::cout << std::endl;

	std::cout << CYAN << "TANT QUE DEBUT N'EST PAS FIN" << RST << std::endl;
	std::cout << CYAN << "AFFICHE LA VALEUR POINTÉ PAR DEBUT" << RST << std::endl;
	while (itb != ite) {
		std::cout << LIME << *itb << RST << std::endl;
		std::cout << PURP << "DEBUT++" << RST << std::endl;
		++itb; }

	std::cout << GRY1 << "COPY DE NOTRE STACK DANS UNE LIST<INT>" << RST << std::endl;
	std::list<int> l(mlist);
}

void	iterator_test() {
	std::cout << LIME << "-> ITERATOR TEST" << RST << std::endl;
	MutantStack<int> mstack;

	for (int i = 0; i < 10; i++) {
		std::cout << ORNG << "PUSH " << i << RST << std::endl;
		mstack.push(i);
	}

	std::cout << std::endl;

	std::cout << CYAN << "AFFICHAGE DU TOP DE LA STACK" << RST << std::endl;
	std::cout << LIME << mstack.top() << RST << std::endl;
	std::cout << std::endl;

	std::cout << PURP << "INITIALISATION ITERATOR DEBUT" << RST << std::endl;
	MutantStack<int>::it itb = mstack.begin();
	std::cout << PURP << "INITIALISATION ITERATOR FIN" << RST << std::endl;
	MutantStack<int>::it ite = mstack.end();
	std::cout << std::endl;

	std::cout << CYAN << "AFFICHAGE 1/2 DES ELEMENTS DE LA STACK EN UTILISANT ITERATOR DEBUT" << RST << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			std::cout << LIME << *itb << RST << std::endl;
		itb++;
		std::cout << PURP << "DEBUT++" << RST << std::endl;
	}

	std::cout << std::endl;

	std::cout << CYAN << "AFFICHAGE 1/2 DES ELEMENTS DE LA STACK EN UTILISANT ITERATOR FIN" << RST << std::endl;
	std::cout << std::endl;
	for (int i = 10; i > 0; i--) {
		if (i % 2 != 0)
			std::cout << LIME << *ite << RST << std::endl;
		ite--;
		std::cout << PURP << "FIN--" << RST << std::endl;
	}
}

int main() {
	std::cout << std::endl;
	subject_test();
	std::cout << std::endl;
	list_test();
	std::cout << std::endl;
	iterator_test();
	std::cout << std::endl;
	return (0);
}
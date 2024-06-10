/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:34:25 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/04 19:54:41 by cedmulle         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

#define MAX_VAL 10

/* -------------------------------------------------------------------------- */
	//MAIN DU SUJET
/* -------------------------------------------------------------------------- */
void	mainSubject(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int> tmp = numbers;
	Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cout << "didn't save the same value!!" << std::endl;
			return ;
		}
	}

	try {
		numbers[-2] = 0;
	} catch(const std::exception& e) {
		std::cout << REDD << e.what() << RST << '\n';
	}

	try {
		numbers[MAX_VAL] = 0;
	} catch(const std::exception& e) {
		std::cout << REDD << e.what() << RST << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	delete [] mirror;//
}


/* -------------------------------------------------------------------------- */
	// MAIN CUSTOM
/* -------------------------------------------------------------------------- */
int main(void)
{
	std::cout << CLRALL;
	std::cout << BLUE "// MAINSUBJECT /////////////////////////" << std::endl;

	std::cout << GRY1 "Doit seulement retourner 2 exceptions:";
	std::cout << "tente d'acceder a index -1 et index MAX_VAL" RST << std::endl;
	mainSubject();
	std::cout << std::endl;

	std::cout << BLUE "// CUSTOM MAIN /////////////////////////" RST << std::endl;

	std::cout << GRY1 "Création d'un Array vide de type int" RST << std::endl;
    Array<int> arrayVide;
    std::cout << PURP "Taille de l'Array vide: " << arrayVide.size() << RST << std::endl;

    std::cout << GRY1 "\nCréation d'un Array avec MAX_VAL éléments initialisés par défaut" RST << std::endl;
    Array<int> arrayMax(MAX_VAL);
    std::cout << PURP "Taille de l'Array initialisé avec MAX_VAL : " << arrayMax.size() << RST << std::endl;

    std::cout << GRY1 "\nRemplissage de l'ArrayMax (valeurs random)" RST << std::endl;
	std::cout << CYAN << "ArrayMax :" << RST << " | ";
    for (int i = 0; i < MAX_VAL; ++i)
	{
        arrayMax[i] = i * 19;
        std::cout << GOLD << arrayMax[i] << RST << " | ";
    }
    std::cout << RST << std::endl;

    std::cout << GRY1 "\nTest du constructeur de copie" RST << std::endl;
    Array<int> copieArray(arrayMax);
	bool	erreurCopie = false;
	std::cout << CYAN << "copieArray :" << RST << " | ";
	for (int i = 0; i < MAX_VAL; i++) {
		if (copieArray[i] == i * 19)
			std::cout << "pos. " << i << " -> " << GOLD << copieArray[i] << RST << " | ";
		else {
			std::cout << " Matrix error." << std::endl;
			erreurCopie = true;
		}
	}
	std::cout << std::endl;

    std::cout << (erreurCopie ? REDD "Erreur dans la copie des valeurs" : LIME "Copie réussie") << RST << std::endl;

    std::cout << GRY1 "\nSurcharge de l'opérateur =" RST << std::endl;
	std::cout << CYAN << "assignArray :" << RST << " | ";
    Array<int> assignArray = arrayMax;
    bool erreurAssign = false;
	for (int i = 0; i < MAX_VAL; i++) {
		if (assignArray[i] == i * 19)
			std::cout << "pos. " << i << " -> " << GOLD << assignArray[i] << RST << " | ";
		else {
			std::cout << " Matrix error." << std::endl;
			erreurAssign = true;
		}
	}
	std::cout << RST << std::endl;

    std::cout << (erreurAssign ? REDD "Erreur dans l'assignation des valeurs" : LIME "Assignation réussie") << RST << std::endl;

    std::cout << GRY1 "\nTest d'accès hors limites avec gestion des exceptions" RST << std::endl;
    try
	{
		std::cout << "Tentative de LECTURE de " << CYAN << "assignArray" RST << " à la position -> MAX_VAL(10)" << std::endl;
		std::cout << std::endl;
        std::cout << assignArray[MAX_VAL] << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << REDD << e.what() << RST << std::endl;
    }

    std::cout << GRY1 "\nTest avec des types complexes (std::string)" RST << std::endl;
	std::cout << "Nous remplissons un arrayString de trois chaîne de caractères différentes :" << std::endl;
	std::cout << std::endl;
	std::cout << ". . . -> L'amour brille" << std::endl;
	std::cout << ". . . -> Sous les étoiles" << std::endl;
	std::cout << ". . . -> Hakuna Matata" << std::endl;
	std::cout << std::endl;
    Array<std::string> arrayString(3);
    arrayString[0] = "L'amour brille";
    arrayString[1] = "Sous les étoiles";
    arrayString[2] = "Hakuna Matata";
	std::cout << std::endl;
	std::cout << "Remplissage effectué. Nous allons maintenat print le tableau pour vérifier." << std::endl;
    for (unsigned int i = 0; i < arrayString.size(); i++)
        std::cout << "pos. " << i << " -> " << ORNG << arrayString[i] << RST << " | ";
    std::cout << std::endl << std::endl;

    return (0);
}

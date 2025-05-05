/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:38:46 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 19:50:21 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"

# define NB_ANIMALS 10

# define GRY1 "\033[0;38;2;128;128;128m"
# define RST "\033[0m"
# define YLLW "\033[0;38;2;255;255;0m"
# define CLRALL "\033[2J\033[3J\033[H"

inline void	printNl(int nb)
{
	for (int i = 0; i < nb; i++)
		std::cout << std::endl;
}

inline void	printMess(const std::string message)
{
	std::cout << GRY1 "/// " << message << " ///" RST << std::endl;
}

void	arrayTest(void)
{
	Animal *tab[NB_ANIMALS + 1];
	tab[NB_ANIMALS] = NULL;

	printMess("Creating cats");
	for (int i = 0; i < (NB_ANIMALS / 2); i++)
		tab[i] = new Cat();
	printNl(1);

	printMess("Creating dogs");
	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
		tab[i] = new Dog();
	printNl(1);

	printMess("All of them making sounds");
	for (int i = 0; i < NB_ANIMALS; i++)
		tab[i]->makeSound();
	printNl(1);

	printMess("Deleting all of them");
	for (int i = 0; i < NB_ANIMALS; i++)
		delete tab[i];
}

inline void	testCopyDog(void)
{
	printMess("Creating Dog 1");
	Dog *d1 = new Dog();
	printNl(1);

	printMess("Setting idea LETS EAT and LETS PLAY");
	d1->getBrain()->setIdea(YLLW "LETS EAT" RST);
	d1->getBrain()->setIdea(YLLW "LETS PLAY" RST);

	printMess("Print idea of Dog 1");
    d1->getBrain()->getIdea(3);
	printNl(1);

	printMess("Creating a copy of Dog 1 in a Dog 2");
	Dog *d2 = new Dog(*d1);
	printNl(1);

	printMess("Kill Dog 1");
	delete d1;
	printNl(1);

	printMess("Print idea of Dog 2");
    d2->getBrain()->getIdea(4);
	printNl(1);

	printMess("Kill Dog 2");
	delete d2;
	printNl(1);
}

inline void	testCopyCat(void)
{
	printMess("Creating Cat 1");
	Cat *d1 = new Cat();
	printNl(1);

	printMess("Setting idea LETS EAT and LETS PLAY");
	d1->getBrain()->setIdea(YLLW "LETS EAT" RST);
	d1->getBrain()->setIdea(YLLW "LETS PLAY" RST);

	printMess("Print idea of Cat 1");
    d1->getBrain()->getIdea(3);
	printNl(1);

	printMess("Creating a copy of Cat 1 in a Cat 2");
	Cat *d2 = new Cat(*d1);
	printNl(1);

	printMess("Kill Cat 1");
	delete d1;
	printNl(1);

	printMess("Print idea of Cat 2");
    d2->getBrain()->getIdea(4);
	printNl(1);

	printMess("Kill Cat 2");
	delete d2;
	printNl(1);
}

void    subject_test()
{
    printMess("Test Subject");
    Animal  *i = new Cat();
    Animal  *j = new Dog();
    printNl(1);

    delete i;
    delete j;
    printNl(1);
}

int main ()
{
    subject_test();
    arrayTest();
    printNl(1);
    testCopyDog();
    printNl(1);
    testCopyCat();
    printNl(1);
    return (0);
}
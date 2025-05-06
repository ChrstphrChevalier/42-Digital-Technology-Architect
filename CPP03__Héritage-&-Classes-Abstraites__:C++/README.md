# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/2341ee6a-dc02-4ce0-b3ce-c7dae81eade6) </p>

## <p align="center"> CPP03 - Héritage simple et gestion d’objets </p>

### Aperçu

Le module **CPP03** introduit l’**héritage simple en C++**. On part de la classe `ClapTrap` qui représente un robot de combat, puis on crée des classes dérivées comme `ScavTrap` et `FragTrap`. Ce module renforce la compréhension des **constructeurs/destructeurs**, des **fonctions membres héritées ou redéfinies**, et de l’usage du **mot-clé `protected`**.

##

### Compétences acquises

- **Héritage simple (`class B : public A`)**
- **Appel explicite au constructeur de la classe mère**
- **Redéfinition de méthodes**
- **Utilisation de `protected` pour le partage intra-hiérarchie**
- **Construction et destruction correcte d’objets hérités**
- **Surcharge de fonctions dans une hiérarchie**
- **Gestion des membres spécifiques dans les sous-classes**

##

### Exercices principaux

- **ClapTrap** :
  - Classe de base avec `name`, `hitPoints`, `energyPoints`, `attackDamage`
  - Méthodes : `attack`, `takeDamage`, `beRepaired`

- **ScavTrap** :
  - Hérite de ClapTrap
  - Ajoute `guardGate()` et modifie les valeurs de départ
  - Redéfinit `attack` (sortie spécifique)

- **FragTrap** :
  - Hérite aussi de ClapTrap
  - Ajoute `highFivesGuys()` et redéfinit également `attack`

##

### Pourquoi ce module est pertinent

**CPP03** introduit les fondements de **l’héritage en P.O.O.**, une brique majeure de la conception orientée objet. Il oblige à réfléchir à la **hiérarchie des classes**, à la **réutilisation de code** et à la **bonne gestion des constructeurs/destructeurs**. Ce module prépare aux modules suivants où l’héritage multiple et la polymorphie seront abordés.


##

# <p align="center"> - Result - </p>

# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/e53672db-33b9-4722-a1b9-513bc8ce2b15) </p>

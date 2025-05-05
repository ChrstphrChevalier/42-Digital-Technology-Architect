# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/afce24bc-523f-42fe-bc77-b3bd520d04ba) </p>

## <p align="center"> CPP01 - Références, Allocation Dynamique et Pointeurs </p>

### Aperçu

Le module **CPP01** approfondit la manipulation des **références**, **pointeurs** et de l’**allocation dynamique** en C++. Il introduit les premières vraies interactions mémoire avec `new`/`delete`, les constructeurs, et la gestion manuelle de ressources. Les exercices mettent l'accent sur les objets créés sur la **pile** vs le **tas**, ainsi que les notions de **portée**, **référence**, **alias**, et **copie**.

##

### Compétences acquises

- **Références vs Pointeurs** : distinction claire entre `&` (référence) et `*` (pointeur)
- **Création dynamique** avec `new` / `delete`
- **Constructeurs et destructeurs** personnalisés
- **Portée et cycle de vie** des objets (pile vs heap)
- **Affichage des adresses et des contenus mémoire**
- **Tableaux dynamiques d’objets**
- **Manipulation de `std::string` en tant qu’attribut de classe**

##

### Exercices principaux

- **Zombie** :
  - Création d’un zombie sur la **pile**
  - Création d’un zombie sur le **tas** avec `new` et suppression avec `delete`
  - Affichage de messages dans les constructeurs/destructeurs

- **ZombieHorde** :
  - Création dynamique d’un tableau d’objets zombies
  - Allocation via `new[]` et libération via `delete[]`

- **Brain (ex02)** :
  - Manipulation de `std::string`, affichage d’adresses mémoire
  - Différences entre la variable, son pointeur, et sa référence

- **Human/Weapon** :
  - Introduction à la **composition d’objets** (un `HumanA/B` possède une `Weapon`)
  - Passage par référence vs par pointeur
  - Changement dynamique d’état via référence/pointeur

- **HarlFilter** :
  - Création d’une classe `Harl` avec 4 niveaux de log (DEBUG, INFO, WARNING, ERROR)
  - Utilisation de **fonctions membres appelées dynamiquement** selon une entrée utilisateur

##

### Pourquoi ce module est pertinent

**CPP01** renforce la compréhension des **comportements mémoire bas niveau** du C++ : allocation dynamique, références, destruction. Il jette les bases pour une gestion propre de ressources, prépare aux patterns RAII, et apprend à structurer des **classes robustes** avec des comportements cohérents.

##

# <p align="center"> - Result - </p>

# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/0a17649f-72b4-48f7-b019-f3c64a93d5c0) </p>

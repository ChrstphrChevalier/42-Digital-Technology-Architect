# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/5c9cde0e-0035-4a75-b852-b3cd4a1fb9f0) </p>

## <p align="center"> CPP05 - Exceptions et surcharge d’opérateurs </p>

### Aperçu

Le module **CPP05** introduit la **gestion d’exceptions en C++** et approfondit la **surcharge d’opérateurs**, en particulier l'opérateur d’affectation et de flux. Le tout est mis en œuvre dans le cadre d’une hiérarchie de classes simulant des formulaires administratifs.

##

### Compétences acquises

- **Gestion des exceptions (`try/catch`, `throw`, `std::exception`)**
- **Surcharge d'opérateurs (`<<`, `=`, etc.)**
- **Hiérarchie de classes avec comportements spécifiques**
- **Encapsulation stricte avec des règles d'accès**
- **Détection et traitement d'erreurs via exceptions personnalisées**

##

### Exercices principaux

- **Bureaucrat** :
  - Possède un nom (const) et un grade (entre 1 et 150)
  - Peut être promu/démis (`incrementGrade()` / `decrementGrade()`)
  - Lance des exceptions si les grades sortent des bornes

- **Form** :
  - Nécessite un grade minimal pour être signé
  - Doit être signée par un `Bureaucrat` avec un grade suffisant
  - Surcharge de l’opérateur `<<` pour affichage

- **Gestion des erreurs** :
  - `GradeTooHighException`
  - `GradeTooLowException`
  - Implémentées via `what()` héritée de `std::exception`

##

### Pourquoi ce module est pertinent

**CPP05** vous prépare à écrire du **code résilient**, capable de gérer les **erreurs d'exécution proprement** sans planter. Il renforce la **maîtrise des classes, de l'encapsulation**, et introduit une **logique métier avec règles métier vérifiées dynamiquement**, un fondement clé en développement logiciel professionnel.

##

# <p align="center"> - Result - </p>

# <p align="center"> ![image](https://github.com/user-attachments/assets/9ebc40ee-77e1-4ec7-86e9-ee1b5ac28526) </p>

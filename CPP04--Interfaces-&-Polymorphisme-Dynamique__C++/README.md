# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/a772c304-b7fa-45e5-a0c2-6e8b8c43081c) </p>

## <p align="center"> CPP04 - Héritage, classes abstraites & deep copies </p>

### Aperçu

Le module **CPP04** approfondit la **programmation orientée objet** avec les notions de **classe abstraite**, de **polymorphisme**, de **méthodes virtuelles** et de **deep copy**. Il introduit l'idée d'une interface (`AAnimal`) et impose une bonne gestion de la mémoire avec des classes comme `Brain`.

##

### Compétences acquises

- **Classe abstraite (`AAnimal`) et méthodes virtuelles pures**
- **Héritage et polymorphisme dynamique**
- **Constructeurs/destructeurs virtuels**
- **Instanciation d’objets via des pointeurs vers la classe de base**
- **Deep copy (constructeur de copie et opérateur d’affectation personnalisés)**
- **Gestion de ressources dynamiques (`Brain` dans `Dog` et `Cat`)**

##

### Exercices principaux

- **AAnimal** (classe abstraite) :
  - Méthode virtuelle pure `makeSound()`
  - Interdiction d’instancier directement

- **Dog** et **Cat** :
  - Héritent de `AAnimal`
  - Contiennent un objet `Brain`
  - Implémentent `makeSound()`

- **Brain** :
  - Contient un tableau de 100 idées
  - Implémente **deep copy** via constructeur de copie + opérateur d’affectation

##

### Pourquoi ce module est pertinent

**CPP04** forme à la **conception de classes robustes et extensibles**, tout en enseignant la **gestion correcte de la mémoire**. Il met l'accent sur le **polymorphisme**, la **réutilisation du code via des classes abstraites**, et la **gestion des objets dynamiques**. C’est un pas essentiel vers une architecture orientée objet propre et maintenable.

##

# <p align="center"> - Result - </p>

# <p align="center"> ![image](https://github.com/ChrstphrChevalier/42Cursus/assets/146819291/15dcab09-e7ae-4576-af31-4b94ded0bed1) </p>

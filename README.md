
# LabyrinthSolver

Ce projet implémente un générateur et un résolveur de labyrinthes en C. L’objectif est de générer un labyrinthe parfait et de le résoudre.

## Table des matières

1. [Introduction](#introduction)
2. [Génération du labyrinthe](#génération-du-labyrinthe)
   - [Les algorithmes de génération](#les-algorithmes-de-génération)
   - [Choix de l'algorithme de génération](#choix-de-lalgorithme-de-génération)
3. [Résolution du labyrinthe](#résolution-du-labyrinthe)
   - [Les algorithmes de résolution](#les-algorithmes-de-résolution)

---

## Introduction

J’ai choisi ce sujet car je trouvais les algorithmes intéressants et je n’avais pas encore fait ce genre d’exercice. De plus, il était facile d’ajouter des fonctionnalités et des améliorations au projet.  
Pour me lancer, j'ai décomposé le projet en trois parties :
* Génération
* Résolution
* Rendu graphique

---

## Génération du labyrinthe

### Les algorithmes de génération

Après avoir effectué quelques recherches, j'ai trouvé plusieurs solutions populaires pour générer des labyrinthes parfaits. Voici les deux algorithmes les plus connus :

1. **L'algorithme de Kruskal** :
   - L'algorithme de Kruskal est basé sur la création d'une grille de cellules vides et de murs (arêtes).
   - On commence par attribuer une valeur aléatoire à chaque cellule.
   - Ensuite, on choisit aléatoirement une cellule et si sa voisine a une valeur différente, on casse le mur entre elles pour les relier.
   - Ce processus continue jusqu’à ce qu’il n'y ait plus de murs, garantissant que le labyrinthe est parfait et sans cycles.

2. **L'algorithme de backtracking (DFS)** :
   - L'algorithme de backtracking, ou recherche en profondeur (DFS), est un algorithme récursif (ou utilisant une pile) qui explore le labyrinthe.
   - Il commence par une cellule de départ et explore récursivement les cellules voisines non explorées, en cassant les murs entre les cellules visitées.
   - Lorsque toutes les cellules voisines ont été explorées, l'algorithme revient en arrière (backtrack) jusqu'à trouver une cellule qui peut encore être explorée.
   - **Avantages** : Facile à implémenter, mais peut ne pas être aussi efficace que d'autres méthodes pour des labyrinthes de grande taille.

---

### Choix de l'algorithme de génération

Après avoir étudié ces deux algorithmes, j'ai décidé de commencer par **l'algorithme de backtracking (DFS)** pour plusieurs raisons :
- **Simplicité d'implémentation** : L'algorithme de backtracking est relativement simple à comprendre et à implémenter, surtout pour une première approche.
- **Compréhension des bases** : Cet algorithme permet de se concentrer sur la gestion de la grille, des murs, et de l'exploration des cellules, tout en apprenant les bases de la récursion et de la gestion de la pile.

Si le temps le permet et que la génération fonctionne correctement, je tenterai d'implémenter l'algorithme de **Kruskal** pour comparer les performances et les résultats des deux méthodes.

---

## Résolution du labyrinthe

### Les algorithmes de résolution

Comme pour la génération des labyrinthes, il existe plusieurs algorithmes de résolution. Étant donné que j'ai déjà implémenté la génération avec backtracking, il m’a semblé naturel d’adapter cet algorithme pour résoudre le labyrinthe.

La différence réside dans le fait que je m'arrête dès que je trouve la sortie. De plus, je dois marquer les cellules qui feront partie du chemin de la solution finale.  
J’ai rencontré des difficultés lorsque j’ai voulu réutiliser des fonctions communes aux algorithmes de génération et de résolution, car elles ne sont pas exactement identiques.  
J'avais alors le choix entre dupliquer les fonctions et ajuster les conditions, ou créer une fonction complexe qui pourrait gérer les deux types de paramètres (générateur, résolveur).  
J'ai finalement opté pour l'option de **dupliquer les fonctions** afin de réduire la complexité du code.

--- 

### Résumé

Le projet implémente deux fonctionnalités principales :
1. **Génération du labyrinthe** avec l'algorithme de backtracking.
2. **Résolution du labyrinthe** en utilisant une variante de backtracking.


---

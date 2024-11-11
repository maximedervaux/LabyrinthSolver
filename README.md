# LabyrinthSolver

Ce projet implémente un générateur et un résolveur de labyrinthes en C. L’objectif est de générer un labyrinthe parfait et de le résoudre. Dans cette première étape, nous nous concentrons sur la génération du labyrinthe.

## Table des matières

1. [Introduction](#introduction)
2. [Génération du labyrinthe](#génération-du-labyrinthe)
    - [Les algorithmes de génération](#les-algorithmes-de-génération)
    - [Choix de l'algorithme de génération](#choix-de-lalgorithme-de-génération)

---

## Introduction

J’ai choisi ce sujet car je trouvais les algorithmes intéressants et je n’avais pas fait ce genre d’exercice jusqu’à présent. De plus, il était facile d’ajouter des fonctionnalités et des améliorations au projet.
Pour me lancer J'ai decomposer le projet en 3 parties :
* Generation
* Resolution
* Rendu graphique

---

## Génération du labyrinthe

### Les algorithmes de génération

Apres avoir chercher un peu sur internet les differentes solutions existent voici ce que j'en conclu . Il existe plusieurs algorithmes populaires pour générer des labyrinthes parfaits. Les deux plus connus sont :

1. **L'algorithme de Kruskal** :
    - L'algorithme de Kruskal est basé sur la création d'une grilles de cellules vides et  d'arêtes (murs) .
    - On commence par ajouter une valeurs aleatoire aux cellules.
    - Ensuite, aléatoirement on prend une cellule et si sa voisine a une valeur differente on casse le mur pour le vusionner .
    - Le processus continue jusqu'à ce qu'il n'y ait plus de murs, garantissant que le labyrinthe est parfait et sans cycles.

2. **L'algorithme de backtracking (DFS)** :
    - L'algorithme de backtracking (ou recherche en profondeur, DFS) est un algorithme récursif ou utilisant une pile pour explorer le labyrinthe.
    - Il commence par une cellule de départ et explore récursivement des cellules voisines non explorées, en cassant les murs entre les cellules visitées.
    - Lorsque toutes les cellules voisines ont été explorées, l'algorithme revient en arrière (backtrack) jusqu'à trouver une cellule qui peut encore être explorée.
    - **Avantages** : Facile à implémenter, mais peut ne pas être aussi efficace que d'autres méthodes pour des labyrinthes de grande taille.

---

### Choix de l'algorithme de génération

Après avoir étudié ces deux algorithmes, j'ai décidé de commencer par **l'algorithme de backtracking (DFS)** pour plusieurs raisons :
- **Simplicité d'implémentation** : L'algorithme de backtracking est relativement simple à comprendre et à implémenter, surtout pour une première approche.
- **Compréhension des bases** : Il permet de se concentrer sur la gestion de la grille, des murs, et de l'exploration des cellules, tout en apprenant les bases de la récursion et de la gestion de la pile.

Si le temps le permet et que la génération fonctionne correctement, je tenterai d'implémenter l'algorithme de **Kruskal** pour comparer les performances et les résultats des deux méthodes.

---
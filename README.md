# Pokémon Jeu

## Description

Ce projet consiste à créer un jeu qui permet d'apprendre les principes de base du C++ et de la programmation orientée objet. Le projet est basé sur le jeu Pokémon. Dans ce jeu, deux joueurs commencent par explorer des Pokémon et les ajouter à la Pokéball de chaque joueur. Ensuite, le premier joueur décide de lancer le combat (qui se fait contre le joueur numéro 2 représenté par l'ordinateur) ou de continuer l'exploration des Pokémon. 

Après 3 combats, le résultat final de la partie est affiché ainsi que le détail de chaque combat.

## Règles du Jeu

- Chaque joueur sélectionne 6 Pokémon.
- Par défaut, le premier joueur commence le combat.
- Lors de chaque combat, les Pokémon de même indice se battent contre ceux de l'indice équivalent jusqu'à ce que l'un des deux atteigne 0 points de vie (Hit Points).
- Le joueur dont le Pokémon reste en vie gagne un point.
- On continue le processus jusqu'à la fin du combat.
- À la fin du combat, un point est attribué au joueur gagnant.
- Ensuite, le joueur peut choisir de lancer un nouveau combat ou de retourner à l'exploration.

Après la fin des 3 combats, les résultats sont affichés avec le nombre de points de chaque joueur.

## Note Importante

Lorsque deux Pokémon s'affrontent et que chacun d'eux a des points d'attaque inférieurs aux points de défense de son adversaire, le combat est ignoré (skip).

## Déroulement du Jeu

Voici un diagramme représentant le déroulement du jeu :

![Diagramme de Déroulement du Jeu]([path/to/game_flow_diagram.png](https://github.com/abderrazekbhr/TP-CPP-ENSEA3/blob/main/documentation/flowChart.png))

Ce diagramme montre les différentes étapes de l'exploration, de la sélection des Pokémon, du lancement des combats et de l'affichage des résultats.

## Architecture du Projet

Le projet suit une architecture orientée objet en C++. Voici un diagramme de classes représentant l'architecture du projet :

![Diagramme de Classes](path/to/class_diagram.png)

Ce diagramme décrit les différentes classes, leurs attributs, méthodes et relations, et comment elles interagissent pour créer le jeu.

## Commandes d'Exécution

Pour exécuter le projet, suivez ces étapes :

1. **Compiler le projet** :
   - Assurez-vous d'avoir un compilateur C++ installé (comme `g++`).
   - Utilisez la commande suivante pour compiler le projet :
     ```bash
     g++ -o pokemon_game main.cpp other_files.cpp
     ```

2. **Exécuter le projet** :
   - Après la compilation, exécutez le jeu avec la commande suivante :
     ```bash
     ./pokemon_game
     ```

## Épreuve de l'Exécution

Voici un exemple de sortie d'exécution du programme :


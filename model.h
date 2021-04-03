/**
 * model.h
 * 
 * Ce fichier contient les prototypes des fonctions liées aux mécanismes du jeu
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

/**
 * \file model.h
 * \brief Librairie contenant les prototypes des fonctions liées aux mécanismes du jeu
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 30/03/2021
*/

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __MODEL__
#define __MODEL__

#include <stdbool.h>

#include <gtk/gtk.h>

typedef struct model_t{
   bool turn;//tour du joueur
   bool gameState;//état du jeu, 1:in game, 0:game is finished
   int winner; //-2: still playing, 1: first player, 0: tie, -1; second player
   char board[16];
}Model;

Model *create_model(bool turn, bool gameState, int winner);

bool check_game_status(const int winningDirection[8][3], int winningBlock[3], Model *m);

int who_wins(Model *m, int *winningBlocks);

bool is_board_full(Model *m);

bool is_combination_possible(Model *m);

#endif // __model__
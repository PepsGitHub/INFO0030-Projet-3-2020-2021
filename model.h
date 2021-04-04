/**
 * model.h
 * 
 * Ce fichier contient les prototypes des fonctions liées aux mécanismes du jeu
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 04/04/21
 * @projet: INFO0030 Projet 3
 */

/**
 * \file model.h
 * \brief Librairie contenant les prototypes des fonctions liées aux mécanismes du jeu
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 04/04/2021
*/

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __MODEL__
#define __MODEL__

#include <assert.h>
#include <stdbool.h>

#include <gtk/gtk.h>

typedef struct model_t{
   bool turn;//tour du joueur: false: premier joueur 'o', true: deuxième joueur 'x'
   bool gameState;//état du jeu: true: partie en cours, false: partie terminée
   int winner; //gagnant: -2: on ne sait pas encore, -1: premier joueur, 0: égalité, 1; deuxième joueur
   char board[16];//état du plateau de jeu, 0: pas encore cliqué, 'o' ou 'x': cliqué
}Model;

/**
 * \fn Model *create_model(bool turn, bool gameState, int winner)
 * \brief Crée le modèle
 * 
 * \param turn tour du joueur: false: premier joueur 'o', true: deuxième joueur 'x'
 * \param gameState état du jeu: true: partie en cours, false: partie terminée
 * \param winner gagnant: -2: on ne sait pas encore, -1: premier joueur, 0: égalité, 1; deuxième joueur
 * 
 * \pre \
 * \post le modèle est correctement créé
 * 
 * \return m Succès
 */
Model *create_model(bool turn, bool gameState, int winner);

/**
 * \fn bool check_game_status(const int direction[8][3], int *winningBlock, Model *m)
 * \brief Check si la partie est toujours en cours et si ce n'est pas le cas, donne aussi la combinaison gagnante
 * 
 * \param direction la direction des combinaisons gagnantes
 * \param winningBlock la combinaison gagnante
 * \param m le modèle
 * 
 * \pre m != NULL
 * \post le statut est correctement vérifié
 * 
 * \return true Partie finie
 * \return false Partie toujours en cours
 */
bool check_game_status(const int direction[24][3], int *winningBlock, Model *m);

/**
 * \fn int who_wins(Model *m, int *winningBlocks)
 * \brief Check qui gagne
 * 
 * \param m le modèle
 * \param winningBlock la combinaison gagnante
 * 
 * \pre m != NULL
 * \post on connaît l'issue de la partie
 * 
 * \return -1 Le premier joueur a gagné
 * \return 0 Egalité
 * \return 1 Le deuxième joueur a gagné
 */
int who_wins(Model *m, int *winningBlocks);

/**
 * \fn bool is_board_full(Model *m)
 * \brief //Check si le plateau est remplit ou pas
 * 
 * \param m le modèle
 * 
 * \pre m != NULL
 * \post on sait si le plateau est rempli ou non
 * 
 * \return true Le plateau est rempli
 * \return false Le plateau n'est pas rempli
 */
bool is_board_full(Model *m);

#endif // __model__
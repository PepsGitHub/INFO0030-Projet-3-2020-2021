/**
 * model.h
 * 
 * Ce fichier contient les prototypes des fonctions liées aux mécanismes du jeu
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 08/04/21
 * @projet: INFO0030 Projet 3
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

/**
 * \file model.h
 * \brief Librairie contenant les prototypes des fonctions liées aux mécanismes du jeu
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 08/04/2021
 * 
 * Déclaration du type opaque Model
 *
 */
typedef struct model_t Model;

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
 * \fn bool get_turn(Model *m)
 * \brief Accesseur en lecture pour le champ turn
 * 
 * \param m le modèle
 * 
 * \pre m != NULL
 * \post le champ est lu
 * 
 * \return m->turn Succès
 */
bool get_turn(Model *m);

/**
 * \fn bool get_gameState(Model *m)
 * \brief Accesseur en lecture pour le champ gameState
 * 
 * \param m le modèle
 * 
 * \pre m != NULL
 * \post le champ est lu
 * 
 * \return m->gameState Succès
 */
bool get_gameState(Model *m);

/**
 * \fn int get_winner(Model *m)
 * \brief Accesseur en lecture pour le champ winner
 * 
 * \param m le modèle
 * 
 * \pre m != NULL
 * \post le champ est lu
 * 
 * \return m->winner Succès
 */
int get_winner(Model *m);

/**
 * \fn char *get_board(Model *m)
 * \brief Accesseur en lecture pour le champ board
 * 
 * \param m le modèle
 * 
 * \pre m != NULL
 * \post le champ est lu
 * 
 * \return m->board Succès
 */
char *get_board(Model *m);

/**
 * \fn Model *set_turn(Model *m, bool turn)
 * \brief Accesseur en écriture pour le champ turn
 * 
 * \param m le modèle
 * \param turn le tour du joueur courant
 * 
 * \pre m != NULL
 * \post le champ est modifié
 * 
 * \return m Succès
 */
Model *set_turn(Model *m, bool turn);

/**
 * \fn Model *set_gameState(Model *m, bool gameState)
 * \brief Accesseur en écriture pour le champ gameState
 * 
 * \param m le modèle
 * \param gameState l'état du jeu
 * 
 * \pre m != NULL
 * \post le champ est modifié
 * 
 * \return m Succès
 */
Model *set_gameState(Model *m, bool gameState);

/**
 * \fn Model *set_winner(Model *m, int winner)
 * \brief Accesseur en écriture pour le champ winner
 * 
 * \param m le modèle
 * \param winner le gagnant
 * 
 * \pre m != NULL
 * \post le champ est modifié
 * 
 * \return m Succès
 */
Model *set_winner(Model *m, int winner);

/**
 * \fn Model *set_board(Model *m, char board[16])
 * \brief Accesseur en écriture pour le champ winner
 * 
 * \param m le modèle
 * \param board le plateau de jeu
 * 
 * \pre m != NULL, board != NULL
 * \post le champ est modifié
 * 
 * \return m Succès
 */
Model *set_board(Model *m, char board[16]);

/**
 * \fn bool check_game_status(const int direction[24][3], int *winningBlock, Model *m)
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
 * \brief Check si le plateau est remplit ou pas
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
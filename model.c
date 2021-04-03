/**
 * model.c
 * 
 * Ce fichier contient les fonctions liées aux mécanismes du jeu
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 03/04/21
 * @projet: INFO0030 Projet 3
 */

#include <stdbool.h>
#include <assert.h>

#include "model.h"

//Création du modèle
Model *create_model(bool turn, bool gameState, int winner){
   Model *m = malloc(sizeof(Model));
   if(m == NULL)
      return NULL;

   m->turn = turn;
   m->gameState = gameState;
   m->winner = winner;
   
   for(int i = 0; i < 16; i++)
      m->board[i] = 0;

   return m;
}

//Combinaisons gagnantes
const int horizontal[8][3] = {{0, 1, 2}, {1, 2, 3}, {4, 5, 6}, {5, 6, 7}, {8, 9, 10}, {9, 10, 11}, {12, 13, 14}, {13, 14, 15}};

const int vertical[8][3] = {{0, 4, 8}, {4, 8, 12}, {1, 5, 9}, {5, 9, 13}, {2, 6, 10}, {6, 10, 14}, {3, 7, 11}, {7, 11, 15}};

const int diagonal[8][3] = {{4, 9, 14}, {0, 5, 10}, {5, 10, 15}, {1, 6, 11}, {2, 5, 8}, {3, 6, 9}, {6, 9, 12}, {7, 10, 13}};

//Check si la partie est toujours en cours et si ce n'est pas le cas, donne aussi la combinaison gagnante
bool check_game_status(const int direction[8][3], int *winningBlock, Model *m){
   assert(m != NULL);

   for(int i = 0; i < 8; i++){
      int count = 0;
      if(m->board[direction[i][0]] == 'o')
         count++;
      
      if(m->board[direction[i][1]] == 'x')
         count++;
      
      if(m->board[direction[i][2]] == 'o')
         count++;

      if(count == 3){
         winningBlock[0] = direction[i][0];
         winningBlock[1] = direction[i][1];
         winningBlock[2] = direction[i][2];
         return true;//partie terminée
      }
   }
   return false;//partie toujours en cours
}

//Check qui gagne
int who_wins(Model *m, int *winningBlocks){
   assert(m != NULL);

   bool win = false;

   win = check_game_status(horizontal, winningBlocks, m);
   if(win && m->turn)
      m->winner = 1;//le joueur 2 gagne
   else if(win && !m->turn)
      m->winner = -1;//le joueur 1 gagne
   
   win = check_game_status(vertical, winningBlocks, m);
   if(win && m->turn)
      m->winner = 1;//le joueur 2 gagne
   else if(win && !m->turn)
      m->winner = -1;//le joueur 1 gagne

   win = check_game_status(diagonal, winningBlocks, m);
   if(win && m->turn)
      m->winner = 1;//le joueur 2 gagne
   else if(win && !m->turn)
      m->winner = -1;//le joueur 1 gagne

   if(is_board_full(m))
      m->winner = 0;//égalité

   return m->winner;
}

//Check si le plateau est remplit ou pas
bool is_board_full(Model *m){
   assert(m != NULL);

   for(int i = 0; i < 16; i++){
      if(m->board[i] == 0)
         return false;
   }
   return true;
}
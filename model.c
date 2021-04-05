/**
 * model.c
 * 
 * Ce fichier contient les fonctions liées aux mécanismes du jeu
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 04/04/21
 * @projet: INFO0030 Projet 3
 */

#include <stdbool.h>
#include <assert.h>

#include "model.h"

/**
 * Définition du type opaque Model
 */
struct model_t{
   bool turn;//tour du joueur: false: premier joueur 'o', true: deuxième joueur 'x'
   bool gameState;//état du jeu: true: partie en cours, false: partie terminée
   int winner; //gagnant: -2: on ne sait pas encore, -1: premier joueur, 0: égalité, 1; deuxième joueur
   char board[16];//état du plateau de jeu, 0: pas encore cliqué, 'o' ou 'x': cliqué
};

//Création du modèle
Model *create_model(bool turn, bool gameState, int winner){
   Model *m = malloc(sizeof(Model));
   if(m == NULL)
      return NULL;

   char *board = malloc(sizeof(char) * 16);
   
   for(int i = 0; i < 16; i++)
      board[i] = 0;

   set_turn(m, turn);
   set_gameState(m, gameState);
   set_winner(m, winner);
   set_board(m, board);

   return m;
}

//debut accesseurs en lecture
bool get_turn(Model *m){
   assert(m != NULL);

   return m->turn;
}

bool get_gameState(Model *m){
   assert(m != NULL);

   return m->gameState;
}

int get_winner(Model *m){
   assert(m != NULL);

   return m->winner;
}

char *get_board(Model *m){
   assert(m != NULL);

   return m->board;
}//fin accesseurs en lecture

//debut accesseurs en écriture
Model *set_turn(Model *m, bool turn){
   assert(m != NULL);

   m->turn = turn;

   return m;
}

Model *set_gameState(Model *m, bool gameState){
   assert(m != NULL);

   m->gameState = gameState;

   return m;
}

Model *set_winner(Model *m, int winner){
   assert(m != NULL);

   m->winner = winner;

   return m;
}

Model *set_board(Model *m, char board[16]){
   assert(m != NULL && board != NULL);

   for(int i = 0; i < 16; i++)
      m->board[i] = board[i];

   return m;
}//fin accesseurs en écriture

//Combinaisons gagnantes
const int winningCombinations[24][3] = {{0, 1, 2}, {1, 2, 3}, {4, 5, 6}, {5, 6, 7}, {8, 9, 10}, {9, 10, 11}, {12, 13, 14}, {13, 14, 15}, {0, 4, 8}, {4, 8, 12}, {1, 5, 9}, {5, 9, 13}, {2, 6, 10}, {6, 10, 14}, {3, 7, 11}, {7, 11, 15}, {4, 9, 14}, {0, 5, 10}, {5, 10, 15}, {1, 6, 11}, {2, 5, 8}, {3, 6, 9}, {6, 9, 12}, {7, 10, 13}};

//Check si la partie est toujours en cours et si ce n'est pas le cas, donne aussi la combinaison gagnante
bool check_game_status(const int winningCombi[24][3], int *winningBlock, Model *m){
   assert(m != NULL);

   for(int i = 0; i < 24; i++){
      int count = 0;

      if(get_board(m)[winningCombi[i][0]] == 'o')
         count++;
      
      if(get_board(m)[winningCombi[i][1]] == 'x')
         count++;
      
      if(get_board(m)[winningCombi[i][2]] == 'o')
         count++;

      if(count == 3){
         winningBlock[0] = winningCombi[i][0];
         winningBlock[1] = winningCombi[i][1];
         winningBlock[2] = winningCombi[i][2];
         return true;//partie terminée
      }
   }
   return false;//partie toujours en cours
}

//Check qui gagne
int who_wins(Model *m, int *winningBlocks){
   assert(m != NULL);

   bool win = false;

   win = check_game_status(winningCombinations, winningBlocks, m);
   if(win && get_turn(m))
      set_winner(m, 1);//le joueur 2 gagne
   else if(win && !get_turn(m))
      set_winner(m, -1);//le joueur 1 gagne

   if(is_board_full(m))
      set_winner(m, 0);//égalité

   return get_winner(m);
}

//Check si le plateau est remplit ou pas
bool is_board_full(Model *m){
   assert(m != NULL);

   for(int i = 0; i < 16; i++){
      if(get_board(m)[i] == 0)
         return false;
   }
   return true;
}
/**
 * model.c
 * 
 * Ce fichier contient les fonctions liées aux mécanismes du jeu
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

#include <stdbool.h>

#include "model.h"

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

//check si la partie est finie ou si elle continue
bool check_game_status(const int winningDirection[8][3], int winningBlock[3], Model *m){
   int count = 0, j = 0;
   for(int i = 0; i < 8; i++){
      count = 0;
      if(m->board[winningDirection[i][j]] == 'o'){
         winningBlock[0] = winningDirection[i][j];
         count++;
      }
      
      if(m->board[winningDirection[i][j+1]] == 'x'){
         winningBlock[1] = winningDirection[i][j];
         count++;
      }
      
      if(m->board[winningDirection[i][j+2]] == 'o'){
         winningBlock[2] = winningDirection[i][j];
         count++;
      }

      if(count == 3){
         return true;
      }
   }
   return false;//game is still busy
}

//regarde qui gagne
int who_wins(Model *m, int *winningBlocks){
   bool win = false;

   win = check_game_status(horizontal, winningBlocks, m);
   if(win && m->turn)
      m->winner = 1;//player 2 won
   else if(win && !m->turn)
      m->winner = -1;//player 1 won
   
   win = check_game_status(vertical, winningBlocks, m);
   if(win && m->turn)
      m->winner = 1;//player 2 won
   else if(win && !m->turn)
      m->winner = -1;//player 1 won

   win = check_game_status(diagonal, winningBlocks, m);
   if(win && m->turn)
      m->winner = 1;//player 2 won
   else if(win && !m->turn)
      m->winner = -1;//player 1 won

   if(is_board_full(m))
      m->winner = 0;

   return m->winner;
}

//check si le board est remplit ou pas
bool is_board_full(Model *m){
   for(int i = 0; i < 16; i++){
      if(m->board[i] == 0)
         return false;
   }
   return true;
}

//check s'il y a eu plus de 3 tours
bool is_combination_possible(Model *m){
   int count = 0;
   for(int i = 0; i < 16; i++){
      if(m->board[i] == 'o' || m->board[i] == 'x')
         count++;
   }
   if(count >= 3)
      return true;
   else 
      return false;
}
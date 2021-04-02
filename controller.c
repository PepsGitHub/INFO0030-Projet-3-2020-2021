/**
 * controller.c
 * 
 * Ce fichier contient les fonctions liées aux actions de l'utilisateur
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

#include <assert.h>

#include "controller.h"

Controller *create_controller(Vue *v, Model *m){
   assert(v != NULL && m != NULL);

   Controller *c = malloc(sizeof(Controller));
   if(c == NULL)
      return NULL;

   c->v = v;
   c->m = m;

   for(int i = 0; i < 17; i++)
      c->pButton[i] = NULL;

   return c;
}

void click_button(GtkWidget *pButton, gpointer data, int i){
   Controller *c = (Controller *)data;

   redraw_button(c, i);

   c->m->turn = !c->m->turn;
}

//resetting the game
void click_new_game(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   for(int i = 0; i < 16; i++){
      c->m->board[i] = false;
      change_image_button(c->pButton[i], "images/default.png");
   }

   c->m->turn = false;
   c->m->winner = 2;
   c->m->gameState = true;
}

void destroy_window(GtkWidget *pWindow, gpointer data){
   gtk_main_quit();
}

void button_clicked(GtkButton *pButton, Model *m){
   assert(m != NULL && m->gameState);

   /*if(!m->board[0])
      m->turn*/
}
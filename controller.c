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

   c->pButton = NULL;
   c->pButtonNumber = 17;

   return c;
}

void click_first_player(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   redraw_button_first_player(c->v, c->pButtonNumber);
}

void click_second_player(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   redraw_button_second_player(c->pButtonNumber, c->pButtonNumber);
}

void destroy_window(GtkWidget *pWindow, gpointer data){
   gtk_main_quit();
}
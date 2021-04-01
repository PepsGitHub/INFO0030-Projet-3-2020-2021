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
   c->pButtonNumber = 0;

   return c;
}

void click_button(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   redraw_button(c);

   c->m->turn = !c->m->turn;
   c->pButtonNumber++;
}

void destroy_window(GtkWidget *pWindow, gpointer data){
   gtk_main_quit();
}
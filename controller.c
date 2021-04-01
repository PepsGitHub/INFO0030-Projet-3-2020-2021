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

void click_button_0(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 0;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_1(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 1;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_2(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 2;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_3(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 3;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_4(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 4;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_5(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 5;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_6(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 6;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_7(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 7;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_8(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 8;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_9(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 9;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_10(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 10;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_11(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 11;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_12(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 12;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_13(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 13;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_14(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 14;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void click_button_15(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 15;
   redraw_button(c);

   c->m->turn = !c->m->turn;
}

void destroy_window(GtkWidget *pWindow, gpointer data){
   gtk_main_quit();
}
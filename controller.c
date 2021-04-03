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

//Rassemble les actions des boutons
void signal_connect(Controller *c){
   g_signal_connect(c->pButton[0], "clicked", G_CALLBACK(click_button_0), c);
   g_signal_connect(c->pButton[1], "clicked", G_CALLBACK(click_button_1), c);
   g_signal_connect(c->pButton[2], "clicked", G_CALLBACK(click_button_2), c);
   g_signal_connect(c->pButton[3], "clicked", G_CALLBACK(click_button_3), c);
   g_signal_connect(c->pButton[4], "clicked", G_CALLBACK(click_button_4), c);
   g_signal_connect(c->pButton[5], "clicked", G_CALLBACK(click_button_5), c);
   g_signal_connect(c->pButton[6], "clicked", G_CALLBACK(click_button_6), c);
   g_signal_connect(c->pButton[7], "clicked", G_CALLBACK(click_button_7), c);
   g_signal_connect(c->pButton[8], "clicked", G_CALLBACK(click_button_8), c);
   g_signal_connect(c->pButton[9], "clicked", G_CALLBACK(click_button_9), c);
   g_signal_connect(c->pButton[10], "clicked", G_CALLBACK(click_button_10), c);
   g_signal_connect(c->pButton[11], "clicked", G_CALLBACK(click_button_11), c);
   g_signal_connect(c->pButton[12], "clicked", G_CALLBACK(click_button_12), c);
   g_signal_connect(c->pButton[13], "clicked", G_CALLBACK(click_button_13), c);
   g_signal_connect(c->pButton[14], "clicked", G_CALLBACK(click_button_14), c);
   g_signal_connect(c->pButton[15], "clicked", G_CALLBACK(click_button_15), c);

   g_signal_connect(c->pButton[16], "clicked", G_CALLBACK(click_new_game), c);
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

//resetting the game
void click_new_game(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   c->pButtonNumber = 16;

   for(int i = 0; i < 16; i++){
      c->m->board[i] = 0;
      change_image_button(c->pButton[i], "images/default.png");
   }

   c->m->turn = false;
   c->m->winner = -2;
   c->m->gameState = true;
}

void destroy_window(GtkWidget *pWindow, gpointer data){
   gtk_main_quit();
}
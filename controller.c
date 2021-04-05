/**
 * controller.c
 * 
 * Ce fichier contient les fonctions liées aux actions de l'utilisateur
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 04/04/21
 * @projet: INFO0030 Projet 3
 */

#include <assert.h>

#include "controller.h"

/**
 * Définition du type opaque Controller
 */
struct controller_t{
   struct vue_t *v;
   Model *m;
   GtkWidget *pButton[17];
   unsigned short pButtonNumber;
};

//debut accesseurs en lecture
Vue *get_vue(Controller *c){
   assert(c != NULL);

   return c->v;
}

Model *get_model_c(Controller *c){
   assert(c != NULL);

   return c->m;
}

GtkWidget **get_buttons(Controller *c){
   assert(c != NULL);

   return c->pButton;
}

unsigned int get_pButtonNumber(Controller *c){
   assert(c != NULL);

   return c->pButtonNumber;
}//fin accesseurs en lecture

//debut accesseurs en écriture
Controller *set_vue(Controller *c, Vue *v){
   assert(c != NULL && v != NULL);

   c->v = v;

   return c;
}

Controller *set_model_c(Controller *c, Model *m){
   assert(c != NULL && m != NULL);

   c->m = m;

   return c;
}

Controller *set_buttons(Controller *c, GtkWidget **pButtons){
   assert(c != NULL && pButtons != NULL);

   for(int i = 0; i < 17; i++)
      c->pButton[i] = pButtons[i];

   return c;
}

Controller *set_buttonNumber(Controller *c, unsigned int pButtonNumber){
   assert(c != NULL);

   c->pButtonNumber = pButtonNumber;

   return c;
}//fin accesseurs en écriture

//Création du controlleur
Controller *create_controller(Vue *v, Model *m){
   assert(v != NULL && m != NULL);

   Controller *c = malloc(sizeof(Controller));
   if(c == NULL)
      return NULL;

   GtkWidget **Buttons = (GtkWidget **)malloc(17 * sizeof(GtkWidget *));

   for(int i = 0; i < 17; i++)
      Buttons[i] = NULL;
   
   set_vue(c, v);
   set_model_c(c, m);
   set_buttons(c, Buttons);
   set_buttonNumber(c, 0);

   return c;
}

//Rassemble les actions des boutons
void signal_connect(Controller *c){
   assert(c != NULL);

   g_signal_connect(get_buttons(c)[0], "clicked", G_CALLBACK(click_button_0), c);
   g_signal_connect(get_buttons(c)[1], "clicked", G_CALLBACK(click_button_1), c);
   g_signal_connect(get_buttons(c)[2], "clicked", G_CALLBACK(click_button_2), c);
   g_signal_connect(get_buttons(c)[3], "clicked", G_CALLBACK(click_button_3), c);
   g_signal_connect(get_buttons(c)[4], "clicked", G_CALLBACK(click_button_4), c);
   g_signal_connect(get_buttons(c)[5], "clicked", G_CALLBACK(click_button_5), c);
   g_signal_connect(get_buttons(c)[6], "clicked", G_CALLBACK(click_button_6), c);
   g_signal_connect(get_buttons(c)[7], "clicked", G_CALLBACK(click_button_7), c);
   g_signal_connect(get_buttons(c)[8], "clicked", G_CALLBACK(click_button_8), c);
   g_signal_connect(get_buttons(c)[9], "clicked", G_CALLBACK(click_button_9), c);
   g_signal_connect(get_buttons(c)[10], "clicked", G_CALLBACK(click_button_10), c);
   g_signal_connect(get_buttons(c)[11], "clicked", G_CALLBACK(click_button_11), c);
   g_signal_connect(get_buttons(c)[12], "clicked", G_CALLBACK(click_button_12), c);
   g_signal_connect(get_buttons(c)[13], "clicked", G_CALLBACK(click_button_13), c);
   g_signal_connect(get_buttons(c)[14], "clicked", G_CALLBACK(click_button_14), c);
   g_signal_connect(get_buttons(c)[15], "clicked", G_CALLBACK(click_button_15), c);

   g_signal_connect(get_buttons(c)[16], "clicked", G_CALLBACK(click_new_game), c);
}

//Conséquences du clic sur le bouton
void click_button_0(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 0);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_1(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 1);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_2(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 2);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_3(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 3);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_4(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 4);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_5(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 5);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_6(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 6);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_7(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 7);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_8(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 8);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_9(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 9);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_10(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 10);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_11(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 11);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_12(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 12);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_13(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 13);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_14(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 14);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

void click_button_15(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 15);
   redraw_button(c);
   if(get_gameState(get_model_c(c)))
      redraw_winning_buttons(c);

   set_turn(get_model_c(c), !get_turn(get_model_c(c)));
}

//Réinitialise le jeu
void click_new_game(GtkWidget *pButton, gpointer data){
   Controller *c = (Controller *)data;

   set_buttonNumber(c, 16);
   char *board = malloc(16 * sizeof(char));
   GtkButton **pButtons = (GtkButton **)malloc(17 * sizeof(GtkButton *));
   
   pButtons = (GtkButton **)get_buttons(c);

   for(int i = 0; i < 16; i++){
      board[i] = 0;
      change_image_button(pButtons[i], "images/default.png");
   }

   set_board(get_model_c(c), board);
   set_buttons(c, (GtkWidget **)pButtons);
   set_turn(get_model_c(c), false);
   set_winner(get_model_c(c), -2);
   set_gameState(get_model_c(c), true);

   free(board);
}

//Détruit la fenêtre
void destroy_window(GtkWidget *pWindow, gpointer data){
   gtk_main_quit();
}
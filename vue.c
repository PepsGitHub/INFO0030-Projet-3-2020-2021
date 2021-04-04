/**
 * vue.c
 * 
 * Ce fichier contient les fonctions liées à l'affichage du jeu
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 04/04/21
 * @projet: INFO0030 Projet 3
 */

#include <gtk/gtk.h>
#include <assert.h>

#include "vue.h"

//Création de la vue
Vue *create_vue(Model *m){
   assert(m != NULL);

   Vue *v = malloc(sizeof(Vue));
   if(v == NULL)
      return NULL;

   v->m = m;

   return v;
}

//Création de la fenêtre
GtkWidget *create_window(){
   GtkWidget *pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pWindow), "oxo");
   gtk_window_set_default_size(GTK_WINDOW(pWindow), 400, 400);

   g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(destroy_window), NULL);

   return pWindow;
}

//Création d'un bouton avec image
GtkButton *load_image_button(char *filename){
   assert(filename != NULL);
   
   //1. Charger l'image et la redimensionner (100*100 pixels)
   GdkPixbuf *pb_temp = gdk_pixbuf_new_from_file(filename, NULL);
   if(pb_temp == NULL){
      printf("Erreur de chargement de l'image o.png!\n");
      return NULL;
   }
   GdkPixbuf *pb = gdk_pixbuf_scale_simple(pb_temp, 100, 100, GDK_INTERP_NEAREST);

   //2. Créer le bouton
   GtkWidget *pButton = gtk_button_new();

   //3. Placer l'image
   GtkWidget *image = gtk_image_new_from_pixbuf(pb);
   gtk_button_set_image(GTK_BUTTON(pButton), image);

   return (GtkButton *)pButton;
}

//Permet de changer l'image d'un bouton déjà existant
GtkButton *change_image_button(GtkButton *pButton, char *filename){
   assert(pButton != NULL && filename != NULL);

   GdkPixbuf *pb_temp = gdk_pixbuf_new_from_file(filename, NULL);
   if(pb_temp == NULL){
      printf("Erreur de chargement de l'image o.png!\n");
      return NULL;
   }
   GdkPixbuf *pb = gdk_pixbuf_scale_simple(pb_temp, 100, 100, GDK_INTERP_NEAREST);

   GtkWidget *image = gtk_image_new_from_pixbuf(pb);
   gtk_button_set_image(GTK_BUTTON(pButton), image);

   return pButton;
}

//Création des boutons et du tableau de boutons
GtkWidget *create_and_attach_buttons(GtkWidget *pTable, GtkWidget **pButton, Controller *c){
   assert(pButton != NULL && c != NULL);

   for(int i = 0; i < 16; i++){
      pButton[i] = (GtkWidget *)load_image_button("images/default.png");
      c->pButton[i] = pButton[i];

   }

   pButton[16] = gtk_button_new_with_label("Nouvelle Partie");
   c->pButton[16] = pButton[16];

   gtk_table_attach(GTK_TABLE(pTable), pButton[0], 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[1], 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[2], 2, 3, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[3], 3, 4, 0, 1, GTK_FILL, GTK_FILL, 0, 0);

   gtk_table_attach(GTK_TABLE(pTable), pButton[4], 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[5], 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[6], 2, 3, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[7], 3, 4, 1, 2, GTK_FILL, GTK_FILL, 0, 0);

   gtk_table_attach(GTK_TABLE(pTable), pButton[8], 0, 1, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[9], 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[10], 2, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[11], 3, 4, 2, 3, GTK_FILL, GTK_FILL, 0, 0);

   gtk_table_attach(GTK_TABLE(pTable), pButton[12], 0, 1, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[13], 1, 2, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[14], 2, 3, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(pTable), pButton[15], 3, 4, 3, 4, GTK_FILL, GTK_FILL, 0, 0);

   gtk_table_attach(GTK_TABLE(pTable), pButton[16], 1, 3, 4, 5, GTK_EXPAND, GTK_EXPAND, 0, 0);

   return pTable;
}

//Redessine le bouton qui vient d'être cliqué
void redraw_button(Controller *c){
   assert(c != NULL);

   if(!c->m->turn && c->m->gameState){
      change_image_button((GtkButton *)c->pButton[c->pButtonNumber], "images/o.png");
      c->m->board[c->pButtonNumber] = 'o';
   }else if(c->m->turn && c->m->gameState){
      change_image_button((GtkButton *)c->pButton[c->pButtonNumber], "images/x.png");
      c->m->board[c->pButtonNumber] = 'x';
   }
}

void redraw_winning_buttons(Controller *c){
   int winningBlock[3] = {0, 1, 2};

   switch(who_wins(c->m, winningBlock)){
   case 0://égalité
      printf("Neither player managed to get a win\n");
      
      break;
   case -1://Le premier joueur a gagné
      change_image_button((GtkButton *)c->pButton[winningBlock[0]], "images/o_gagnant.png");
      change_image_button((GtkButton *)c->pButton[winningBlock[1]], "images/x_gagnant.png");
      change_image_button((GtkButton *)c->pButton[winningBlock[2]], "images/o_gagnant.png");

      printf("Player 1 has won the game\n");

      c->m->gameState = false;

      break;
   case 1://Le deuxième joueur a gagné
      change_image_button((GtkButton *)c->pButton[winningBlock[0]], "images/o_gagnant.png");
      change_image_button((GtkButton *)c->pButton[winningBlock[1]], "images/x_gagnant.png");
      change_image_button((GtkButton *)c->pButton[winningBlock[2]], "images/o_gagnant.png");

      printf("Player 2 has won the game\n");

      c->m->gameState = false;

      break;
   default:
      c->m->gameState = true;
   }
}
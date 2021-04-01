/**
 * vue.c
 * 
 * Ce fichier contient les fonctions liées à l'affichage du jeu
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

#include <gtk/gtk.h>
#include <assert.h>

#include "vue.h"

Vue *create_vue(Model *m){
   assert(m != NULL);

   Vue *v = malloc(sizeof(Vue));
   if(v == NULL)
      return NULL;

   v->m = m;

   return v;
}

GtkWidget *create_window(){
   GtkWidget *pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pWindow), "oxo");
   gtk_window_set_default_size(GTK_WINDOW(pWindow), 400, 400);

   g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(destroy_window), NULL);

   return pWindow;
}

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

   return pButton;
}

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

GtkWidget *create_and_attach_buttons(GtkWidget *pTable, GtkButton **pButton, Controller *c){
   assert(pButton != NULL);

   for(int i = 0; i < 16; i++){
      pButton[i] = load_image_button("images/default.png");
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

void redraw_button(Controller *c){
   assert(c != NULL && c->m->gameState);

   if(!c->m->turn && c->m->gameState)
      change_image_button(c->pButton[c->pButtonNumber], "images/o.png");
   else
      change_image_button(c->pButton[c->pButtonNumber], "images/x.png");
}
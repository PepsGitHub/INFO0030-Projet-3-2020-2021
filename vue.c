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

GtkWidget *create_window(){
   GtkWidget *pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pWindow), "oxo");
   gtk_window_set_default_size(GTK_WINDOW(pWindow), 400, 400);

   g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

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
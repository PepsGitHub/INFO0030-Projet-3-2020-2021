/**
 * controller.c
 * 
 * Ce fichier est le point d'entrée du programme
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdbool.h>

#include "controller.h"
#include "vue.h"
#include "model.h"

int main(int argc, char **argv){
   Model *m = create_model(true);
   if(m == NULL)
      return EXIT_FAILURE;

   Vue *v = create_vue(m);
   if(v == NULL)
      return EXIT_FAILURE;

   Controller *c = create_controller(v, m);
   if(c == NULL)
      return EXIT_FAILURE;

   //Lancement de l'IHM
   GtkWidget *pWindow;
   GtkWidget *pTable;
   GtkWidget *pButton[17];

   //Init de GTK
   gtk_init(&argc, &argv);

   //Création de la fenêtre
   pWindow = create_window();

   //Création des boutons pour l'initialisation de la fenêtre
   pTable = gtk_table_new(4, 5, FALSE);
   //create_and_attach_buttons(pTable, pButton);
   for(int i = 0; i < 16; i++)
      pButton[i] = load_image_button("images/default.png");

   pButton[16] = gtk_button_new_with_label("Nouvelle Partie");

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

   //Gestion des évènements
   c->pButton = pButton[0];
   c->pButtonNumber = 0;
   g_signal_connect(G_OBJECT(c->pButton), "clicked", G_CALLBACK(click_first_player), c);

   //Ajout des éléments à la fenêtre
   gtk_container_add(GTK_CONTAINER(pWindow), GTK_WIDGET(pTable));
   gtk_widget_show_all(pWindow);

   gtk_main();

   return EXIT_SUCCESS;
}
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
   Model *m = create_model(false, true);
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
   GtkButton *pButton[17];

   //Init de GTK
   gtk_init(&argc, &argv);

   //Création de la fenêtre
   pWindow = create_window();

   //Création des boutons pour l'initialisation de la fenêtre
   pTable = gtk_table_new(4, 5, FALSE);
   create_and_attach_buttons(pTable, pButton, c);

   //Gestion des évènements
   signal_connect(c);

   if(c->pButtonNumber > 15)
      c->m->gameState = false;

   //Ajout des éléments à la fenêtre
   gtk_container_add(GTK_CONTAINER(pWindow), GTK_WIDGET(pTable));
   gtk_widget_show_all(pWindow);

   gtk_main();

   return EXIT_SUCCESS;
}
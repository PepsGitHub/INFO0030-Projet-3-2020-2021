/**
 * controller.h
 * 
 * Ce fichier contient les prototypes des fonctions liées aux actions de l'utilisateur
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

/**
 * \file controller.h
 * \brief Librairie contenant les prototypes des fonctions liées aux actions de l'utilisateur
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 30/03/2021
*/

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <gtk/gtk.h>

#include "model.h"
#include "vue.h"

typedef struct controller_t{
   struct vue_t *v;
   Model *m;
   GtkWidget *pButton[17];
   unsigned short pButtonNumber;
}Controller;

Controller *create_controller(struct vue_t *v, Model *m);

void click_button(GtkWidget *pButton, gpointer data);

void destroy_window(GtkWidget *pWindow, gpointer data);


#endif // __controller__
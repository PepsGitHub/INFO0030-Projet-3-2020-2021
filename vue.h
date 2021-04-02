/**
 * vue.h
 * 
 * Ce fichier contient les prototypes des fonctions liées à l'affichage du jeu
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

/**
 * \file vue.h
 * \brief Librairie contenant les prototypes des fonctions liées à l'affichage du jeu
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 30/03/2021
*/

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __VUE__
#define __VUE__

#include <gtk/gtk.h>

#include "model.h"
#include "controller.h"

typedef struct vue_t{
   Model *m;
}Vue;

Vue *create_vue(Model *m);

/**
 * \fn GtkWidget *create_window(void)
 * \brief Crée la fenêtre
 * 
 * \param \
 * 
 * \pre: \
 * \post: la fenêtre est créée
 * 
 * \return:
 *    pWindow Succès
 */
GtkWidget *create_window(void);

/**
 * \fn GtkWidget *create_window(void)
 * \brief Crée la fenêtre
 * 
 * \param filename le nom de l'image à charger sur un bouton
 * 
 * \pre: filename != NULL
 * \post: le bouton est créé avec l'image
 * 
 * \return:
 *    pButton Succès
 */
GtkButton *load_image_button(char *filename);

GtkButton *change_image_button(GtkButton *pButton, char *filename);

GtkWidget *create_and_attach_buttons(GtkWidget *pTable, GtkButton **pButton, struct controller_t *c);

void signal_connect(struct controller_t *c);

void redraw_button(struct controller_t *c, int i);



#endif // __vue__

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
   GtkButton *pButton[17];
   unsigned short pButtonNumber;
}Controller;

Controller *create_controller(struct vue_t *v, Model *m);

void click_button_0(GtkWidget *pButton, gpointer data);

void click_button_1(GtkWidget *pButton, gpointer data);

void click_button_2(GtkWidget *pButton, gpointer data);

void click_button_3(GtkWidget *pButton, gpointer data);

void click_button_4(GtkWidget *pButton, gpointer data);

void click_button_5(GtkWidget *pButton, gpointer data);

void click_button_6(GtkWidget *pButton, gpointer data);

void click_button_7(GtkWidget *pButton, gpointer data);

void click_button_8(GtkWidget *pButton, gpointer data);

void click_button_9(GtkWidget *pButton, gpointer data);

void click_button_10(GtkWidget *pButton, gpointer data);

void click_button_11(GtkWidget *pButton, gpointer data);

void click_button_12(GtkWidget *pButton, gpointer data);

void click_button_13(GtkWidget *pButton, gpointer data);

void click_button_14(GtkWidget *pButton, gpointer data);

void click_button_15(GtkWidget *pButton, gpointer data);

void click_new_game(GtkWidget *pButton, gpointer data);

void button_clicked(GtkButton *pButton, Model *m);

void destroy_window(GtkWidget *pWindow, gpointer data);


#endif // __controller__
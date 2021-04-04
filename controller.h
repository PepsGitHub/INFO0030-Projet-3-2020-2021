/**
 * controller.h
 * 
 * Ce fichier contient les prototypes des fonctions liées aux actions de l'utilisateur
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 04/04/21
 * @projet: INFO0030 Projet 3
 */

/**
 * \file controller.h
 * \brief Librairie contenant les prototypes des fonctions liées aux actions de l'utilisateur
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 04/04/2021
*/

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <assert.h>
#include <gtk/gtk.h>

#include "model.h"
#include "vue.h"

typedef struct controller_t{
   struct vue_t *v;
   Model *m;
   GtkWidget *pButton[17];
   unsigned short pButtonNumber;
}Controller;

/**
 * \fn Controller *create_controller(struct vue_t *v, Model *m)
 * \brief Crée le controlleur
 * 
 * \param v la vue
 * \param m le modèle
 * 
 * \pre m != NULL, v != NULL
 * \post le controlleur est correctement créé
 * 
 * \return c Succès
 */
Controller *create_controller(struct vue_t *v, Model *m);

/**
 * \fn void signal_connect(struct controller_t *c)
 * \brief Rassemble les actions des boutons
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post le controlleur est correctement créé
 * 
 * \return c Succès
 */
void signal_connect(struct controller_t *c);

/**
 * \fn void click_button_0(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 0
 * 
 * \param pButton un bouton
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 0 ont eu lieu
 * 
 * \return
 *    \
 */
void click_button_0(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_1(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 1
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 1 ont eu lieu
 * 
 * \return \
 */
void click_button_1(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_2(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 2
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 2 ont eu lieu
 * 
 * \return \
 */
void click_button_2(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_3(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 3
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 3 ont eu lieu
 * 
 * \return \
 */
void click_button_3(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_4(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 4
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 4 ont eu lieu
 * 
 * \return \
 */
void click_button_4(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_5(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 5
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 5 ont eu lieu
 * 
 * \return \
 */
void click_button_5(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_6(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 6
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 6 ont eu lieu
 * 
 * \return \
 */
void click_button_6(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_7(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 7
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 7 ont eu lieu
 * 
 * \return \
 */
void click_button_7(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_8(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 8
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 8 ont eu lieu
 * 
 * \return \
 */
void click_button_8(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_9(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 9
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 9 ont eu lieu
 * 
 * \return \
 */
void click_button_9(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_10(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 10
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 10 ont eu lieu
 * 
 * \return \
 */
void click_button_10(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_11(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 11
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 11 ont eu lieu
 * 
 * \return \
 */
void click_button_11(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_12(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 12
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 12 ont eu lieu
 * 
 * \return \
 */
void click_button_12(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_13(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 13
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 13 ont eu lieu
 * 
 * \return \
 */
void click_button_13(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_14(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 14
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 14 ont eu lieu
 * 
 * \return \
 */
void click_button_14(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_button_15(GtkWidget *pButton, gpointer data)
 * \brief Conséquences du clic sur le bouton 15
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post Les conséquences du clic sur le bouton 15 ont eu lieu
 * 
 * \return \
 */
void click_button_15(GtkWidget *pButton, gpointer data);

/**
 * \fn void click_new_game(GtkWidget *pButton, gpointer data)
 * \brief Réinitialise le jeu
 * 
 * \param pButton le bouton en question
 * \param data le type de données
 * 
 * \pre \
 * \post le jeu est réinitialisé, une nouvelle partie peut commencer
 * 
 * \return \
 */
void click_new_game(GtkWidget *pButton, gpointer data);

/**
 * \fn void destroy_window(GtkWidget *pWindow, gpointer data)
 * \brief Détruit la fenêtre
 * 
 * \param pWindow le bouton pour quitter la fenêtre
 * \param data le type de données
 * 
 * \pre \
 * \post: la fenêtre est détruite
 * 
 * \return \
 */
void destroy_window(GtkWidget *pWindow, gpointer data);

#endif // __controller__
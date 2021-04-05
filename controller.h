/**
 * controller.h
 * 
 * Ce fichier contient les prototypes des fonctions liées aux actions de l'utilisateur
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 04/04/21
 * @projet: INFO0030 Projet 3
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

/**
 * \file controller.h
 * \brief Librairie contenant les prototypes des fonctions liées aux actions de l'utilisateur
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 04/04/2021
 * 
 * Déclaration du type opaque Controller
 *
 */

typedef struct controller_t Controller;

/**
 * \fn struct vue_t *get_vue(Controller *c)
 * \brief Accesseur en lecture pour le champ v
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post le champ est lu
 * 
 * \return c->v Succès
 */
struct vue_t *get_vue(Controller *c);

/**
 * \fn Model *get_model_c(Controller *c)
 * \brief Accesseur en lecture pour le champ m
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post le champ est lu
 * 
 * \return c->m Succès
 */
Model *get_model_c(Controller *c);

/**
 * \fn GtkWidget **get_buttons(Controller *c)
 * \brief Accesseur en lecture pour le champ pButton
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post le champ est lu
 * 
 * \return c->pButton Succès
 */
GtkWidget **get_buttons(Controller *c);

/**
 * \fn unsigned int get_pButtonNumber(Controller *c)
 * \brief Accesseur en lecture pour le champ pButtonNumber
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post le champ est lu
 * 
 * \return c->pbuttonNumber Succès
 */
unsigned int get_pButtonNumber(Controller *c);

/**
 * \fn Controller *set_vue(Controller *c, struct vue_t *v)
 * \brief Accesseur en écriture pour le champ v
 * 
 * \param c le controlleur
 * \param v la vue
 * 
 * \pre c != NULL, v != NULL
 * \post le champ est modifié
 * 
 * \return c Succès
 */
Controller *set_vue(Controller *c, struct vue_t *v);

/**
 * \fn Controller *set_model_c(Controller *c, Model *m)
 * \brief Accesseur en écriture pour le champ m
 * 
 * \param c le controlleur
 * \param m le modèle
 * 
 * \pre c != NULL, m != NULL
 * \post le champ est modifié
 * 
 * \return c Succès
 */
Controller *set_model_c(Controller *c, Model *m);

/**
 * \fn Controller *set_buttons(Controller *c, GtkWidget *pButtons[17])
 * \brief Accesseur en écriture pour le champ pButtons
 * 
 * \param c le controlleur
 * \param v la vue
 * 
 * \pre c != NULL, pButtons != NULL
 * \post le champ est modifié
 * 
 * \return c Succès
 */
Controller *set_buttons(Controller *c, GtkWidget **pButtons);

/**
 * \fn Controller *set_buttonNumber(Controller *c, unsigned int pButtonNumber)
 * \brief Accesseur en écriture pour le champ pButtonNumber
 * 
 * \param c le controlleur
 * \param pButtonNumber le numéro du bouton
 * 
 * \pre c != NULL
 * \post le champ est modifié
 * 
 * \return c Succès
 */
Controller *set_buttonNumber(Controller *c, unsigned int pButtonNumber);

/**
 * \fn Controller *create_controller(struct vue_t *v, Model *m)
 * \brief Crée le controlleur
 * 
 * \param v la vue
 * \param m le modèle
 * 
 * \pre m != NULL, v != NULL
 * \post le controlleur est créé
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
 * \post les signaux sont effectifs
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
 * \fn bool is_button_clicked(Controller *c, unsigned int buttonNumber)
 * \brief Permet de savoir si le bouton en question a déjà été cliqué
 * 
 * \param c le controlleur
 * \param buttonNumber le numéro du bouton
 * 
 * \pre c != NULL
 * \post on connait l'état du bouton
 * 
 * \return true bouton déjà cliqué
 * \return false bouton pas encore cliqué
 */
bool is_button_clicked(Controller *c, unsigned int buttonNumber);

/**
 * \fn void destroy_window(GtkWidget *pWindow, gpointer data)
 * \brief Détruit la fenêtre
 * 
 * \param pWindow le bouton pour quitter la fenêtre
 * \param data le type de données
 * 
 * \pre \
 * \post la fenêtre est détruite
 * 
 * \return \
 */
void destroy_window(GtkWidget *pWindow, gpointer data);

#endif // __controller__
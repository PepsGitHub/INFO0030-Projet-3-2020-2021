/**
 * vue.h
 * 
 * Ce fichier contient les prototypes des fonctions liées à l'affichage du jeu
 * 
 * \author: Dumoulin Peissone S193957
 * \date: 08/04/21
 * @projet: INFO0030 Projet 3
 */

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __VUE__
#define __VUE__

#include <gtk/gtk.h>
#include <assert.h>

#include "model.h"
#include "controller.h"

/**
 * \file vue.h
 * \brief Librairie contenant les prototypes des fonctions liées à l'affichage du jeu
 * \author Peissone Dumoulin - Université de Liège
 * \version 1.0
 * \date 08/04/2021
 * 
 * Déclaration du type opaque Vue
 *
 */
typedef struct vue_t Vue;

/**
 * \fn Vue *create_vue(Model *m)
 * \brief Crée la vue
 * 
 * \param model le modèle
 * 
 * \pre m != NULL
 * \post la vue est correctement créée
 * 
 * \return v Succès
 */
Vue *create_vue(Model *m);

/**
 * \fn Model *get_model(Vue *v)
 * \brief Accesseur en lecture pour le champ m
 * 
 * \param v la vue
 * 
 * \pre v != NULL
 * \post le champ est lu
 * 
 * \return v->m Succès
 */
Model *get_model(Vue *v);

/**
 * \fn Vue *set_model(Vue *v, Model *m)
 * \brief Accesseur en écriture pour le champ m
 * 
 * \param v la vue
 * \param m le modèle
 * 
 * \pre v != NULL, m != NULL
 * \post le champ est modifié
 * 
 * \return v Succès
 */
Vue *set_model(Vue *v, Model *m);

/**
 * \fn GtkWidget *create_window(void)
 * \brief Crée la fenêtre
 * 
 * \param \
 * 
 * \pre \
 * \post la fenêtre est créée
 * 
 * \return pWindow Succès
 */
GtkWidget *create_window(void);

/**
 * \fn GtkButton *load_image_button(char *filename)
 * \brief Création d'un bouton avec image
 * 
 * \param filename le nom de l'image à charger sur un bouton
 * 
 * \pre filename != NULL
 * \post le bouton est créé avec l'image
 * 
 * \return pButton Succès
 */
GtkButton *load_image_button(char *filename);

/**
 * \fn GtkButton *change_image_button(GtkButton *pButton, char *filename)
 * \brief Permet de changer l'image d'un bouton déjà existant
 * 
 * \param pButton le bouton en question
 * \param filename le nom de l'image à charger sur un bouton
 * 
 * \pre pButton != NULL, filename != NULL
 * \post l'image du bouton est changée
 * 
 * \return pButton Succès
 */
GtkButton *change_image_button(GtkButton *pButton, char *filename);

/**
 * \fn GtkWidget *create_and_attach_buttons(GtkWidget *pTable, 
 GtkWidget **pButton, struct controller_t *c)
 * \brief Création des boutons et du tableau de boutons
 * 
 * \param pTable la table où attacher les boutons
 * \param pButton un tableau de boutons
 * \param c le controlleur
 * 
 * \pre pButton != NULL, c != NULL
 * \post le tableau de boutons est créé
 * 
 * \return pTable Succès
 */
GtkWidget *create_and_attach_buttons(GtkWidget *pTable, GtkWidget **pButton, struct controller_t *c);

/**
 * \fn void redraw_button(struct controller_t *c)
 * \brief Redessine le bouton qui vient d'être cliqué
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post le bouton est redessiné
 * 
 * \return /
 */
void redraw_button(struct controller_t *c);

/**
 * \fn void redraw_winning_buttons(struct controller_t *c)
 * \brief Redessine les boutons de la combinaison gagnante
 * 
 * \param c le controlleur
 * 
 * \pre c != NULL
 * \post les boutons de la combinaison gagnante sont redessinés
 * 
 * \return /
 */
void redraw_winning_buttons(struct controller_t *c);

#endif // __vue__

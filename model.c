/**
 * model.c
 * 
 * Ce fichier contient les fonctions liées aux mécanismes du jeu
 * 
 * @author: Dumoulin Peissone S193957
 * @date: 30/03/21
 * @projet: INFO0030 Projet 3
 */

#define X 1
#define O 0

#include <stdbool.h>

#include "model.h"

Model *create_model(bool value){
   Model *m = malloc(sizeof(Model));
   if(m == NULL)
      return NULL;

   m->value = value;

   return m;
}
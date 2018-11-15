#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"


int main(int argc, char **argv) {

  FILE *s = NULL;

  struct heartBeat *dataLoaded;


  if((s = fopen("../03 - Processing/main/beats.csv", "r")) == NULL) {
    //On donne à s la valeur du return de fopen, qui est donc différent de NULL si ça a fonctionné
    //tout en vérifiant si il a fonctionné
    printf("Impossible d'ouvrir le fichier.");
    exit(-1);
    //Si le fopen n'a pas fonctionné, on envoie un message d'erreur et on quitte le problème
  }

  int n = getLength(s);
  //On met dans n le nombre de ligne contenu dans le fichier .csv

  read(s, (struct heartBeat **)&dataLoaded, n);
  //On lit le fichier et on rentre les valeurs dans un tableau de structure de la taille du fichier

  UI(dataLoaded, n);
  //On appelle la fonction du menu qui va appeler les autres fonctions et s'occuper de l'interface

  fclose(s);
  free(dataLoaded);
  //free(dataSortedByBPM);
  //On ferme le fichier et on libère l'espace réquisitionné par le programme
  return 0;
}

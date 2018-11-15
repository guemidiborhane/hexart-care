#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "actions.h"


int getLength(FILE *f){  // fonction permettant d'obtenir le nombre de ligne du fichier f
    fseek(f, 0, SEEK_SET); // permet de remettre le curseur en haut du fichier
    char temp[LENGTH_LINE]; // tableau de charactere ou va être stocké la ligne du fichier lu
    int i = 0;

    while(fgets(temp, LENGTH_LINE, f) != NULL) // tant que l'on arrive a lire une ligne
    {
        i ++; // on increment i de 1
    }
    return i; // et on retourne cette valeur de i
}


int moyInRange(int n, struct heartBeat *a, int min, int max) { // fait la moyenne des bpm entre deux timestamp (min et max)
  int i;
  int sum = 0;
  int counter = 0;
  for(i = 0; i < n; ++i) { // on parcoure notre tableau de structure
    if (min <= a[i].timestamp && a[i].timestamp <= max){ // si le bpm de la case du tableau que l'on regarde se situe entre les deux timestamp
      sum += a[i].bpm; // alors on ajoute a notre variable sum le bpm de cette case
      counter++;     // et on increment le counter
    }
  }
  return sum/counter;
}


int getFirstBPMInRange(int n, struct heartBeat *a, int min, int max){ // recupere le bpm de l'index le plus petit entre deux timestamp (min et max)
    int i;
    for(i = 0; i < n; ++i) { // on parcoure notre tableau de structure
    if (min <= a[i].timestamp && a[i].timestamp <= max){ // si le bpm de la case du tableau que l'on regarde se situe entre les deux timestamp
      return a[i].bpm;
    }
  }
  return -1;
}


int getLastBPMInRange(int n, struct heartBeat *a, int min, int max){ // opposé de getfirstbpminrange
  int i;
  for (i = n; i-- > 0; )
  {
    if (min <= a[i].timestamp && a[i].timestamp <= max){
      return a[i].bpm;
    }
  }
  return -1;
}

void getDate(char * buffer, int timestamp){
    struct tm * timeinfo;
    /* Conversion to time_t as localtime() expects a time_t* */
    time_t epoch_time_as_time_t = timestamp;
    /* Call to localtime() now operates on time_t */
    timeinfo = localtime(&epoch_time_as_time_t);
    strftime(buffer, 60, "%d/%m/%Y %H:%M:%S", timeinfo);

}

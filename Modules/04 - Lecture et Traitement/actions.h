#include "donnees.h"
#ifndef ACTIONS_H
#define ACTIONS_H


//recupere le nbr de ligne du fichier
int getLength(FILE *f);

// fonction de tri
void sort(int n, struct heartBeat *a, int (cmp)(struct heartBeat *, struct heartBeat *));


// recupere la moyenne de bpm entre deux timestamp
int moyInRange(int n, struct heartBeat *a, int min, int max);


int getFirstBPMInRange(int n, struct heartBeat *a, int min, int max);


int getLastBPMInRange(int n, struct heartBeat *a, int min, int max);


#endif // ACTIONS_H

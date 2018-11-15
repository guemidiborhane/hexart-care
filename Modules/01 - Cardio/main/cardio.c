#include "cardio.h"


// fonction permettant de charger des valeurs dans une structure heartBeat afin de lancer une capture
void startCapture(hearbeat *HB, int startTime, int period){
  HB->beats =0;
  HB->startTime = startTime;
  HB->period = period;
}

// fonction permettant de recuperer le nombre de battement pas minute
void determineBPM(hearbeat *HB){
  // produit en croix permettant de determiné le nombre de battement par minute a l'aide d'un nombre de battement total sur un temps.
  HB->bpm = (HB->beats * (60000/(float)HB->period));
}

// fonction appelé lorsque la capture doit s'arreter et retourne le BPM 
int stopCapture(hearbeat *HB){
  determineBPM(HB);
  return HB->bpm;
}

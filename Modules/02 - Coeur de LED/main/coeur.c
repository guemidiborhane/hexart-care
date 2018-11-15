#include "Arduino.h"
#include "coeur.h"
#include "param.h"

// variable global
int LED[20]; // tableau contenant les pins de nos leds
short ledLength; // contient le nombre de led
short lastLedIndex = -1; // index du tableau LED contenant la derniere led allumé

void initLedPin(int pin[], int Length) { // permet de passer les variables locales en globales au fichier 
  ledLength = Length;
  int i;
  for(i = 0; i < ledLength; i++){
    LED[i] = pin[i];
    pinMode(pin[i], OUTPUT);
  }
}


void turnOn(int i) { // allume la led correspond au pin LED[i]
  digitalWrite(LED[i], HIGH);
  lastLedIndex = i;
 
}
void clearLed(){ // eteint toutes les leds
  int i;
  for(i = 0; i < ledLength; i++){
    digitalWrite(LED[i], LOW);
  }
}

void modeAll() { // allume toutes les leds
  int i = 0;
  for (i = 0; i < ledLength; i++) {
    turnOn(i);
  }
}

void modeRandom() { // allume toutes les leds
 // int i = random(0,ledLength - 1);
 // turnOn(i);
}

void modeOneByOne(){ // allume une leds apres l'autre
  if (lastLedIndex < ledLength - 1){
    turnOn(lastLedIndex +1);
  }else{
    turnOn(0);
  }
}

void modeOneForX(){ // allume une leds / sur 2 / sur 3 / sur 4
  // pour 2 pour 3 pour 4 viens ici du fichier param.h qui contient en define le parametre correspondant
  int i;
  for(i = 0; i < ledLength; i+=parameter){
    turnOn(i);
  }
}

void printLed() { // fonction permettant en fonction du mode (provenant du fichier param.h) d'allumé de la bonne maniere la/les leds
  switch (mode) {
    case 1:
      modeAll();
      break;
    case 2:
      modeOneForX();
      break;
    case 3:
      modeOneByOne();
      break;     
    case 4:
      turnOn(parameter);
      break;         
    default:
      modeAll();
      break;
  }
}

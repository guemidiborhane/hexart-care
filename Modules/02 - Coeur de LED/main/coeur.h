#ifndef COEUR_H
#define COEUR_H
#ifdef __cplusplus
extern "C" {
#endif

// this function will be call one times to store all pins leds
void initLedPin(int pin[], int Length);

// allume la led correspondant au pin LED[index]
void turnOn(int index);
// eteint toutes les leds
void clearLed();
// allume toutes les leds
void modeAll();
// allume une led apres l'autre
void modeOneByOne();
// allume une leds sur la valeur de parameter dans le fichier param.h
void modeOneForX();
// fonction pour allumer les leds dans le mode selectionné dans param.h
void printLed();
#ifdef __cplusplus
} // extern "C"
#endif
#endif

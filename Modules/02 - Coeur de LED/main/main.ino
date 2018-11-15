// fichier pour tester le module coeur.
#include "Arduino.h"
#include "coeur.h"

void setup(){
  //Serial.begin(9600);
  int pins[] = {2,3,4,5,6,7,8,9,10,11};
  initLedPin(pins, 10);

}

void loop(){
  printLed();
  delay(200);
  clearLed();
  delay(500);
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "generateCode.h"


int main(int argc, char **argcv){

    FILE* f = NULL;
    f = fopen("../../../app/param.h","w"); // on ouvre le fichier app/param.h en mode d'écriture

    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier");
        return 1;
    }

    char choice1 = '1';
    char choice2 = '1';
    char choice3;

    do {
        choice1 = showMenu();
        printf("\n");
    } while(choice1 != '1' && choice1 != '2' && choice1 != '3' && choice1 != '4' && choice1 != '5');

    if (choice1 == '5') {
        return 0;
    }

    if (choice1 == '2' || choice1 == '4') {
        do {
                system("cls");
                choice2 = showSubMenu(choice1);
                printf("\n");
        } while(choice2 != 'q' && ((int) choice2 > 0 && (int) choice2 < 9));
    }
    if (choice1 == 'q'){
        return 0;
    }
    system("cls");
    createFile(f, choice1, choice2); // appel de la fonction ecrivant dans notre fichier param.h les parametres d'allumage des leds
    fclose(f);
    printf("Fichier g%cn%cr%c.\n", 130, 130, 130);
    printf("Voulez vous le transferer sur l'arduino ?\n");

    do {
        printf("[y]es / [n]o: ");
        choice3  = getche();

    }while(choice3 != 'y' && choice3 != 'n');

    if(choice3 == 'y'){
        printf("Envoi en cours . . .\n");
        // permet d'envoyer un projet ino sur un arduino branché en usb
//        system("C:/Program Files/WindowsApps/ArduinoLLC.ArduinoIDE_1.8.15.0_x86__mdqgnx93n4wtt/arduino_debug.exe --upload C:/Users/Hichem/Documents/Ecole/projet/A1-Hexart-Care-master/app/app.ino");

    }

    return 0;
}

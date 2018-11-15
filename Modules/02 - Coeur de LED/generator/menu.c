#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"menu.h"

char showMenu(){
    system("cls"); // vide la console
    printf("||------------------------------------------------------||\n");
    printf("||       Menu : Param%ctrage du prototype (AFFICHAGE)    ||\n", 130);
    printf("||------------------------------------------------------||\n");
    printf("|| [1] Toutes les LEDs clignotes                        ||\n");
    printf("|| [2] Clignote une LEDs sur XXX                        ||\n");
    printf("|| [3] Une led apres l'autre                            ||\n");
    printf("|| [4] Une seul LED clignote au choix                   ||\n");
    printf("|| [5] Pour quitter                                     ||\n");
    printf("||------------------------------------------------------||\n");
    printf("\nVotre choix: ");
    return getche(); // getche() retourne la valeur de la touche pressé a la suite de son appel
}

char showSubMenu(char choice){
    system("cls");
    printf("||------------------------------------------------------||\n");
    printf("||       Menu : Parametre supplementaire                ||\n");
    printf("||------------------------------------------------------||\n");
    if (choice == '2'){
        printf("||  Une led sur combien ?                           ||\n");
    }else if(choice == '4'){
        printf("||  Quelle LEDs voulez vous allum%c [0;9]                ||\n", 130);
    }
    printf("||------------------------------------------------------||\n");
    printf("||  [q] Pour quitter                                    ||\n");
    printf("\nVotre choix: ");
    return getche();
}

#include "donnees.h"

#ifndef MENU_H
#define MENU_H


void UI(struct heartBeat *dataLoaded, int size);
//La fonction qui va appeller les menu et les autres fonctions
//afin de gérer toutes les demandes de l'utilisateur  et les afficher

char showMenu();
//Affiche le menu principale dans la console et demande une valeur � l'utilisateur

char showSubMenu1();
//Affiche le sous menu correspondant au choix 1. du menu principal et demande une valeur � l'utilisateur

char showBackMenu1();
//Demande si l'utilisateur veut quitter le programme ou revenir au menu principal

void showReversed(int n, struct heartBeat *a);
//Affiche les donn�es contenu dans un tableau de structure dans l'ordre inverse

void show(int n, struct heartBeat *a);
//Affiche les donn�es contenu dans un tableau de structure dans l'ordre

void showInRange(int n, struct heartBeat *a, int min, int max);
//Affiche les donn�es appartenant � un intervalle de temps

#endif // MENU_H

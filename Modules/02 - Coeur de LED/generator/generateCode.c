#include <stdlib.h>
#include <stdio.h>

void createFile(FILE *f, char choice1, char choice2)
{
    fprintf(f, "%s %c\n", "#define mode",choice1); // écriture dans le fichier de notre choix
    fprintf(f, "%s %c", "#define parameter",choice2); // écriture dans le fichier du parametre optionnel en fonction des cas
}

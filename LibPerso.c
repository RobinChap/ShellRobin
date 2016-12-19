//Bibliothèqe de fonctions d'usage commun
//Pris sur le web ou maison
//De Robin Chaperon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LibPerso.h"


void clean(const char *buffer, FILE *fp)
{
    char *p = strchr(buffer,'\n');
    if (p != NULL)
        *p = 0;
    else
    {
        int c;
        while ((c = fgetc(fp)) != '\n' && c != EOF);
    }
}

void waitFor(unsigned int secs){
    unsigned int retTime = time(0) + secs;
    while(time(0) < retTime);
}

#include <stdio.h>
#include <stdlib.h>
#include "niveau.h"

int chargerNiveau()
{
    FILE *fichier = NULL;
    char ligneFichier[3] = {0};
    int i = 0, j = 0;
    fichier = fopen("niveau.txt", "r");
    if(!fichier)
    {
        printf("impossible de lire le fichier niveau\n");
        exit(0);
    }
    fscanf(fichier, "%d %d %d", );
    fclose(fichier);
}
int sauvegarderNiveau()
{
    FILE* fichier=NULL;
    int i =0, j=0;
    fichier=fopen("niveau.txt", "a");
    if(!fichier)
    {
        printf("impossible d'ecrire dans le fichier");
        exit(0);
    }
    fprintf(fichier, "%d %d %d");
    fclose(fichier);

}

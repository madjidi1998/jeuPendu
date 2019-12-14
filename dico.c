#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"
int piocherMot(char *motPioche)
{
FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
long nombreMots = 0, numMotChoisi = 0;
int caractereLu = 0;
dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule
// On vérifie si on a réussi à ouvrir le dictionnaire
if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
{
printf("\nImpossible de charger le dictionnaire de mots");
return 0; // On retourne 0 pour indiquer que la fonction a échoué
// A la lecture du return, la fonction s'arrête immédiatement.
}
// On compte le nombre de mots dans le fichier (il suffit de compter les
// entrées \n). Pensez à laisser une Entrée après le dernier mot du dico !
do
{
caractereLu = fgetc(dico);
if (caractereLu == '\n')
nombreMots++;
} while(caractereLu != EOF);
numMotChoisi = nombreAleatoire(nombreMots); /* On pioche un mot au hasard
// On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivés au
bon mot*/
rewind(dico);
while (numMotChoisi > 0)
{
caractereLu = fgetc(dico);
if (caractereLu == '\n')
numMotChoisi--;
}
/* Le curseur du fichier est positionné au bon endroit.
On n'a plus qu'à faire un fgets qui lira la ligne */
fgets(motPioche, 100, dico);
// On vire l'\n à la fin
motPioche[strlen(motPioche) - 1] = '\0';
fclose(dico);
return 1; // Tout s'est bien passé, on retourne 1
}
long nombreAleatoire(long nombreMax)
{
srand(time(NULL));
return (rand() % nombreMax);
}


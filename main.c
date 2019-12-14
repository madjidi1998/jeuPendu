#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dico.h"

int gagne(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);
char lireCaractere();
int main(int argc, char* argv[])
{
char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
char motSecret[100] = {0}; // Ce sera le mot à trouver
int *lettreTrouvee = NULL; /* Un tableau de booléens. Chaque case correspond à une
lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée*/
 // Compteur de coups restants (0 = mort)
long i = 0; // Une petite variable pour parcourir les tableaux
long tailleMot = 0;
int choix;
int rep;
do
{
int Score;
long coupsRestants = 7;
printf("====================================\n");
printf("= ================================ =\n");
printf("== BIENVENUE DANS LE JEU DU PENDU ==\n");
printf("==                                ==\n");
printf("= = = = = = = = = = =  = = = = = = =\n");
printf("= = = = = = = = = = = =  = = = = = =\n");
printf("1 -JOUER\n\n");
printf("2 -REGLES DU JEU\n\n");
printf("3 -MEILLEUR SCORE\n\n");
printf("0 -QUITTER\n\n");
scanf("%d", &choix);
switch(choix)
{
case 1:
if (!piocherMot(motSecret))
exit(0);
tailleMot = strlen(motSecret);
lettreTrouvee = malloc(tailleMot * sizeof(int)); /*On alloue dynamiquement le tableau
lettreTrouvee (dont on ne connaissait pas la taille au départ)*/
if (lettreTrouvee == NULL)
exit(0);
for (i = 0 ; i < tailleMot ; i++)
lettreTrouvee[i] = 0;
// On continue à jouer tant qu'il reste au moins un coup à jouer ou qu'on
// n'a pas gagné

while (coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot))
{

printf("\n\nIl vous aviez %ld coups a jouer", coupsRestants);
printf("\nLe mot a trouver est: ");
/* On affiche le mot secret en masquant les lettres non trouvées
Exemple : *A**ON */
for (i = 0 ; i < tailleMot ; i++)
{
if (lettreTrouvee[i]) // Si on a trouvé la lettre n°i
printf("%c", motSecret[i]); // On l'affiche
else
printf("*"); // Sinon, on affiche une étoile pour les lettres non trouvées
}
printf("\nFaites vos propositions ci dessous : \n");
lettre = lireCaractere();
printf("\n");
// Si ce n'était PAS la bonne lettre
if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
{
coupsRestants--; // On enlève un coup au joueur
affiche(coupsRestants);
}
}
if (gagne(lettreTrouvee, tailleMot))
printf("\n\nGagne ! Le mot secret etait bien : %s\n", motSecret);
else
printf("\n\nPerdu ! Le mot secret etait : %s\n", motSecret);


FILE* fichiers=NULL;
fichiers=fopen("score.txt", "r");
if(fichiers!=NULL)
{
    fscanf(fichiers, "%ld", coupsRestants);
    fclose(fichiers);
}


free(lettreTrouvee); // On libère la mémoire allouée manuellement (par malloc)
break;
case 2:
printf("REGLES DU JEU");
printf("\n=============\n");
printf("Le but du jeu est de deviner en moins de 7 essais un mot que seul l ordinateur connait. Pour\n");
printf ("mener a bien votre mission, vous allez proposer une lettre :\n");
printf (" -si la lettre est correcte alors, celle-ci s affiche à sa place dans le mot a deviner ;\n");
printf (" -si la lettre est incorrecte, alors, votre nombre d’essais diminue de 1.\n");
printf ("Autrement dit :\n");
printf (" -lorsqu’une lettre est correcte, le nombre d essais reste inchange ;\n");
printf (" -lorsqu’une lettre est incorrecte, le nombre d’essais diminue de 1 ;\n");
printf (" -lorsque tout le mot a ete devine, vous avez gagne ;\n");
printf (" -lorsque le nombre d’essais est a zero (0), vous avez perdu.\n");
printf ("Exemple:\n");
printf ("Supposons que le mot a deviner soit « bonjour ». Vous proposez la lettre  o , cette derniere se\n");
printf ("trouve dans le mot, l ordinateur affiche donc *o**o**. Si vous proposez ensuite la lettre  u ,\n");
printf ("l ordinateur affiche : *o**ou*.\n");
break;
case 3:
printf("MEILLEUR SCORE\n");
break;
case 0:
return 0;
break;
default:
printf("veillez entrez le bon numero\n");
break;
}
printf("1 pour continuer 0 pour annuler\n");
scanf("%d", &rep);
} while(rep==1);
return 0;
}
char lireCaractere()
{
char caractere = 0;
caractere = getchar(); // On lit le premier caractère

caractere = toupper(caractere); /* On met la lettre en majuscule si elle ne l'est pas
déjà*/
// On lit les autres caractères mémorisés un à un jusqu'à l'\n
while (getchar() != '\n') ;
return caractere; // On retourne le premier caractère qu'on a lu
}
int gagne(int lettreTrouvee[], long tailleMot)
{
long i = 0;
int joueurGagne = 1;
for (i = 0 ; i < tailleMot ; i++)
{
if (lettreTrouvee[i] == 0)
joueurGagne = 0;
}
return joueurGagne;
}
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
long i = 0;
int bonneLettre = 0;
// On parcourt motSecret pour vérifier si la lettre proposée y est
for (i = 0 ; motSecret[i] != '\0' ; i++)
{
if (lettre == motSecret[i]) // Si la lettre y est
{
bonneLettre = 1; // On mémorise que c'était une bonne lettre
lettreTrouvee[i] = 1; /* On met à 1 le case du tableau de booléens correspondant
à la lettre actuelle*/
}
}
return bonneLettre;
}
 void affiche(int coups)
{
    switch(coups)
    {
        case 6:
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        break;
        case 5:
        printf("-----------\n");
        printf("|          |\n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        break;
        case 4:
        printf("-----------\n");
        printf("|          |\n");
        printf("|         / \\\n");
        printf("|         \\_/\n");
        printf("|              \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        break;
        case 3:
        printf("-----------\n");
        printf("|          |\n");
        printf("|         / \\\n");
        printf("|         \\_/\n");
        printf("|         _|_ \n");
        printf("|         | |   \n");
        printf("|         |_| \n");
        printf("|             \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        break;
        case 2:
        printf("-----------\n");
        printf("|          |\n");
        printf("|         / \\\n");
        printf("|         \\_/\n");
        printf("|         _|_ \n");
        printf("|        /| |\\   \n");
        printf("|        /|_|\\ \n");
        printf("|             \n");
        printf("|          \n");
        printf("|          \n");
        printf("|          \n");
        break;
        case 1:
        printf("-----------\n");
        printf("|          |\n");
        printf("|         / \\\n");
        printf("|         \\_/\n");
        printf("|         _|_ \n");
        printf("|        /| |\\   \n");
        printf("|        /|_|\\ \n");
        printf("|          ^   \n");
        printf("|        /  \n");
        printf("|       /   \n");
        printf("|          \n");
        break;
        case 0:
        printf("-----------       \n");
        printf("|          |      \n");
        printf("|         / \\    \n");
        printf("|         \\_/    \n");
        printf("|         _|_     \n");
        printf("|        /| |\\   \n");
        printf("|        /|_|\\   \n");
        printf("|          ^      \n");
        printf("|        /   \\    \n");
        printf("|       /     \\   \n");
        printf("|                  \n");



    }
}




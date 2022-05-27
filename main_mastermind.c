#include <stdlib.h>
#include <stdio.h>
#include "mastermind.h" 
#include <time.h>


int main(){
    srand(time(NULL));
    int niveau=0;
    printf("Bienvenue au Mastermind \n");
    
    printf("\nRetrouver la suite exacte (donner aléatoirement par le\nprogramme et n’apparaissant pas à l’écran)\n");
    printf("\nQuand un chiffre est situé au bon endroit, renvoie un « A ».\n");
    printf("\nQuand un chiffre est présent dans la suite mais n’est pas situé \nau bon endroit, renvoie un « B ».\n");

    
    printf("\n\n");
    printf("1-Facile\n");
    printf("2-Moyen\n");
    printf("3-Difficile\n");
    printf("4-Quitter\n");

    scanf("%d", &niveau);
    int *solution; //tableau contenant la solution
    int *essai; //tableau saisi par le joueur
    int len; //taille du tableau
    int continuer; //Partie en cours vrai pour 1 faux pour 0
    int nb_essai=1;

    if(niveau ==1){
        len=4;
        printf("\n");
        solution=facile();
    }

    if(niveau ==2){
        len=6;
        printf("\n");
       solution=moyen();
    }

    if(niveau ==3){
        len=8;
        printf("\n");
        solution=difficile();
    }
    
    if(niveau ==4){
        printf("A une prochaine fois peut-être !\n");
        return 0;
    }

    printf("Essai n%d\n\n", nb_essai);
    essai=saisie(len);
    printf("\n");
    if(reussi(essai, solution, len)==1){
        printf("BRAVO ! VOUS AVEZ TROUVER LA BONNE SUITE DU PREMIER COUP\n");
        return 0;
    }
    else{
        printf("\n");
        continuer=afficher_resultat(essai, solution, len);
        
        while (continuer==1){
            printf("\n");
            nb_essai++;
            printf("Essai n%d\n\n", nb_essai);
            essai=saisie(len);
            if(reussi(essai, solution, len)){
                printf("\n");
                affiche_tab(essai,len);
                printf("BRAVO ! VOUS AVEZ TROUVER LA BONNE SUITE APRES %d ESSAIS\n", nb_essai);
                return 0;
            }
            continuer=afficher_resultat(essai, solution, len);
        }
        printf("\nDommage ! Vous-y étiez presque ;-(\n");
        return 0;
    }
}   
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mastermind.h" 

//Véririfie si l'élément k est unique dans le tableau 'solution'
int est_unique(int tab[], int len, int k){
    int cpt=0;
    for(int i=0; i<len;i++){
        if (tab[i]==k)
        {
            cpt++;
        }
    }
    if(cpt==1) return 1;
    else return 0;
}

int* facile(){
    printf("-Facile --> Sur un tableau de 4 cases\n");
    printf("        --> Des valeures de 1 à 4 uniques \nex: 1324, 3241, 4132, ...\n");
    printf("\n");

    int i=0;
    
    int *solution=malloc(sizeof(int)*4);
    if (solution==NULL){
        printf("Problème d'allocation \n");
        return NULL;
    }
    for(i=0; i<4;i++){
        
        solution[i] = rand() % 4 + 1;
        while(est_unique(solution,4,solution[i])==0){
            solution[i] = rand() % 4 + 1;
        }
        
    }
    
    return solution;
}

int* moyen(){
    printf("-Moyen --> Sur un tableau de 6 cases\n");
    printf("       --> Des valeures de 1 à 6 uniques \n");
    printf("       --> Une case vide représentée par un 0 (1 chance sur 6 d'apparaitre, pouvant apparaitre plusieurs fois)\nex:016532, 640201, ...\n");
    printf("\n");

    int i=0;
    
    int *solution=malloc(sizeof(int)*6);
    if (solution==NULL){
        printf("Problème d'allocation \n");
        return NULL;
    }
    for(i=0; i<6;i++){
        solution[i] = rand() % (6 + 1);
        if(solution[i]!=0){
            while(est_unique(solution,6,solution[i])==0){
                solution[i] = rand() % (6 + 1);
            }
        }
    }
    
    return solution;
}

int* difficile(){
    printf("-Difficile --> Sur un tableau de 8 cases\n");
    printf("           --> Des valeures de 1 à 8 pouvant apparaitre plusieurs fois (aléatoire de 1 à 8)\n");
    printf("           --> Une case vide représentée par un 0 (1 chancesur 5 d'apparaitre, pouvant apparaitre plulsieurs fois)\nex : 86220165, 07513570, ...)\n");
    printf("\n");
    
    int i=0;
    
    int *solution=malloc(sizeof(int)*8);
    if (solution==NULL){
        printf("Problème d'allocation \n");
        return NULL;
    }
    for(i=0; i<8;i++){
        
        solution[i] = rand() % (8 + 1);
        if(solution[i]!=0){
            while(est_unique(solution,8,solution[i])==0){
                solution[i] = rand() % (8 + 1);
            }
        }
        
    }
    
    return solution;
}

//affichage d'un tableau
void affiche_tab(int tab[], int len){
    
    for(int i=0; i<len ;i++){
        fprintf(stderr, "%d    |    ", tab[i]);
    }
    printf("\n");
}

//création du tableau par le joueur
int* saisie(int len){
    int i; 
    int *tab;
    tab=malloc(sizeof(int)*len);
    
    for ( i = 0; i < len; i++)
    {
        printf("chiffre %d :\n", i+1 );
        scanf("%d", &tab[i]);
    }
    return tab;
}

//renvoie 1 si le joueur a trouvé la bonne suite
int reussi(int essai[], int solution[], int len){
    int vrai=0;
    for(int i=0; i<len;i++){
        if(solution[i]==essai[i]){
            vrai++;
        }
    }
    if(vrai==len) return 1;
    else return 0;
}

//Compte le nombre de chiffre qui sont dans le bon emplacement
//du tableau saisi
int bien_place(int essai[], int solution[], int len){
    int i;
    int vrai=0;
    for(i=0; i<len;i++){
        if(solution[i]==essai[i]){
            vrai++;
        }
    }
    return vrai;
}

//Compte le nombre de chiffre qui sont présent dans la liste
//mais qui ne sont pas dans le bon emplacement 
int mal_place(int essai[], int solution[], int len){
    int i, j;
    int vrai=0;
    for(i=0; i<len ; i++){
        for (j=0; j<len ; j++)
        {
            if(essai[j]==solution[i]){
                if (j!=i) vrai++;
            }
        }
        
    }
    return vrai;
}

//retourne 1 si le joueur souhaite encore jouer et 0 sinon
//affiche le nombre de chiffre bien placé et/ou mal placé
int afficher_resultat(int essai[], int solution[], int len){
    affiche_tab(essai,len);
    int oui;
    printf("\n");
    printf("Résultat de la tentative : ");
    for (int i = 0; i < bien_place(essai,solution,len); i++)
    {
        printf("A ");
    }
    for (int i = 0; i < mal_place(essai,solution,len); i++)
    {
        printf("B ");
    }
    printf("\nVoulez-vous rejouer ? 1/0\n");
    scanf("%d", &oui);
    if (oui==1) return 1;
    else return 0;
}


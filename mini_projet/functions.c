#include "header.h"
void ajouter(livre arr[],int size,int *count){
    int i;
    for(i=0;i<size;i++){
        printf("\nEnter informations book %d:\n",i+1);
        
        printf(" \t \t\tTitre : ");
        scanf(" %[^\n]",arr[*count].titre);

        printf(" \t \t\tAutore: ");
        scanf(" %[^\n]",arr[*count].auteur);
         
        printf(" \t \t\tPrix: ");
        scanf("%f",&arr[*count].prix);

        printf(" \t \t\tQuantity : ");
        scanf("%d",&arr[*count].quantite);
        (*count)++;
    }

}

void afficher(livre arr[],int count){
    int i;
    for(i=0;i<count;i++){
        printf("\n============ book %d ===========\n",i+1);
        printf("\tTitre => %s\n",arr[i].titre);
          printf("\tAutour=> %s\n",arr[i].auteur);
            printf("\tPrix => %.2f\n",arr[i].prix);
              printf("\tQuantity => %d\n",arr[i].quantite);
    }
}

void rechercher(livre arr[],int count){
    int i;
    char T[20];
    printf("Enter title : ");
    scanf(" %[^\n]",T);
    int  verif=0;
    for(i=0;i<count;i++){
        if(strcmp(arr[i].titre,T) == 0){
          printf("\n============ Book Here ===========\n");
          printf("\tTitre => %s\n",arr[i].titre);
          printf("\tAutour=> %s\n",arr[i].auteur);
          printf("\tPrix => %.2f\n",arr[i].prix);
          printf("\tQuantity => %d\n",arr[i].quantite);
          printf("************ FOUND IT **************\n");
         verif =1;
        }     
    }

    if (verif != 1)
    {
       printf("==============  =  =============\n");
       printf("\tNOT FOUND IT!");
       printf("\n_______________________________\n");
    }

}

void modifie(livre arr[],int count){
    int i;
    char T[20];
    printf("\nFor Modify A Quantity :\n");
    printf("Enter Title: ");
    scanf(" %[^\n]",T);
     int  verif=0;
    for(i=0;i<count;i++){
        if(strcmp(arr[i].titre,T) == 0){
           verif =1;
          printf("\tNew Quantity : ");
          scanf("%d",&arr[i].quantite);

          printf("\n============ New Edite ===========\n");
          printf("\tTitre => %s\n",arr[i].titre);
          printf("\tAutour=> %s\n",arr[i].auteur);
          printf("\tPrix => %.2f\n",arr[i].prix);
          printf("\tQuantity => %d\n",arr[i].quantite);
          printf("_______________  DONE  ______________\n");

        
        }     
    }
        
    if (verif != 1)
    {
       printf("===========  =  ==========\n");
       printf("\tNOT FOUND IT!");
       printf("___________________________\n");
    }
    
}
void supprimer(livre arr[],int *count){
     int i;
    char T[20];

    printf("Enter title : ");
    scanf(" %[^\n]",T);

    int  verif=0;
    for(i=0;i<*count;i++){
        if(strcmp(arr[i].titre,T) == 0){
          verif =1;
          printf("\n========= You Are Delete This Book ===========\n");
          printf("\tTitre => %s\n",arr[i].titre);
          printf("\tAutour=> %s\n",arr[i].auteur);
          printf("\tPrix => %.2f\n",arr[i].prix);
          printf("\tQuantity => %d\n",arr[i].quantite);
          printf("__________________  DONE  _____________________\n");
        for (int j = i; j < *count ;j++)
          {
             arr[j] = arr[j+1];
          }
        }     
    }
    (*count)--;
    
    if (verif != 1)
    {
       printf("===========  =  ==========\n");
       printf("\tNOT FOUND IT!");
       printf("___________________________\n");
    }

}
int total_livre(livre arr[],int count){
    int total =0 ;
    for(int i=0;i<count;i++){
        total += arr[i].quantite;
    }
    return total; 
}
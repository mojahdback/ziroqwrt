#include <stdio.h>
#include <string.h>

#define MAX 100
typedef struct{
    char titre[20];
    char auteur[20];
    float prix;
    int quantite;

}livre;
     
   

void ajouter(livre arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("\nEnter informations book %d:\n",i+1);
        
        printf(" \t \t\tTitre : ");
        scanf(" %[^\n]",arr[i].titre);

        printf(" \t \t\tAutore: ");
        scanf(" %[^\n]",arr[i].auteur);
         
        printf(" \t \t\tPrix: ");
        scanf("%f",&arr[i].prix);

        printf(" \t \t\tQuantity : ");
        scanf("%d",&arr[i].quantite);
    }

}

void afficher(livre arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("\n============ book %d ===========\n",i+1);
        printf("\tTitre => %s\n",arr[i].titre);
          printf("\tAutour=> %s\n",arr[i].auteur);
            printf("\tPrix => %.2f\n",arr[i].prix);
              printf("\tQuantity => %d\n",arr[i].quantite);
    }
}

void rechercher(livre arr[],int size){
    int i;
    char T[20];
    printf("Enter title : ");
    scanf(" %[^\n]",T);
    int  verif=0;
    for(i=0;i<size;i++){
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

void modifie(livre arr[],int size){
    int i;
    char T[20];
    printf("\nFor Modify A Quantity :\n");
    printf("Enter Title: ");
    scanf(" %[^\n]",T);
     int  verif=0;
    for(i=0;i<size;i++){
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
void supprimer(livre arr[],int size){
     int i;
    char T[20];

    printf("Enter title : ");
    scanf(" %[^\n]",T);

    int  verif=0;
    for(i=0;i<size;i++){
        if(strcmp(arr[i].titre,T) == 0){
          verif =1;
          printf("\n========= You Are Delete This Book ===========\n");
          printf("\tTitre => %s\n",arr[i].titre);
          printf("\tAutour=> %s\n",arr[i].auteur);
          printf("\tPrix => %.2f\n",arr[i].prix);
          printf("\tQuantity => %d\n",arr[i].quantite);
          printf("__________________  DONE  _____________________\n");
        for (int j = i; j < size ;j++)
          {
             arr[j] = arr[j+1];
          }
        }     
    }
    
    if (verif != 1)
    {
       printf("===========  =  ==========\n");
       printf("\tNOT FOUND IT!");
       printf("___________________________\n");
    }

}
int total_livre(livre arr[],int size){
    int total =0 ;
    for(int i=0;i<size;i++){
        total += arr[i].quantite;
    }
    return total; 
}


int main(){

    livre livres[MAX];
    int size;
    int choix;
    do{
    printf("\n\t**********MENU DE MANIGEMENT*********\n");
    printf("\t1.Ajouter un livre au stock.\n");
    printf("\t2.Afficher tous les livres disponibles.\n");
    printf("\t3.Rechercher un livre par son titre.\n");
    printf("\t4.Mettre a jour la quantite d'un livre.\n");
    printf("\t5.Supprimer un livre du stock.\n");
    printf("\t6.Afficher le nombre total de livres en stock.\n");
    printf("\t7.Enter zero to Exite\n");
    
    printf("\nEnter le choix:");
    scanf("%d",&choix);
    switch(choix){

        case 1 : printf("How much book do you want to enter : ");
                 scanf("%d",&size);
                 printf("\n*************** START ****************\n");
                 ajouter(livres,size);
                 printf("\n----------------- END ----------------\n");
                 break;
               
        case 2 : printf("\n*************** START ****************\n");
                 afficher(livres,size);
                 printf("\n----------------- END ----------------\n");
                 break; 

        case 3 : printf("\n*************** START ****************\n");
                 rechercher(livres,size);
                 printf("\n----------------- END ----------------\n");
                 break;
                
        case 4 : printf("\n*************** START ****************\n");
                 modifie(livres,size);
                 printf("\n----------------- END ----------------\n");
                 break;
                
        case 5 : printf("\n*************** START ****************\n");
                 supprimer(livres,size);
                 size--;
                 printf("\n----------------- END ----------------\n");
                 break;
                  
        case 6 :  int all_book =  total_livre(livres,size);
                  printf("\n*************** START ****************\n");
                  printf(" totale of books : %d",all_book);
                  printf("\n----------------- END ----------------\n");
                  break;
                 
        case 0 : printf("Thanks for using our program!\n");
                 printf("\n----------------- END ----------------\n");
                 break;
                 
        default : printf("Invalid choice!\n");
                  break;
        
    }

    }while(choix != 0);
    



    return 0;
}
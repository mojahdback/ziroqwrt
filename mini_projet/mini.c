#include "header.h"
int main(){

    livre livres[MAX];
    int count =0;
    int size;
    int choix;
    int all_book;
    do{
    printf("\n\t**********MENU DE MANIGEMENT*********\n");
    printf("\t1.Ajouter un livre au stock.\n");
    printf("\t2.Afficher tous les livres disponibles.\n");
    printf("\t3.Rechercher un livre par ISBN.\n");
    printf("\t4.Mettre a jour la quantite d'un livre.\n");
    printf("\t5.Supprimer un livre du stock.\n");
    printf("\t6.Afficher le nombre total de livres en stock.\n");
    printf("\t7.sorting.\n");
    printf("\t7.Enter zero to Exite\n");
    
    printf("\nEnter le choix:");
    scanf("%d",&choix);
    switch(choix){

        case 1 : printf("How much book do you want to enter : ");
                 scanf("%d",&size);
                 printf("\n*************** START ****************\n");
                 ajouter(livres,size,&count);
                 printf("\n----------------- END ----------------\n");
                 break;
               
        case 2 : printf("\n*************** START ****************\n");
                 afficher(livres,count);
                 printf("\n----------------- END ----------------\n");
                 break; 

        case 3 : printf("\n*************** START ****************\n");
                 rechercher(livres,count);
                 printf("\n----------------- END ----------------\n");
                 break;
                
        case 4 : printf("\n*************** START ****************\n");
                 modifie(livres,count);
                 printf("\n----------------- END ----------------\n");
                 break;
                
        case 5 : printf("\n*************** START ****************\n");
                 supprimer(livres,&count);
                
                 printf("\n----------------- END ----------------\n");
                 break;
                  
        case 6 :  all_book =  total_livre(livres,count);
                  printf("\n*************** START ****************\n");
                  printf(" totale of books : %d",all_book);
                  printf("\n----------------- END ----------------\n");
                  break;
        case 7 :  printf("\n*************** START ****************\n");
                  sorting(livres,count);
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
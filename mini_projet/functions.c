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

        printf("\tEnter L'ISBN: ");
        scanf("%lld",&arr[*count].isbn);
    
            
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
              printf("\tL'ISBN => -%d\n",arr[i].isbn);
              
    }
              
    
}

void rechercher(livre arr[],int count){
    int i;
    int i1;
  
    sort_isbn(arr,count);
    printf("Enter L'ISBN : ");
    scanf("%d",&i1);
   
  
    int  verif=0;
    int mid;
    int low =0, too = count -1;
    i =0;
    while(low <= too){

          mid = (low + too) /2;
          if(arr[mid].isbn == i1 ){

              printf("\n============ Book Here ===========\n");
              printf("\tTitre => %s\n",arr[i].titre);
              printf("\tAutour=> %s\n",arr[i].auteur);
              printf("\tPrix => %.2f\n",arr[i].prix);
              printf("\tQuantity => %d\n",arr[i].quantite);
              printf("\tL'ISBN => %d\n",arr[mid].isbn);
              printf("************ FOUND IT **************\n");
              verif =1;
              i++;
              break;
            

          }
       
          else if((arr[mid].isbn < i1))
                  low = mid + 1;

          else 
              too = mid - 1;
             
            
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
       printf("\n___________________________\n");
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
       printf("\n___________________________\n");
    }

}
int total_livre(livre arr[],int count){
    int total =0 ;
    for(int i=0;i<count;i++){
        total += arr[i].quantite;
    }
    return total; 
}

void sort_isbn(livre arr[], int count){
    int i,j;
    livre temp;

    for(i=0;i<count -1;i++){
        for(j= 0;j<count -1-i;j++){
            if(arr[j].isbn> arr[j+1].isbn ){

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}

void sorting(livre arr[],int count ){
    int n;
    int i,j;
    printf("Do you want to sort by :\n");
    printf("choose number:\n");
    printf("1 : Character or 2 : Quantity :");
    scanf("%d",&n);
    if(n == 1){
          int b;
           printf("choose number:\n");
           printf("1 :  croissant  or 2 : decroissant :");
           scanf("%d",&b);
           if(b == 1)
           {
              livre temp;
              for(i=0;i<count -1 ;i++){
                for(j=0;j<count -i-1;j++){
                    if(arr[j].titre > arr[j+1].titre){
                         temp = arr[j];
                          arr[j] = arr[j+1];
                          arr[j+1] = temp;   
                    }       
                 }
               } 
            
            }   
     
            if(b != 1)
            {
                     livre temp;
                      for(i=0;i<count -1 ;i++){
                        for(j=0;j<count -i-1;j++){
                           if(arr[j].titre < arr[j+1].titre){
                          temp = arr[j];
                          arr[j] = arr[j+1];
                          arr[j+1] = temp;  
                         }
                        }
                      }
            }
    }
      
    if(n == 2){
            int b;
           printf("choose number:\n");
           printf("1 :  croissant  or 2 : decroissant :");
           scanf("%d",&b);
           if(b == 1)
           {
              livre temp;
              for(i=0;i<count -1 ;i++){
                for(j=0;j<count - i - 1;j++){
                    if(arr[j].quantite > arr[j+1].quantite){
                         temp = arr[j];
                          arr[j] = arr[j+1];
                          arr[j+1] = temp;   
                    }     
                }
               } 
      
            } 
            
            if(b != 1)
            {
                     livre temp;
                      for(i=0;i<count -1 ;i++){
                        for(j=0;j<count -i -1;j++){
                           if(arr[j].quantite < arr[j+1].quantite){
                          temp = arr[j];
                          arr[j] = arr[j+1];
                          arr[j+1] = temp;  
                         }
                        }
                      }
            }
               
    }
    afficher(arr,count); 
    
}
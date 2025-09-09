#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    char titre[20];
    char auteur[20];
    float prix;
    int quantite;
    long long isbn;

}livre;

   
     
void ajouter(livre arr[],int size,int *count);
void afficher(livre arr[],int count);
void rechercher(livre arr[],int count);
void modifie(livre arr[],int count);
void supprimer(livre arr[],int *count);
int total_livre(livre arr[],int count);
void sort_isbn(livre arr[], int count);
void sorting(livre arr[],int count);
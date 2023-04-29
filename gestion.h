#ifndef GEDTIONFDP2_H_INCLUDED
#define GEDTIONFDP2_H_INCLUDED
#include "structure.h"
#define max 100
#define max 100
int login (void);
void menu (void);
int verifentier(void);
void afficher(fiche f);
fiche ajouter();
int rechercher (int cnssrech ,int moisrech , int n ,fiche tab[max]);
int  recherchercnss (int cnssrech ,int i,fiche tab[max]);
void supprimer(fiche tab[],int *n);
int salairesMois(fiche tab[max],int n,int moisrech);
int salairesemployer(fiche tab[max],int n,int cnssrech );
void modifier(fiche *f,fiche tab[],int n);


#endif // GEDTIONFDP2_H_INCLUDED

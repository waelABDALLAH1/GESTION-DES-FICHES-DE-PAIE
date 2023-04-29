#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"gestion.h"
#define max 100
#include <time.h>
#include<ctype.h>
#include <conio.h>



int login()
{
  char username[20];
  char userpwd[9]; // for storing password
  int i;

  printf("Entrer votre nom d'utilisateur : ");
  scanf("%s",username);

  printf("Entrer votre mot de passe : ");

  for(i=0;i<8;i++)
  {
   userpwd[i]=getch();
   printf("*");
  }
  userpwd[i]='\0';

/*------------------*/

  printf("\n\nAppuyer sur une touche pour continuer :");
  getch();

 if((strcmp(username,"0000")==0) && (strcmp(userpwd,"00000000")==0))
 {
  printf("\n\nconnexion avec succes \n");
  return 1 ;
 }else
 {
  printf("\n\n nom d'utilisateur ou mot de passe incorrect\n");
 }
 return 0;
}

fiche ajouter()
  { fiche f;
    int i=0;
    printf("Donner le numero cnss de l'emloyer : \n");
    f.e.cnss=verifentier();
    printf("Donner le nom de l'emloyer  : \n");
    do{
         gets(f.e.nom);
         for(i=0; i<strlen(f.e.nom);i++)
  	       {
  	 	     if(isalpha(f.e.nom[i])==0)
             {
                if(isspace(f.e.nom[i])==0){
                  i=strlen(f.e.nom)+1;
                  printf("redonner le nom de l'emloyer  : \n");
                }
           }
      } }while(i>strlen(f.e.nom) || i==0);
      i=0;
     printf("Donner le prenom de l'emloyer  : \n");
       do{
         gets(f.e.prenom);
         for(i=0; i<strlen(f.e.prenom);i++)
  	       {
  	 	     if(isalpha(f.e.prenom[i])==0){
                if(isspace(f.e.prenom[i])==0){
                   i=strlen(f.e.prenom)+1;
                   printf("Redonner le prenom de l'emloyer  : \n");
                }
  	 	     }
           }
      }while(i>strlen(f.e.prenom) || i==0);

    do{
        printf("Donner le grade de l'emloyer (PDG,DG,directeur,employer) : \n");
        gets(f.e.grade);
     }while(!(strcmp(f.e.grade,"PDG")==0 || strcmp(f.e.grade,"DG")==0 || strcmp(f.e.grade,"directeur")==0 || strcmp(f.e.grade,"employer")==0));


         printf("Donner le numero de la fiche de paie  a ajouter : \n");
         f.num=verifentier();

         printf("Donner le salaire: \n");
         f.salaire=verifentier();
         do{
         printf("Donner le mois : \n");
         scanf("%d",&f.mois);
         }while(f.mois<1 || f.mois>12);
         printf("------------------------------------------------------------------- \n") ;
         return f;
  }


void afficher(fiche f)
{
   printf("numero: %d | salaire:%d |mois:%d | cnss:%d | nom:%s |prenom:%s |grade:%s\n",f.num,f.salaire,f.mois,f.e.cnss,f.e.nom,f.e.prenom,f.e.grade);
}

int rechercher (int cnssrech ,int moisrech , int n ,fiche tab[])
{   int i,j=0;
    for(i=0;i<n;i++)
     {
         if((tab[i].e.cnss==cnssrech) && (tab[i].mois==moisrech))
         {
             afficher(tab[i]);
             return j;
         }
     }
     return j+1;
}


int  recherchercnss (int cnssrech ,int i,fiche tab[])
{    int j=0;
      if(tab[i].e.cnss==cnssrech)
        return j+1;
      return j;
}

void supprimer(fiche tab[],int *n)
{  int f;
   int i=0,indice;
   printf("Donner le num de la fiche %c supprimer",133);
   scanf("%d",&f);
    while(tab[i].num!=f && i<*n)
       i++;
   if(i==*n)
       printf("\n Cette fiche n'existe pas\n");

   else{
       indice=i;
      for(i=indice;i<*n-1;i++)
        tab[i]=tab[i+1];
      --*n;
      }
}

int salairesMois(fiche tab[max],int n,int moisrech)
  {int s=0;
      for(int i=0;i<n;i++)
      {
          if(tab[i].mois==moisrech)
            s+=tab[i].salaire;
      }
      return s;
  }


int salairesemployer(fiche tab[max],int n,int cnssrech )
{
    int s=0;
      for(int i=0;i<n;i++)
      {
          if(tab[i].e.cnss==cnssrech)
            s+=tab[i].salaire;
      }
      return s;
}


void modifier(fiche *f,fiche tab[],int n)
{  int reponse=0,j,x,k;char prenom[20];char nom[20];
   fiche f1;
   f1.num=f->num;
   f1.mois=f->mois;
   f1.salaire=f->salaire;
   f1.e.cnss=f->e.cnss;
   strcpy(f1.e.grade,f->e.grade);
   strcpy(f1.e.nom,f->e.nom);
   strcpy(f1.e.prenom,f->e.prenom);
    while(reponse!=7){
         printf("Quelle info a  changer (1:salaire | 2:mois | 3:nom | 4:prenom | 5:grade |6:num cnss | 7:aucun) : ");
         reponse=verifentier();
        switch(reponse){
        case 1:
            printf("\n Donner le nouveau salaire : ");
            f1.salaire=verifentier();
            break;
        case 2:
            printf("\n Donner le nouveau mois : ");
            f1.mois=verifentier();
            break;
        case 3:
            printf("\n Donner le nouveau nom : ");
            j=0;
            do{
              gets(nom);
              strcpy(f1.e.nom,nom);

              for(j=0; j<strlen(f1.e.nom);j++){
  	 	        if(isalpha(f1.e.nom[j])==0){
                   if(isspace(f1.e.nom[j])==0){
                      j=strlen(f1.e.nom)+1;
                      printf("Redonner le nom de l'employer  : \n");
                   }
  	 	        }
               }
             }while(j>strlen(f1.e.nom) || j==0);
            break;
        case 4:
            printf("\n Donner le nouveau prenom : ");
            j=0;
            do{
              gets(prenom);
              strcpy(f1.e.prenom,prenom);
              for(j=0; j<strlen(f1.e.prenom);j++){
  	 	        if(isalpha(f1.e.prenom[j])==0){
                   if(isspace(f1.e.prenom[j])==0){
                      j=strlen(f1.e.prenom)+1;
                      printf("Redonner le prenom de l'employer  : \n");
                   }
  	 	        }
              }
             }while(j>strlen(f1.e.prenom) || j==0);
           break;
         case 5:
                do{
                 printf("\n Donner le nouveau grade(PDG,DG,directeur,employer) :\n");
                 gets(f1.e.grade);
                }while(!(strcmp(f1.e.grade,"PDG")==0 || strcmp(f1.e.grade,"DG")==0 || strcmp(f1.e.grade,"directeur")==0 || strcmp(f1.e.grade,"employer")==0));
            break;
         case 6:
            printf("Donner le nouveu numero de cnss \n");
             f1.e.cnss=verifentier();
             break;
         case 7:
            break ;
          default:
                printf("\nEntree invalide\n");
                break;

      }
    }
      x=0;
    for(j=0;j<n;j++){

        if(f1.num!=tab[j].num){
            if ((tab[j].e.cnss==f1.e.cnss) && (tab[j].mois==f1.mois))
                  j=n+1;
            for(k=0;k<n;k++){
              if(f1.num!=tab[j].num){
                if(f1.e.cnss==tab[k].e.cnss){
                  if(strcmp(tab[k].e.nom,f1.e.nom)!=0 || strcmp(tab[k].e.prenom,f1.e.prenom)!=0){
                    x++;
                    k=n;
                  }
                }
              }
            }
        }
    }
    if((j==n) && ( x==0)){ //modification
        f->mois=f1.mois;
        f->salaire=f1.salaire;
        f->e.cnss=f1.e.cnss;
        strcpy(f->e.grade,f1.e.grade);
        strcpy(f->e.nom,f1.e.nom);
        strcpy(f->e.prenom,f1.e.prenom);
        printf("\n La fiche est modifie\n");
      }
    else
       printf("Cette modification est impossible a satisfaire\n ");

}

int extract( char *chaine, char *sousChaine)
{
  int i=0;
  //récupérer la longueur de la chaîne
  int length = strlen(chaine);
  for( i =0; i <length-1; i++){
    sousChaine[i] = chaine[i];
  }
  return length;
}






void menu (void)
{
   fiche tab[max];
   fiche f;
   char ch[200],sousCh[200];
     int choix,n=0,j,cnssrech,moisrech,i=0;
      int zz,x,k;int g;

     FILE * file=fopen("data.txt","r+"); //w:write ;
     if(file==NULL){
        printf("erreur");
     }
    while(fgets(ch,200,file)!=NULL){
       i++;
       g=extract(ch,sousCh);

       if(i==1){
         f.e.cnss=atoi(sousCh);
       }
       if(i==2){
          for(j=0;j<g-1;j++)
          {f.e.nom[j]=sousCh[j];


          }f.e.nom[g-1]='\0';

       }
       if(i==3){
        for(j=0;j<g-1;j++)
            f.e.prenom[j]=sousCh[j];
        f.e.prenom[g-1]='\0';
       }
       if(i==4){
        for(j=0;j<g-1;j++)
            f.e.grade[j]=sousCh[j];
        f.e.grade[g-1]='\0';
       }
        if(i==5){
          sousCh[g-1]='\0';
          f.num=atoi(sousCh);
        }

        if(i==6){
          sousCh[g-1]='\0';
          f.salaire=atoi(sousCh);
        }
        if(i==7){
          sousCh[g-1]='\0';
          f.mois=atoi(sousCh);
          tab[n]=f;
          n++;
          i=0;
        }
}
     fclose(file);
    while(1)
        {

        time_t timestamp=time(NULL);
        struct tm * timeInfos = localtime(&timestamp);
        printf("\n                                          ********   ©   Project done by WAEL ABDALLAH & AMINE ZIADI    ©   ************************************************");
        printf("\n                                          ******************************************************************************************************************");
        printf("\n                                          ***                                                    ENIT        ***********************************************");
        printf("\n                                          ***                Menu                                            ***********************************************");
        printf("\n                                          ***                                             le : %d/%d/%d     **********************************************",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ******************************************************************************************************************");
        printf("\n                                          1) Ajouter une fiche de paie \n");
        printf("\n                                          2) Rechercher la fiche de paie d'un employer identifie par Num CNSS, pour un mois donn%c\n",130);
        printf("\n                                          3) Rechercher toutes les fiche de paie d'un employer identifi%c par son Num CNSS\n",130);
        printf("\n                                          4) supprimer une fiche de paie\n");
        printf("\n                                          5) Calculer le montant total de tous les salaires d'un mois donn%c\n",130);
        printf("\n                                          6) Calculer le montant total de tous les salaires d'un employer donn%c (Num CNSS)\n",130);
        printf("\n                                          7) Changer une information dans une fiche\n");
        printf("\n                                          8) Afficher\n");
        printf("\n                                          9) Quitter\n");
        printf("\n                                          Choisir une option ");
          choix=verifentier();


 switch(choix)
  {

         case 1: // ajouter une fiche de paie
             system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   Ajouter une fiche de paie  ***************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");

 do{
        i=0;
        f=ajouter();
       for(j=0;j<n;j++)  //verifie chaque fiche est unique
       {
         if ((tab[j].num==f.num) || ((tab[j].e.cnss==f.e.cnss) && (tab[j].mois==f.mois)))
         {
            printf("Cette fiche existe deja OU cet employer a deja une fiche de paie pour ce mois\n");
            j=n+1;
         }
       }
        x=0;
            for(k=0;k<n;k++){     //verifie chaque num de cnss a toujours les memes nom et prenom
                if(f.e.cnss==tab[k].e.cnss){
                  if(strcmp(tab[k].e.nom,f.e.nom)!=0 || strcmp(tab[k].e.prenom,f.e.prenom)!=0){
                    x++;
                    k=n;
                  }
                }
            }
       if (j==n && x==0)
        {tab[n]=f;
        n+=1;}
         else{printf("Veuillez ressaisir cette fiche \n");
                         i=1;
            }
        }while(i==1);
        for(i=0;i<n;i++)
          {
           afficher(tab[i]);
          }


printf("\nTapez 1 pour rentrer au menu : \n");
             zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }
        case 2: // recherche 1
            system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   RECHERCHE ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
           printf("Num cnss pourrechercher: ");
           cnssrech=verifentier();
           printf("mois pour rechercher: ");
           moisrech=verifentier();
           j=rechercher(cnssrech , moisrech , n ,tab);
          if(j==1)
          {printf("Aucune fiche trouver");}
        printf("\nTapez 1 pour rentrer au menu : \n");
              zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }


        case 3:  // recherche 2
             system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   RECHERCHE ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
             printf("Num cnss pour rechercher: ");
             cnssrech=verifentier();
               j=0;
            for(i=0;i<n;i++)
                {
                    if (recherchercnss(cnssrech,i,tab))
                           {
                               afficher (tab[i]);
                                j+=1;
                           }
                }
             if(j==0)
               printf("Cette employer n'existe pas");
  printf("\nTapez 1 pour rentrer au menu : \n");
  zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }

          case 4: //supprimer
               system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   SUPPRIMER ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
                   j=n;
                   supprimer(tab,&n);
                   if(j==n)
                    {for(i=0;i<n;i++)
                       afficher (tab[i]);
                    }
                    else
                        printf("La fiche a %ct%c supprimer",130,130);
	     printf("\nTapez 1 pour rentrer au menu : \n");
	       zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }

          case 5: //somme 1
               system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   SOMME ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
            printf("Donner le mois\n");
            scanf("%d",&moisrech);
            printf("\n Le totale des salaires est :%d\n",salairesMois(tab,n,moisrech));
           printf("\nTapez 1 pour rentrer au menu : \n");
             zz=verifentier();

            if(zz==1)
            {
                system("CLS");
                 break;

            }

        case 6: // somme 2
             system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************  SOMME    ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
           printf("Donner le num cnss\n");
             cnssrech=verifentier();
           if(salairesemployer(tab,n,cnssrech)==0)
            printf("cette employer ne se trouve pas dans la liste \n");
           else
           printf("La somme est :%d",salairesemployer(tab,n,cnssrech));
printf("\nTapez 1 pour rentrer au menu : \n");
        zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }

        case 7: // modification
             system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   MODIFICATION ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
             printf("Taper le num de la fiche %c modifier : ",133);
               j=verifentier();
            for(i=0;i<n;i++)
              {
                  if (tab[i].num==j)
                    {
                       modifier(&tab[i],tab,n);
                       i=n+1;
                     }
              }
            if (i==n)
              printf("\n Aucune fiche trouvee\n" );
         printf("\nTapez 1 pour rentrer au menu : \n");
              zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }
        case 8: // afficher
             system("CLS");
              printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   AFFICHAGE  ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
     printf("\n");
            if (n==0)
                printf("Aucune fiche existe");
            else
            {
               for(i=0;i<n;i++)
                 afficher (tab[i]);
            }
           printf("\nTapez 1 pour rentrer au menu : \n");
             zz=verifentier();
            if(zz==1)
            {
                system("CLS");
                 break;

            }


    case 9:// sortir
        system("CLS");

        printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   SORTIR ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
        printf("\n");
        printf("\nTapez un chiffre pour quitter: \n");
          getch();

            file=fopen("data.txt","w"); //w:write ;
            for (i=0;i<n;i++)
                 fprintf(file,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n",tab[i].e.cnss,tab[i].e.nom,tab[i].e.prenom,tab[i].e.grade,tab[i].num,tab[i].salaire,tab[i].mois);
            fclose(file) ;
            exit(0);
         break;
        default:
            printf("\nEntree invalide");
            break;}}}


 int verifentier (void)
{
   char chaine[50];
   int indice;
   int value;
   int correct;
   do
   {
       correct = 1;
       indice = 0;
       scanf("%s",chaine);
       while(chaine[indice] != '\0')
       {
          if (chaine[indice] < '0' ||chaine[indice] > '9')
               correct = 0;
          indice++;
       }
       if (correct == 0)
           printf("erreur, recommencer donnner un entier :\n");
    }while( correct == 0);
    value = atoi(chaine);
    return value ;
};

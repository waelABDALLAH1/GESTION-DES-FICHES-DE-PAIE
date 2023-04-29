#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"
#include <time.h>
#define max 100
#include <string.h>
int main()
{
    system("COLOR 0A");
    int option;
    int l,j;

        time_t timestamp=time(NULL);
        struct tm * timeInfos = localtime(&timestamp);
        printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
        printf("\n                                          ***********************************************   BIENVENUE ********************************************************");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          **                                                                                                                **");
        printf("\n                                          ********************************************************************************************************************\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                                              Taper 1 pour vous connecter \n");
        scanf("%d",&option);
        getchar();
        system("CLS");
        if(option == 1){
        	 printf("\n                                          *****************************************  GESTION DE FICHE DE PAIE ************************************************");
             printf("\n                                          **                                                                                                                **");
             printf("\n                                          **                                                                                         Date : %d/%d/%d      **",timeInfos->tm_mday,timeInfos->tm_mon+1 ,timeInfos->tm_year+1900    );
             printf("\n                                          ***********************************************   BIENVENUE ********************************************************");
             printf("\n                                          **                                                                                                                **");
             printf("\n                                          **                                                                                                                **");
             printf("\n                                          **                                                 CONNEXION                                                      **");
             printf("\n                                          ********************************************************************************************************************\n");

             l=0;
             j=0;
             while(l==0 && j<3){
                 l=login();
                 j++;
             }
             if (l==1){
                system("CLS");
                menu();
             }
             else
                  printf("\n                                      systeme bloquee                              \n");
}
return 0;
}



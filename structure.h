#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};
typedef struct{
   int cnss;
   char nom[10];
   char prenom[10];
   char grade[20];
}employer;
typedef struct{
  int num;
  int salaire;
  int mois;
  employer e;
}fiche;



#endif // STRUCTURE_H_INCLUDED

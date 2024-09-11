#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct departement
{
    char name[10];
};
struct Etudiant
{
    int id;
    char nom[30];
    char prenom[30];
    char datenaissance[30];
    struct departement dep;
    float note;
};
int l = 0;
struct Etudiant liste[50];

void ajouter()
{
    int choix;
    printf("entrer les information  etudiant : \n");
    printf("entrer le nom d'etudiant : \n");
    scanf(" %[^\n]", liste[l].nom);
    printf("entrer le prenom d'etudiant : \n");
    scanf(" %[^\n]", liste[l].prenom);
    printf("entrer la date naissance : \n");
    scanf(" %[^\n]", liste[l].datenaissance);
    printf("entrer le departement d'etudiant : \n");
    printf("taper 1 pour  le departement MATH : \n");
    printf("entrer 2 le departement PHISIC : \n");
    printf("entrer 3 le departement INFO : \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        strcpy(liste[l].dep.name, "math");
        break;
    case 2:
        strcpy(liste[l].dep.name, "phisic");
        break;
    case 3:
        strcpy(liste[l].dep.name, "info");
        break;
    default:
        printf("choix introvable \n");
    }
    printf("entrer la note d'etudiant  : \n");
    scanf(" %f", &liste[l].note);

   liste[l].id = l + 1;
     l++;

}

void afficher()
{
    for (int i = 0; i < l; i++)
    {
        printf("******************************************* \n");
        printf("les information  etudiant  : \n");
        printf("ID d'etudiant : %d \n", liste[i].id);
        printf("le nom d'etudiant : %s \n", liste[i].nom);
        printf("le prenom d'etudiant : %s \n", liste[i].prenom);
        printf("la date naissance d'etudiant : %s \n", liste[i].datenaissance);
        printf("le departement d'etudiant : %s \n", liste[i].dep.name);
        printf("la note d'etudiant : %.2f \n", liste[i].note);
        printf("******************************************* \n");
    }
}

void recherche()
{
    char nom1[30];
    char dep1[30];
    int choix;
    printf("taper 1 pour chercher un etudiant par son nom : \n");
    printf("taper 2 pour chercher la liste des etudiant par un departement : \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("enter le nom d etudiant rechercher \n");
        scanf(" %[^\n]", nom1);
        for (int i = 0; i < l; i++)
        {
            if (strcmp(liste[i].nom, nom1) == 0)
            {
                printf("les information  etudiant rechercher : \n");
                printf("le nom d'etudiant : %s \n", liste[i].nom);
                printf("le prenom d'etudiant : %s \n", liste[i].prenom);
                printf("la date naissance d'etudiant : %s \n", liste[i].datenaissance);
                printf("le departement d'etudiant : %s \n", liste[i].dep.name);
                printf("la note d'etudiant : %.2f \n", liste[i].note);
            }
        }
        break;
    case 2:
        printf("enter le departement d etudiant rechercher (math ou phisic ou info) : \n");
        scanf(" %[^\n]", dep1);
        for (int i = 0; i < l; i++)
        {
            if (strcmp(liste[i].dep.name, dep1) == 0)
            {
                printf("le nom d'etudiant :   %s ", liste[i].nom);
                printf("le prenom d'etudiant : %s \n", liste[i].prenom);
            }
        }
            break;
        default:
            printf("choix introvable \n");
            break;

    }
}

void Statistiques()
{
    struct Etudiant copie[50];
    char depp[10];
    int choix;
int countmath = 0;
    int countphisic = 0;
    int countinfo = 0;
    float seuil;
    printf("taper 1 : Afficher le nombre total d'etudiants inscrits.  \n");
    printf("taper 2 : Afficher le nombre d'etudiants dans chaque departement. \n");
    printf("taper 3 : Afficher les etudiants ayant une moyenne generale superieure a un certain seuil. \n");
    printf("taper 4 : Afficher les 3 etudiants ayant les meilleures notes.  \n");
    printf("taper 5 : Afficher le nombre d'etudiants ayant reussi dans chaque departement. \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("le nombre total est : %d  \n", l);
        break;
    case 2:

        for (int i = 0; i < l; i++)
        {

            if (strcmp(liste[i].dep.name, "math") == 0)
            {

                countmath++;

            }
            else if (strcmp(liste[i].dep.name,"phisic") == 0)
            {

                countphisic++;
            }
            else if (strcmp(liste[i].dep.name, "info") == 0)
            {

                countinfo++;
            }
             }

         printf("le nombre d etudiant dans departement math est : %d \n", countmath);
         printf("le nombre d etudiant dans departement info est : %d  \n", countinfo);
         printf("le nombre d etudiant dans departement phisic est : %d \n", countphisic);
        break;
    case 3:
        printf("enter le seuil : ");
        scanf(" %f", &seuil);
        for (int i = 0; i < l; i++)
        {
            if (liste[i].note >= seuil)
            {
                printf("le nom d'etudiant : %s ", liste[i].nom);
                printf("le prenom d'etudiant : %s \n", liste[i].prenom);
            }
        }
        break;
    case 4:

        for (int i = 0; i < l; i++)
        {
            copie[i] = liste[i];
        }
        for (int i = 0; i < l; i++)
        {
            if (copie[i].note < copie[i + 1].note)
            {
                struct Etudiant tmp;
                tmp = copie[i + 1];
                copie[i + 1] = copie[i];
                copie[i] = tmp;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            printf("le nom d'etudiant : %s \n", copie[i].nom);
            printf("le prenom d'etudiant : %s \n", copie[i].prenom);
            printf("le departement d'etudiant : %s \n", copie[i].dep.name);
            printf("la note  d'etudiant : %.2f \n", copie[i].note);
        }
        break;
    case 5:

        for (int i = 0; i < l; i++)
        {
            if (liste[i].note >= 10)
            {
                printf("le nom d'etudiant : %s ", liste[i].nom);
                printf("le prenom d'etudiant : %s \n", liste[i].prenom);
            }
        }
        break;
    }
}
void modifier()
{
    int id2;
    char newnom[50];
    char newprenom[50];
    char newdatenai[50];
    float newnote;
    printf("entrer id du etudiant que vous voullez modifier : \n");
    scanf("%d", &id2);
    printf("entrer le neauvau nom : \n");
    scanf(" %s",newnom);
    printf("entrer le neauvau prenom : \n");
    scanf(" %s",newprenom);
    printf("entrer la nouvelle date naissance : \n");
    scanf(" %s", newdatenai);
    printf("entrer la nouvelle note : \n");
    scanf("%f",&newnote);
    for (int i = 0; i < l; i++)
    {
      if (liste[i].id == id2)
        {
            strcpy(liste[i].nom, newnom);
            strcpy(liste[i].prenom, newprenom);
            strcpy(liste[i].datenaissance, newdatenai);
            liste[i].note = newnote;
        }

    }
}


void suprimer() {
    int id3;
    printf("entrer id du etudiant que vous voulez supprimer : ");
    scanf("%d", &id3);

    int found = 0;  // Flag to check if student is found
    for (int i = 0; i < l; i++) {
        if (liste[i].id == id3) {
            found = 1;
            for (int j = i; j < l - 1; j++) {
                liste[j] = liste[j + 1];  // Shift students left
            }
            l--;  // Decrease the count of students
            break;  // Exit loop after removing student
        }
    }

    if (!found) {
        printf("Etudiant avec l'ID %d non trouvé.\n", id3);
    }
}

void moyenne()
{
    char dep2[50];
    float total = 0;
    float M;
    int comp=0;
    printf("enter le departement d etudiant  (math ou phisic ou info) : \n");
    scanf("%s",dep2);
    for (int i = 0; i < l; i++)
    {
        if (strcmp(liste[i].dep.name, dep2) == 0)
        {
            comp++;
            total += liste[i].note;
        }
}
   if (comp > 0)
        {
            M = total / comp;
            printf("la moyenne generale de cette departement est : %.2f  \n", M);
        }
        else
            printf("operation impossible");
    }

void trier()
{
    struct Etudiant copie2[50];
     struct Etudiant copie1[50];
    struct Etudiant T;
    struct Etudiant T1;
    int choix;
    printf("taper 1 pour trier alphabetique les etudiant par leur nom : \n");
    printf("taper 2 pour trier les etudiant par note general : \n");
    printf("taper 3 pour trier les etudiant par leur status de reussite ( moyennne >= 10) : \n");
    scanf("%d", &choix);
    for(int i = 0 ;i< l ; i++){
        copie1[i] = liste[i];
    }
     for(int i = 0 ;i< l ; i++){
        copie2[i] = liste[i];
    }

    switch (choix)
    {
    case 1:
        for (int j = 0; j < l-1; j++)
        {

            for (int i = 0; i < l-1-j ; i++)
            {
                if (strcmp( copie1[i].nom,  copie1[i+1].nom) > 0)
                {
                      T =  copie1[i];
                     copie1[i] =  copie1[i + 1];
                    copie1[i+1] = T;
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            printf("les information  etudiant  : \n");
            printf("le nom d'etudiant : %s \n",  copie1[i].nom);
            printf("le prenom d'etudiant : %s \n",  copie1[i].prenom);
            printf("la date naissance d'etudiant : %s \n",  copie1[i].datenaissance);
            printf("le departement d'etudiant : %s \n",  copie1[i].dep.name);
            printf("la note d'etudiant : %.2f \n",  copie1[i].note);
            printf("******************************************* \n");
        }
        break;

    case 2:

        for (int j= 0; j< l-1; j++){
                for (int i= 0; i< l; i++)
                if (copie2[i].note>copie2[i+1].note){

                       T1 = copie2[i];
                    copie2[i] = copie2[i+1];
                    copie2[i+1] = T1;
                     }}
         for (int i = 0; i < l; i++)
        {
            printf("les information  etudiant  : \n");
            printf("le nom d'etudiant : %s \n", copie2[i].nom);
            printf("le prenom d'etudiant : %s \n", copie2[i].prenom);
            printf("la date naissance d'etudiant : %s \n", copie2[i].datenaissance);
            printf("le departement d'etudiant : %s \n", copie2[i].dep.name);
            printf("la note d'etudiant : %.2f \n", copie2[i].note);
             printf("******************************************* \n");
        }
        break;
    case 3:
    for (int j= 0; j< l-1; j++){
                for (int i= 0; i< l; i++)
                if (copie2[i].note>copie2[i+1].note){

                       T1 = copie2[i];
                    copie2[i] = copie2[i+1];
                    copie2[i+1] = T1;
                     }}
         for (int i = 0; i < l; i++)
        {
            if (copie2[i].note>10)
            {
                printf("les information  etudiant  : \n");
            printf("le nom d'etudiant : %s \n", copie2[i].nom);
            printf("le prenom d'etudiant : %s \n", copie2[i].prenom);
            printf("la date naissance d'etudiant : %s \n", copie2[i].datenaissance);
            printf("le departement d'etudiant : %s \n", copie2[i].dep.name);
            printf("la note d'etudiant : %.2f \n", copie2[i].note);
             printf("******************************************* \n");
            }
            
        }
        break;
    }
}

void menu(){
    int choix;
    while (1)
    {
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\MENU\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
        printf("taper 1 pour ajouter un etudiant : \n");
        printf("taper 2 pour afficher les etudiant : \n");
        printf("taper 3 pour modifier  un etudiant par son id: \n");
        printf("taper 4 pour suprimer un etudiant : \n");
        printf("taper 5 pour calculer la moyenne generale de chaque departement (math ou phisic ou info) : \n");
        printf("taper 6 pour statistiques : \n");
        printf("taper 7 pour rechercher un etudiant par : \n");
        printf("taper 8 pour trier un etudiant par : \n");
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
        scanf("%d", &choix);

        switch (choix)
        {

        case 1:
            ajouter();
            break;
        case 2:
            afficher();
            break;
        case 3:
            modifier();
            break;
        case 4:
            suprimer();
            break;
        case 5:
            moyenne();
            break;
        case 6:
            Statistiques();
            break;
        case 7:
            recherche();
            break;
        case 8:
            trier();
            break;
        default:
            printf("choix introvable");
        }
    }
}

int main() {
    
    strcpy(liste[0].nom, "Alice");
    strcpy(liste[0].prenom, "Johnson");
    strcpy(liste[0].datenaissance, "2000-01-15");
    strcpy(liste[0].dep.name, "math");
    liste[0].note = 12.5;
    liste[0].id = ++l;

    strcpy(liste[1].nom, "Bob");
    strcpy(liste[1].prenom, "Smith");
    strcpy(liste[1].datenaissance, "1999-11-20");
    strcpy(liste[1].dep.name, "phisic");
    liste[1].note = 14.0;
    liste[1].id = ++l;

    strcpy(liste[2].nom, "Carol");
    strcpy(liste[2].prenom, "Williams");
    strcpy(liste[2].datenaissance, "2001-03-25");
    strcpy(liste[2].dep.name, "info");
    liste[2].note = 16.5;
    liste[2].id = ++l;

    strcpy(liste[3].nom, "David");
    strcpy(liste[3].prenom, "Brown");
    strcpy(liste[3].datenaissance, "2000-07-30");
    strcpy(liste[3].dep.name, "math");
    liste[3].note = 10.0;
    liste[3].id = ++l;

    strcpy(liste[4].nom, "Eve");
    strcpy(liste[4].prenom, "Davis");
    strcpy(liste[4].datenaissance, "1998-05-15");
    strcpy(liste[4].dep.name, "phisic");
    liste[4].note = 11.5;
    liste[4].id = ++l;

    strcpy(liste[5].nom, "Frank");
    strcpy(liste[5].prenom, "Miller");
    strcpy(liste[5].datenaissance, "2002-06-18");
    strcpy(liste[5].dep.name, "info");
    liste[5].note = 9.0;
    liste[5].id = ++l;

    strcpy(liste[6].nom, "Grace");
    strcpy(liste[6].prenom, "Wilson");
    strcpy(liste[6].datenaissance, "1997-12-05");
    strcpy(liste[6].dep.name, "math");
    liste[6].note = 15.5;
    liste[6].id = ++l;

    strcpy(liste[7].nom, "Hank");
    strcpy(liste[7].prenom, "Moore");
    strcpy(liste[7].datenaissance, "1999-09-22");
    strcpy(liste[7].dep.name, "phisic");
    liste[7].note = 13.0;
    liste[7].id = ++l;

    strcpy(liste[8].nom, "Ivy");
    strcpy(liste[8].prenom, "Taylor");
    strcpy(liste[8].datenaissance, "2000-02-11");
    strcpy(liste[8].dep.name, "info");
    liste[8].note = 17.0;
    liste[8].id = ++l;

    strcpy(liste[9].nom, "Jack");
    strcpy(liste[9].prenom, "Anderson");
    strcpy(liste[9].datenaissance, "1998-10-09");
    strcpy(liste[9].dep.name, "math");
    liste[9].note = 8.5;
    liste[9].id = ++l;

    menu();
    return 0;
}


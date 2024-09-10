#include<stdio.h>
#include<string.h>
#define MAX_ETUD
// structure d'une date de naissance
typedef struct{
    int jour,mois,annee;
}dateN;

// structure d'une étudiant
typedef struct{
    int num;
    char nom[20],prenom[20];
    dateN d;
    char dept[30];
    float moy_gen;
}etudiant;

// déclaration d'une tableau(université) des étudiants.
    etudiant tab[MAX_ETUD];
    int nombre=0;

// vérifier si une annee est bissextile
int estBissextile(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

// Vérifier si un date est valide 
int dateValide(dateN date) {
    if (date.mois < 1 || date.mois > 12) 
        return 0;
    if (date.jour < 1) 
        return 0;

    int joursfinMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (estBissextile(date.annee)) 
        joursfinMois[1] = 29;

    if (date.jour > joursfinMois[date.mois - 1])
         return 0;
    return 1;
}

// calculer l'age de l'érudiant
int calculerAge(dateN date, dateN date_en_cours) {
    int age = date_en_cours.annee - date.annee;
    if (date_en_cours.mois < date.mois || (date_en_cours.mois == date.mois && date_en_cours.jour < date.jour)) {
        age--;
    }
    return age;
}

//fonction test si la date valide et que  l'étudiant a plus que 17 
int estEtudiantValide(etudiant e, dateN dateActuelle) {
    if (!dateValide(e.d)) return 0;
    if (calculerAge(e.d, dateActuelle) <= 17)
    {
       return 0; 
    }else
        return 1;
}

// Ajouter un étudiant "simple"
void Ajouter(){
    tab[nombre].num=nombre+1;
    int i;
    printf("Entrez le Nom de l'étudiant :");
    getchar();
    gets(tab[nombre].nom);
    printf("Entrez le Prénom de l'étudiant :");
    getchar();
    gets(tab[nombre].prenom);
    printf("Le département :");
    printf("1.Math / Info \n");
    printf("2.Physique / Chimie \n");
    printf("3.Sciences Sociales \n");
    printf("4.Sciences Humaines \n");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        strcpy(tab[nombre].dept,"Math / Info");
        break;
    case 2:
        strcpy(tab[nombre].dept,"Physique / Chimie");
        break;
    case 3:
        strcpy(tab[nombre].dept,"Sciences Sociales");
        break;
    case 4:
        strcpy(tab[nombre].dept,"Sciences Humaines");
        break;
    }
    printf("Entrez La date d'Aujourd'hui (jj mm aaaa):");
     do
        {
            printf("Entrez la deadline (jj mm aaaa) : ");
            scanf("%d %d %d",&tab[nombre].d.jour,&tab[nombre].d.mois,&tab[nombre].d.annee);

        if (!dateValidee(tab[nombre].d.jour, tab[nombre].d.mois, tab[nombre].d.annee)) {
            printf("Date invalide ! La tâche ne peut pas être créée.\n");
        }
        }while(!dateValidee(tab[nombre].d.jour,tab[nombre].d.mois,tab[nombre].d.annee));
}
// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n********* Menu Principal *********\n");
    printf("1. Ajouter des étudiants\n");
    printf("2. Modifier ou supprimer une étudiant\n");
    printf("3. Afficher les détails d'un étudiant\n");
    printf("4. Calculer la moyenne générale\n");
    printf("5. Afficher les statistiques\n");
    printf("6. Rechercher un étudiant\n");
    printf("7. Trier un étudiant par\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
}
void main(){
int choix, id, jour, mois, annee,ch1, ch4, md;
    char titre[100];
    do {
        afficherMenu();
        scanf("%d",&choix);
        
        switch (choix) {
            case 1:
                printf("*******Menu d'Ajout*******\n");
                printf("1. Ajout Simple\n");
                printf("2. Ajout Multiple.\n");
                printf("Votre choix :");
                printf("%d",&ch1);
                creerTache();
                break;
            
            case 2:
            printf("*******Menu d'Affichage*******\n");
                printf("1. Affichage Simple\n");
                printf("2. Affichage Trier des tâches par deadline.\n");
                printf("3. Trier les tâches par ordre alphabétique.\n");
                printf("4. Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
                
                printf("Votre choix : ");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    afficherToutesTaches();
                    break;
                case 2:
                    Trie_deadline();
                    afficherToutesTaches();
                    break;
                case 3:
                    Trie_titre();
                    afficherToutesTaches();
                    break;
                case 4:
                    AfficherTache3joursdeadline();
                    break;
                }
                
                break;
            
            case 3:
                printf("*******Menu de Recherche*******\n");
                printf("1. Rechercher par ID\n");
                printf("2. Rechercher par Titre\n");
                printf("Votre choix : ");
                scanf("%d", &ch4);
                
                if (ch4 == 1) {
                    printf("Entrez l'ID de la tâche à rechercher : ");
                    scanf("%d", &id);
                    int index = Rechercher_id(id);
                    if (index != -1) {
                        afficherTache(tab[index]);
                    } else {
                        printf("Tâche non trouvée.\n");
                    }
                } else if (ch4 == 2) {
                    printf("Entrez le titre de la tâche à rechercher : ");
                    getchar();
                    gets(titre);
                    int index = Rechercher_titre(titre);
                    if (index != -1) {
                        afficherTache(tab[index]);
                    } else {
                        printf("Tâche non trouvée.\n");
                    }
                } else {
                    printf("Choix invalide.\n");
                }
                break;
            
            case 4:
                printf("*******Menu de Manipulation*******\n");
                printf("1. Modification d'une tâche\n");
                printf("2. Suppression d'une tâche par ID\n");
                printf("Votre choix : ");
                scanf("%d", &ch4);
                
                switch (ch4) {
                    case 1:
                        printf("Entrez l'ID de la tâche à modifier : ");
                        scanf("%d", &id);
                        printf("1. Modifier la description.\n");
                        printf("2. Modifier le statut.\n");
                        printf("3. Modifier la deadline.\n");
                        printf("Votre choix : ");
                        scanf("%d", &md);
                        
                        switch (md) {
                            case 1:
                                Modification_description(id);
                                break;
                            case 2:
                                Modification_statut(id);
                                break;
                            case 3:
                                Modification_deadline(id);
                                break;
                            default:
                                printf("Choix invalide.\n");
                        }
                        break;
                        
                    case 2:
                        printf("Entrez l'ID de la tâche à supprimer : ");
                        scanf("%d", &id);
                        supprimer_par_id(id);
                        break;
                        
                    default:
                        printf("Choix invalide.\n");
                }
                break;
            case 5:
                afficherStatistiques();
                break;
            case 6:
                printf("fin de Saisie !!! Au revoir !\n");
                break;
            
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);
}
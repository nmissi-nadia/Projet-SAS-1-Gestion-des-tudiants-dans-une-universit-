#include<stdio.h>
#include<string.h>
#include<time.h>
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

dateN DateAct() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    dateN date_act;
    date_act.jour = tm.tm_mday;
    date_act.mois = tm.tm_mon + 1; // tm_mon commence à 0, donc on ajoute 1
    date_act.annee = tm.tm_year + 1900; // tm_year commence à 1900, donc on ajoute 1900

    return date_act;
}
// Ajouter un étudiant "simple"
void Ajouter() {
    dateN dateact; 

    
    tab[nombre].num = nombre + 1;
    int i;
    printf("Entrez le Nom de l'étudiant : ");
    getchar();
    gets(tab[nombre].nom);
    printf("Entrez le Prénom de l'étudiant : ");
    gets(tab[nombre].prenom);

    printf("Le département :\n");
    printf("1. Math / Info\n");
    printf("2. Physique / Chimie\n");
    printf("3. Sciences Sociales\n");
    printf("4. Sciences Humaines\n");
    scanf("%d", &i);
    switch (i) {
        case 1:
            strcpy(tab[nombre].dept, "Math / Info");
            break;
        case 2:
            strcpy(tab[nombre].dept, "Physique / Chimie");
            break;
        case 3:
            strcpy(tab[nombre].dept, "Sciences Sociales");
            break;
        case 4:
            strcpy(tab[nombre].dept, "Sciences Humaines");
            break;
        default:
            strcpy(tab[nombre].dept, "Non spécifié");
            break;
    }
    dateact = DateAct();
    printf("Entrez la date de naissance (jj mm aaaa) : ");
    scanf("%d %d %d", &tab[nombre].d.jour, &tab[nombre].d.mois, &tab[nombre].d.annee);

    if (!estEtudiantValide(tab[nombre], dateact)) {
        printf("Erreur : Date de naissance invalide ou étudiant trop jeune (moins de 17 ans).\n");
        return;
    }
    printf("Entrez la moyenne générale : ");
    scanf("%f", &tab[nombre].moy_gen);

    nombre++;
    printf("Étudiant ajouté avec succès !\n");
}
//fonction pour qjouter plusieurs étudiant
void Ajout_Multiple(int n){
    while (n!=0)
    {
        Ajouter();
        n--;
    }
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
void main() {
    int choix,ch1,ch2,ch3,ch4,ch5,fois;
    do {
        afficherMenu();
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                printf("\n****** Ajouter un étudiant ******\n");
                printf("1. Ajout simple \n");
                printf("2. Ajout multiple\n");
                printf("Votre choix : ");
                scanf("%d", &ch1);
                
                if (ch1 == 1) {
                    Ajouter();
                } else if (ch1 == 2) {
                    printf("Entrez le nombre des étudiants à ajouter :");
                    scanf("%d",&fois);
                    Ajout_Multiple(fois);
                    
                } else {
                    printf("Choix invalide.\n");
                } 
                break;
                
            case 2:
                printf("\n****** Modifier ou supprimer un étudiant ******\n");
                printf("1. Modifier les informations d'un étudiant\n");
                printf("2. Supprimer un étudiant\n");
                printf("Votre choix : ");
                scanf("%d",&ch2);
                
                if (ch2 == 1) {
                    // Appeler la fonction pour modifier un étudiant
                    ModifierEtudiant();
                } else if (ch2 == 2) {
                    // Appeler la fonction pour supprimer un étudiant
                    SupprimerEtudiant();
                } else {
                    printf("Choix invalide.\n");
                }
                break;
                
            case 3:
                printf("\n****** Afficher les détails d'un étudiant ******\n");
                // Appeler la fonction pour afficher les détails d'un étudiant
                AfficherEtudiant();
                break;
                
            case 4:
                printf("\n****** Calculer la moyenne générale ******\n");
                printf("1. Calculer la moyenne générale de chaque département\n");
                printf("2. Calculer la moyenne générale de l'université\n");
                // Appeler la fonction pour calculer la moyenne générale
                CalculerMoyenneGenerale();
                break;
                
            case 5:
                printf("\n****** Statistiques ******\n");
                printf("1. Nombre total d'étudiants inscrits\n");
                printf("2. Nombre d'étudiants dans chaque département\n");
                printf("3. Étudiants avec une moyenne supérieure à un seuil\n");
                printf("4. Les 3 meilleurs étudiants\n");
                printf("5. Nombre d'étudiants ayant réussi par département\n");
                printf("Votre choix : ");
                scanf("%d", &ch4);
                
                switch (ch4) {
                    case 1:
                        
                        AfficherTotalEtudiants();
                        break;
                    case 2:
                        
                        AfficherEtudiantsParDepartement();
                        break;
                    case 3:
                        
                        AfficherEtudiantsMoyenneSuperieure();
                        break;
                    case 4:
                        
                        AfficherTop3Etudiants();
                        break;
                    case 5:
                        
                        AfficherEtudiantsReussite();
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
                break;
                
            case 6:
                printf("\n****** Rechercher un étudiant ******\n");
                printf("1. Rechercher par nom\n");
                printf("2. Rechercher par département\n");
                printf("Votre choix : ");
                scanf("%d", &ch5);
                
                if (ch5 == 1) {
                    // Rechercher un étudiant par nom
                    RechercherEtudiantParNom();
                } else if (ch5 == 2) {
                    // Rechercher les étudiants par département
                    RechercherEtudiantsParDepartement();
                } else {
                    printf("Choix invalide.\n");
                }
                break;
                
            case 7:
                printf("\n****** Trier les étudiants ******\n");
                printf("1. Tri alphabétique (A-Z ou Z-A)\n");
                printf("2. Tri par moyenne générale (du plus élevé au plus faible ou inversement)\n");
                printf("3. Tri selon le statut de réussite\n");
                printf("Votre choix : ");
                int ch6;
                scanf("%d", &ch6);
                
                switch (ch6) {
                    case 1:
                        // Trier par nom alphabétiquement
                        TrierEtudiantsParNom();
                        break;
                    case 2:
                        // Trier par moyenne générale
                        TrierEtudiantsParMoyenne();
                        break;
                    case 3:
                        // Trier selon le statut de réussite
                        TrierEtudiantsParReussite();
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
                break;
                
            case 0:
                printf("fin de saisie .Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);
}
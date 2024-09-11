#include<stdio.h>
#include<string.h>
#include<time.h>
#include"uneversite.h"
#define MAX_ETUD 10000
void main() {
    int choix,ch1,ch2,ch3,ch4,ch5,ch6,tch1,tch2,tch3,fois,cf,id,seuil,i;
    etudiant e1,e2,e3;
    char dept[30];
        tab[0]=(etudiant){1, "Benali", "Ali", {15, 3, 2002}, "Physique / Chimie", 14.5};
        tab[1]=(etudiant){2, "Ait", "Omar", {22, 8, 2001}, "Math / Info", 6.7};
        tab[2]=(etudiant){3, "El", "Khalil", {9, 11, 2003}, "Physique / Chimie", 13.6};
        tab[3]=(etudiant){4, "Haddad", "Youssef", {30, 5, 2002}, "Sciences Sociales", 11.8};
        tab[4]=(etudiant){5, "Zouhair", "Rachid", {6, 12, 2000}, "Math / Info", 15.2};
        tab[5]=(etudiant){6, "Chakib", "Said", {18, 7, 2001}, "Sciences Humaines", 9.4};
        tab[6]=(etudiant){7, "Boukari", "Nadia", {10, 10, 2003}, "Sciences Sociales", 14.1};
        tab[7]=(etudiant){8, "Tazi", "Fatima", {25, 6, 2002}, "Math / Info", 16.0};
        tab[8]=(etudiant){9, "Alami", "Hanae", {3, 9, 2000}, "Physique / Chimie", 12.9};
        tab[9]=(etudiant){10, "Abdelhadi", "Ahmed", {14, 4, 2001}, "Math / Info", 19.8};
        tab[10]=(etudiant){11, "Rifai", "Soufiane", {1, 1, 2003}, "Math / Info", 5.7};
        tab[11]=(etudiant){12, "Mouhsine", "Amina", {20, 2, 2002}, "Sciences Humaines", 13.3};
        tab[12]=(etudiant){13, "El", "Mehdi", {5, 5, 2001}, "Sciences Sociales", 12.5};
        tab[13]=(etudiant){14, "Khalid", "Samira", {28, 7, 2003}, "Physique / Chimie", 14.4};
        tab[14]=(etudiant){15, "Naji", "Ibrahim", {16, 8, 2002}, "Math / Info", 6.9};
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
                
                switch (ch2) {
                    case 1:
                        printf("**Voulez vous vraiment Modifier ?**\n");
                        printf("1. Oui .\n");
                        printf("2. Non .\n");
                        printf("Votre choix : ");
                        scanf("%d", &cf);
                        switch (cf)
                        {
                        case 1:
                            printf("Entrez l'ID de l'étudiant à modifier : ");
                            scanf("%d",&id);
                            Modification_Etud(id);
                            break;
                        case 2:
                            break;
                        }
                        
                        break;
                        
                    case 2:
                        printf("**Voulez vous vraiment Supprimer ?**\n");
                        printf("1. Oui .\n");
                        printf("2. Non .\n");
                        printf("Votre choix : ");
                        scanf("%d", &cf);
                        switch (cf)
                        {
                        case 1:
                            printf("Entrez l'ID de l'étudiant à supprimer : ");
                            scanf("%d", &id);
                            supprimer_par_id(id);
                            break;
                        case 2:
                            break;
                        }
                        break;
                        
                    default:
                        printf("Choix invalide.\n");
                }
                break;
                break;
                
            case 3:
                printf("\n****** Afficher les détails d'un étudiant ******\n");
                afficherTsEtud();
                break;
                
            case 4:
                printf("\n****** Calculer la moyenne générale ******\n");
                printf("1. Calculer la moyenne générale de chaque département\n");
                CalculerMoyenneGenerale_Dept();
                printf("2. Calculer la moyenne générale de l'université\n");
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
                        
                        printf("Nombre total d'étudiants inscrits : %d \n",nombre);
                        break;
                    case 2:
                        
                        AfficherEtudiantsParDepartement();
                        break;
                    case 3:
                        printf("Entrez le seuil :");
                        scanf("%d",&seuil);
                        AfficherEtudiantsMoyenneSuperieure(seuil);
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
                    
                    RechercherEtudiantParNom();
                } else if (ch5 == 2) {
                    printf("Le département rechérché:\n");
                    printf("1. Math / Info\n");
                    printf("2. Physique / Chimie\n");
                    printf("3. Sciences Sociales\n");
                    printf("4. Sciences Humaines\n");
                    scanf("%d", &i);
                    switch (i) {
                        case 1:
                            strcpy(dept, "Math / Info");
                            break;
                        case 2:
                            strcpy(dept, "Physique / Chimie");
                            break;
                        case 3:
                            strcpy(dept, "Sciences Sociales");
                            break;
                        case 4:
                            strcpy(dept, "Sciences Humaines");
                            break;
                        default:
                            strcpy(dept, "Non spécifié");
                            break;
                    }
                    
                    RechercherEtudiantsParDepartement(dept);
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
                        printf("\n****** Trier les étudiants ******\n");
                        printf("1. Tri alphabétique (A-Z)\n");
                        printf("2. Tri alphabétique (Z-A)\n");
                        scanf("%d",&tch1);
                        if (tch1==1)
                        {
                            TrierEtudiantsParNomAZ_Bulle();
                        }else if(tch1==2){
                            TrierEtudiantsParNomZA();
                        }else
                            printf("Choix invalide!!\n");
                        
                        break;
                    case 2:
                        printf("\n****** Trier les étudiants ******\n");
                        printf("1. Tri des étudiants par moyenne générale, du plus élevé au plus faible\n");
                        printf("2. Tri des étudiants par moyenne générale, du plus faible au plus élevé\n");
                        scanf("%d",&tch2);
                        if (tch2==1)
                        {
                            TrierEtudiantsParMoyenne();
                        }else if(tch2==2){
                            TrierEtudiantsParMoyenneinverse();
                        }else
                            printf("Choix invalide!!\n");
                        
                        break;
                    case 3:
                        
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
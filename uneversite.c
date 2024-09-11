#include<stdio.h>
#include<string.h>
#include<time.h>
#include"uneversite.h"
#define MAX_ETUD 10000
void main() {
    int choix,ch1,ch2,ch3,ch4,ch5,fois,cf,id,seuil;
    etudiant e1,e2,e3;
    FILE *file = fopen("test.txt", "r");
    char dept[30];
    
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
                //CalculerMoyenneGenerale_Dept();
                printf("2. Calculer la moyenne générale de l'université\n");
                
                //CalculerMoyenneGenerale();
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
                        
                        printf("Nombre total d'étudiants inscrits : %d \n",nombre+1);
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
                    
                    // printf();
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
                        
                        //TrierEtudiantsParNom();
                        break;
                    case 2:
                        // Trier par moyenne générale
                        //TrierEtudiantsParMoyenne();
                        break;
                    case 3:
                        // Trier selon le statut de réussite
                        //TrierEtudiantsParReussite();
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
                break;
            case 8:
                remplir_test("test.txt");
                break;
            case 0:
                printf("fin de saisie .Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);
}
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX_ETUD 10000
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
    int nombre=15;

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
    date_act.mois = tm.tm_mon + 1;
    date_act.annee = tm.tm_year + 1900;

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

    dateact = DateAct();
    do
        {
            printf("Entrez la date de naissance (jj mm aaaa) : ");
            scanf("%d %d %d", &tab[nombre].d.jour, &tab[nombre].d.mois, &tab[nombre].d.annee);

            if (!estEtudiantValide(tab[nombre], dateact)) {
            printf("Erreur : Date de naissance invalide ou étudiant moins de 17 ans.\n");
            }
        }while(!estEtudiantValide(tab[nombre], dateact));
    

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
// fonction pour afficher une seul etudiant
void afficheretud(etudiant e) {
    printf("ID: %d\n", e.num);
    printf("Nom: %s\n", e.nom);
    printf("Prénom: %s\n", e.prenom);
    printf("Date de Naissance: %02d/%02d/%04d\n", e.d.jour, e.d.mois, e.d.annee);
    printf("Département: %s\n", e.dept);
    printf("Moyenne Générale: %.2f\n", e.moy_gen);
    printf("---------------------------\n");
}
// fonction qui afficher toutes les étudiants 
void afficherTsEtud() {
    if (nombre == 0) {
        printf("Aucune étudiant à afficher.\n");
    } else {
        for (int i = 0; i < nombre; i++) {
            //afficheretud(tab[i]);
                printf("ID: %d\n", tab[i].num);
                printf("Nom: %s\n", tab[i].nom);
                printf("Prénom: %s\n", tab[i].prenom);
                printf("Date de Naissance: %02d/%02d/%04d\n", tab[i].d.jour, tab[i].d.mois, tab[i].d.annee);
                printf("Département: %s\n", tab[i].dept);
                printf("Moyenne Générale: %f\n", tab[i].moy_gen);
                printf("---------------------------\n");
        }
    }
}
// Fonction pour rechercher une étudiant par son ID
int Rechercher_id(int id) {
    for (int i = 0; i < nombre; i++) {
        if (tab[i].num == id) {
            return i; 
        }
    }
    return -1; 
}
void RechercherEtudiantParNom(){
    char noom[20];
    int tr=-1;
    printf("Entrez Le Nom à rechercher: ");
    getchar();
    gets(noom);
     for (int i = 0; i < nombre; i++) {
        if (strcmp(tab[i].nom,noom)==0) {
            afficheretud(tab[i]); 
            tr=i;
        }
    }
    if(tr==-1){
        printf("Aucun étudiant porter cette nom .\n");
    }
}
// Afficher la liste des étudiants inscrits dans un département spécifique
void RechercherEtudiantsParDepartement(char dept[]){
    int tr=-1;
     for (int i = 0; i < nombre; i++) {
        if (strcmp(tab[i].dept,dept)==0) {
            afficheretud(tab[i]); 
            tr=i;
        }
    }
    if(tr==-1){
        printf("Aucun étudiant dans cette département .\n");
    }
}
//Modifier ou supprimer les informations d'un étudiant en fonction de son numéro unique
void Modification_Etud(int id) {
    dateN dateact;
    int pos = Rechercher_id(id),j,i;
    if (pos != -1) {
        printf("Quelle modification pouvez vous faire ?\n ");
        printf("Modifier :\n");
        printf("1.Nom \n");
        printf("2.Prénom\n");
        printf("3.Date Naissance\n");
        printf("4.Département\n");
        printf("5.Moyenne Générale\n");
        printf("Votre choix :");
        scanf("%d",&j);
        getchar();
        switch (j)
        {
        case 1:
            printf("Entrez le Nom :");
            gets(tab[pos].nom);
            break;
        case 2:
            printf("Entrez le Prénom :");
            
            gets(tab[pos].prenom);
            break;
        case 3:
             dateact = DateAct();
            do
                {
                    printf("Entrez la date de naissance (jj mm aaaa) : ");
                    scanf("%d %d %d", &tab[pos].d.jour, &tab[pos].d.mois, &tab[pos].d.annee);

                    if (!estEtudiantValide(tab[pos], dateact)) {
                    printf("Erreur : Date de naissance invalide ou étudiant moins de 17 ans.\n");
                    }
                }while(!estEtudiantValide(tab[pos], dateact));
            break;
        case 4:
            printf("Le département :\n");
            printf("1. Math / Info\n");
            printf("2. Physique / Chimie\n");
            printf("3. Sciences Sociales\n");
            printf("4. Sciences Humaines\n");
            scanf("%d", &i);
            switch (i) {
                case 1:
                    strcpy(tab[pos].dept, "Math / Info");
                    break;
                case 2:
                    strcpy(tab[pos].dept, "Physique / Chimie");
                    break;
                case 3:
                    strcpy(tab[pos].dept, "Sciences Sociales");
                    break;
                case 4:
                    strcpy(tab[pos].dept, "Sciences Humaines");
                    break;
                default:
                    strcpy(tab[pos].dept, "Non spécifié");
                    break;
            }
            break;
        case 5:
            printf("Entrez le Moyen Générale :");
            scanf("%f",tab[pos].moy_gen);
            break;
        
        }
        
        printf("Etudiant modifiée avec succès.\n");
    } else {
        printf("Etudiant non trouvée.\n");
    }
}
// Fonction pour supprimer une étudiant par ID
void supprimer_par_id(int id) {
    int pos = Rechercher_id(id);
    if (pos != -1) {
       
        for (int i = pos; i < nombre - 1; i++) {
            tab[i] = tab[i + 1];
        }
        nombre--; 
        printf("Etudiant supprimée avec succès.\n");
    } else {
        printf("Etudiant non trouvée.\n");
    }
}

// Statistiques
// Afficher le nombre total d'étudiants inscrits.
void AfficherEtudiantsParDepartement(){
    int aa=0,bb=0,cc=0,dd=0,i;
    printf("Nombre d'étudiants dans:\n");
    for ( i = 0; i < nombre; i++)
    {
        if(strcmp(tab[i].dept,"Math / Info")==0){
            aa++;
        }
        if(strcmp(tab[i].dept,"Physique / Chimie")==0){
            bb++;
        }
        if(strcmp(tab[i].dept,"Sciences Sociales")==0){
            cc++;
        }
        if(strcmp(tab[i].dept,"Sciences Humaines")==0){
            dd++;
        }
        
    }
    printf("Math / Info = %d \n",aa);
    printf("Physique / Chimie = %d \n",bb);
    printf("Sciences Sociales = %d \n",cc);
    printf("Sciences Humaines = %d \n",dd);
}
//  Étudiants avec une moyenne supérieure à un seuil
void AfficherEtudiantsMoyenneSuperieure(int seuil){
    
        for (int i = 0; i < nombre; i++) {
            if(tab[i].moy_gen>=seuil){
                printf("ID: %d\n", tab[i].num);
                printf("Nom: %s\n", tab[i].nom);
                printf("Prénom: %s\n", tab[i].prenom);
                printf("Date de Naissance: %02d/%02d/%04d\n", tab[i].d.jour, tab[i].d.mois, tab[i].d.annee);
                printf("Département: %s\n", tab[i].dept);
                printf("Moyenne Générale: %f\n", tab[i].moy_gen);
                printf("---------------------------\n");
            }
              
        }
    }
//Afficher les 3 étudiants ayant les meilleures notes.

void AfficherTop3Etudiants(){
    int i;
    for (i = 0; i < nombre; i++)
    {
        etudiant temp;
        if(tab[i].moy_gen<tab[i+1].moy_gen)
        {
            temp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=temp;
        }
    }
    for (i = 0; i < 3; i++)
    {
        printf("%d er place :",i+1);
        afficheretud(tab[i]);
    }
    
}
// Afficher le nombre d'étudiants ayant réussi dans chaque département (ceux ayant une note supérieure ou égale à 10/20).
void AfficherEtudiantsReussite(){
     int aa=0,bb=0,cc=0,dd=0,i;
    printf("Nombre d'étudiants dans:\n");
    for ( i = 0; i < nombre; i++)
    {
        if(strcmp(tab[i].dept,"Math / Info")==0){
            if(tab[i].moy_gen>=10)
                aa++;
        }
        if(strcmp(tab[i].dept,"Physique / Chimie")==0){
            if(tab[i].moy_gen>=10)
                bb++;
        }
        if(strcmp(tab[i].dept,"Sciences Sociales")==0){
            if(tab[i].moy_gen>=10)
                cc++;
        }
        if(strcmp(tab[i].dept,"Sciences Humaines")==0){
            if(tab[i].moy_gen>=10)
                dd++;
        }
        
    }
    printf("Math / Info = %d \n",aa);
    printf("Physique / Chimie = %d \n",bb);
    printf("Sciences Sociales = %d \n",cc);
    printf("Sciences Humaines = %d \n",dd);
}
//Calculer la moyenne générale de chaque département
void CalculerMoyenneGenerale_Dept(){
    int aa=0,bb=0,cc=0,dd=0,i;
    float a=0,b=0,c=0,d=0;
    printf("La moyenne général pour:\n");
    for ( i = 0; i < nombre; i++)
    {
        if(strcmp(tab[i].dept,"Math / Info")==0){
            a+=tab[i].moy_gen;
            aa++;
        }
        if(strcmp(tab[i].dept,"Physique / Chimie")==0){
            b+=tab[i].moy_gen;
            bb++;
        }
        if(strcmp(tab[i].dept,"Sciences Sociales")==0){
            c+=tab[i].moy_gen;
            cc++;
        }
        if(strcmp(tab[i].dept,"Sciences Humaines")==0){
            d+=tab[i].moy_gen;
            dd++;
        }
        
    }
    printf("Math / Info = %.2f \n",a/aa);
    printf("Physique / Chimie = %.2f \n",b/bb);
    printf("Sciences Sociales = %.2f \n",c/cc);
    printf("Sciences Humaines = %.2f \n",d/dd);
}
//Calculer la moyenne générale de l'université
void CalculerMoyenneGenerale(){
    int aa=0,i;
    float a=0;
    
    for ( i = 0; i < nombre; i++)
    {
            a+=tab[i].moy_gen;
            aa++;
    }
    printf("La moyenne général pour:%.2f \n",a/aa);
}

// Tri alphabétique des étudiants en fonction de leur nom (de A à Z ou de Z à A).
void TrierEtudiantsParNomAZ_Bulle() {
    int i, j;
    etudiant temp;
    for (i = 0; i < nombre - 1; i++) {
        for (j = 0; j < nombre - i - 1; j++) {
            if (strcmp(tab[j].nom, tab[j + 1].nom) > 0) {
                
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < nombre; i++) {
        afficheretud(tab[i]);
    }
}
void TrierEtudiantsParNomAZ_Insertion() {
    int i, j;
    etudiant temp;
    for (i = 1; i < nombre; i++) {
        temp = tab[i];
        j = i - 1;
        while (j >= 0 && strcmp(tab[j].nom, temp.nom) > 0) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = temp;
    }
    for (i = 0; i < nombre; i++) {
        afficheretud(tab[i]);
    }
}
void TrierEtudiantsParNomAZ_Selection() {
    int i, j, minIndex;
    etudiant temp;
    for (i = 0; i < nombre - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < nombre; j++) {
            if (strcmp(tab[j].nom, tab[minIndex].nom) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Échange les étudiants
            temp = tab[i];
            tab[i] = tab[minIndex];
            tab[minIndex] = temp;
        }
    }
    for (i = 0; i < nombre; i++) {
        printf("%d er place :", i + 1);
        afficheretud(tab[i]);
    }
}

void TrierEtudiantsParNomZA(){
    int i, j;
    etudiant temp;
    for (i = 0; i < nombre - 1; i++) {
        for (j = 0; j < nombre - i - 1; j++) {
            if (strcmp(tab[j].nom, tab[j + 1].nom) < 0) {
                
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < nombre; i++) {
        afficheretud(tab[i]);
    }

}
// Tri des étudiants par moyenne générale, du plus élevé au plus faible ou inversement.
void TrierEtudiantsParMoyenne(){
    int i;
    for (i = 0; i < nombre; i++)
    {
        etudiant temp;
        if(tab[i].moy_gen<tab[i+1].moy_gen)
        {
            temp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=temp;
        }
    }
    for (i = 0; i < nombre; i++)
    {
        afficheretud(tab[i]);
    }
}
void TrierEtudiantsParMoyenneinverse(){
    int i;
    for (i = 0; i < nombre; i++)
    {
        etudiant temp;
        if(tab[i].moy_gen<tab[i+1].moy_gen)
        {
            temp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=temp;
        }
    }
    for (i = 0; i < nombre; i++)
    {
        afficheretud(tab[i]);
    }
}
// Tri des étudiants selon leur statut de réussite (ceux ayant une moyenne supérieure ou égale à 10/20).
void TrierEtudiantsParReussite(){
    int i;
    for (i = 0; i < nombre; i++)
    {
        etudiant temp;
        if(tab[i].moy_gen<tab[i+1].moy_gen)
        {
            temp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=temp;
        }
    }
    for (i = 0; i < nombre; i++)
    {
        if(tab[i].moy_gen>=10)
        {
            afficheretud(tab[i]);
        }
        else{
            break;
        }
        
    }
}
// fonction pour afficher le menu principal
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
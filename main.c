#include <stdio.h>
#include <string.h>


int next_id = 1;
struct joueur {
    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[30];
    int age;
    int buts;
    char dateinscription[20];
    char statut[20];
};

struct joueur joueurs[100];
int nombre_joueur = 0;
void ajouter_joueur() {

    if(nombre_joueur >= 100)
    {
        printf(">>> Impossible d'ajouter plus de joueurs !\n");
        return;
    }
    int choix;
    do {
        printf("------------------------------------------------------------\n");
        printf("\nCHOISIR UNE FONCTION : \n");
        printf("1- Ajouter un joueur\n");
        printf("2- Ajouter plusieurs joueurs\n");
        printf("3- Exit\n");
        printf("------------------------------------------------------------\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            joueurs[nombre_joueur].id = next_id++;
            printf("NOM : ");
            scanf("%s", joueurs[nombre_joueur].nom);
            printf("PRENOM : ");
            scanf("%s", joueurs[nombre_joueur].prenom);
            printf("NUMERO DE MAILLOT : ");
            scanf("%d", &joueurs[nombre_joueur].numeroMaillot);
            printf("POSTE : ");
            scanf("%s", joueurs[nombre_joueur].poste);
            printf("AGE : ");
            scanf("%d", &joueurs[nombre_joueur].age);
            printf("NOMBRE DE BUTS : ");
            scanf("%d", &joueurs[nombre_joueur].buts);
            printf("DATE D'INSCRIPTION (JJ/MM/AAAA): ");
            scanf("%s", joueurs[nombre_joueur].dateinscription);
            printf("STATUT : ");
            scanf("%s", joueurs[nombre_joueur].statut);
            nombre_joueur++;
            printf("------------------------------------------------------------\n");
            printf(">>> JOUEUR AJOUTE AVEC SUCCES !\n");
            printf("------------------------------------------------------------\n");
        } else if (choix == 2) {
            int n;
            printf("Combien de joueurs voulez-vous ajouter ? ");
            scanf("%d", &n);

            if(nombre_joueur + n > 100)
            {
                printf(">>> Impossible d'ajouter plus de joueurs !\n");
                return;
            }
            for (int i = 0; i < n; i++) {
                printf("\n--- Joueur %d ---\n", i + 1);
                joueurs[nombre_joueur].id = next_id++;
                printf("NOM : ");
                scanf("%s", joueurs[nombre_joueur].nom);
                printf("PRENOM : ");
                scanf("%s", joueurs[nombre_joueur].prenom);
                printf("NUMERO DE MAILLOT : ");
                scanf("%d", &joueurs[nombre_joueur].numeroMaillot);
                printf("POSTE : ");
                scanf("%s", joueurs[nombre_joueur].poste);
                printf("AGE : ");
                scanf("%d", &joueurs[nombre_joueur].age);
                printf("NOMBRE DE BUTS : ");
                scanf("%d", &joueurs[nombre_joueur].buts);
                printf("DATE D'INSCRIPTION (JJ/MM/AAAA): ");
                scanf("%s", joueurs[nombre_joueur].dateinscription);
                printf("STATUT : ");
                scanf("%s", joueurs[nombre_joueur].statut);
                nombre_joueur++;
                printf(">>> Joueur %d ajoute avec succes !\n", i + 1);
            }
        }
        // for (int i = 0; i < nombre_joueur; i++) {
        //         printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
        //         joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
        //         joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
        //         joueurs[i].dateinscription, joueurs[i].statut);
        //     }
    } while (choix != 3);
}
void afficher_joueur() {
    if (nombre_joueur == 0) {
        printf(">>> Aucun joueur existe !\n");
        return;
    }

    int choix;
    do {
        printf("\n------------------------------------------------------------\n");
        printf("1- Afficher les joueurs par NOM\n");
        printf("2- Afficher les joueurs par POSTE\n");
        printf("3- Afficher les joueurs par AGE\n");
        printf("4- Exit\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            struct joueur tmp;
            for (int i = 0; i < nombre_joueur - 1; i++) {
                for (int j = i + 1; j < nombre_joueur; j++) {
                    if (strcmp(joueurs[i].nom, joueurs[j].nom) > 0) {
                        tmp = joueurs[i];
                        joueurs[i] = joueurs[j];
                        joueurs[j] = tmp;
                    }
                }
            }

            printf("\n====== LISTE DES JOUEURS TRIES PAR NOM ======\n");
            for (int i = 0; i < nombre_joueur; i++) {
                printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
                joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
                joueurs[i].dateinscription, joueurs[i].statut);
            }

        } else if (choix == 2) {
            char postes[][20] = {"attaquant", "milieu", "defense", "gardien"};

            for (int p = 0; p < 4; p++) {
                printf("\n====== %s ======\n", postes[p]);
                for (int i = 0; i < nombre_joueur; i++) {
                    if (strcmp(joueurs[i].poste, postes[p]) == 0) {
                        printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
                               joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                               joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
                               joueurs[i].dateinscription, joueurs[i].statut);
                    }
                }
            }

        } else if (choix == 3) {
            struct joueur tmp;
            for (int i = 0; i < nombre_joueur - 1; i++) {
                for (int j = i + 1; j < nombre_joueur; j++) {
                    if (joueurs[i].age > joueurs[j].age) {
                        tmp = joueurs[i];
                        joueurs[i] = joueurs[j];
                        joueurs[j] = tmp;
                    }
                }
            }
            printf("\n====== LISTE DES JOUEURS TRIES PAR AGE ======\n");
            for (int i = 0; i < nombre_joueur; i++) {
            printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
            joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
            joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
            joueurs[i].dateinscription, joueurs[i].statut);
            }
        }

    } while (choix != 4);
}
void mod_joueurs()
{
    if (nombre_joueur == 0) {
        printf(">>> Aucun joueur existe !\n");
        return;
    }
    for(int i = 0; i < nombre_joueur; i++)
    {
        printf("------------------------------------------------------------\n");
        printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
        joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
        joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
        joueurs[i].dateinscription, joueurs[i].statut);
    }
        printf("------------------------------------------------------------\n");
    int id;
    printf("Entrer l'ID du joueur a modifier : ");
    scanf("%d", &id);
    for(int i = 0; i < nombre_joueur; i++)
    {
        if(joueurs[i].id == id)
        {
            int choix;
                printf("------------------------------------------------------------\n");
                printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
                joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
                joueurs[i].dateinscription, joueurs[i].statut);
            printf("------------------------------------------------------------\n");

            do{
                printf("1- Modifier Le Poste du Joueur : \n");
                printf("2- Modifier L'age du Joueur : \n");
                printf("3- Modifier Le Nombre de Buts du Joueur : \n");
                printf("4- Exit\n\n");
                printf("Votre choix : ");
                scanf("%d", &choix);

                if(choix == 1)
                {
                    printf("LE NOUVEAU POSTE : ");
                    scanf("%s", joueurs[i].poste);
                    printf("------------------------------------------------------------\n");
                    printf(">>> Poste modifie avec succes !\n");
                    printf("------------------------------------------------------------\n");
                }else if(choix == 2)
                {
                    printf("LE NOUVEL AGE : ");
                    scanf("%d", &joueurs[i].age);
                    printf("------------------------------------------------------------\n");
                    printf(">>> Age modifie avec succes !\n");
                    printf("------------------------------------------------------------\n");
                }else if(choix == 3)
                {
                    printf("LE NOUVEAU NOMBRE DE BUTS : ");
                    scanf("%d", &joueurs[i].buts);
                    printf("------------------------------------------------------------\n");
                    printf(">>> Nombre de buts modifie avec succes !\n");
                    printf("------------------------------------------------------------\n");
                }
            }while(choix != 4);
        }
        else{
            printf("------------------------------------------------------------\n");
            printf(">>> Aucun joueur avec cet ID !\n");
            printf("------------------------------------------------------------\n");
        }
    }
}

void supprimer_joueur() {
    int id;
    if (nombre_joueur == 0) {
        printf(">>> Aucun joueur existe !\n");
        return;
    }
    for (int i = 0; i < nombre_joueur; i++) {
        printf("------------------------------------------------------------\n");
        printf("ID:%d | NOM:%s | PRENOM:%s | MAILLOT:%d | POSTE:%s | AGE:%d | BUTS:%d | DATE:%s | STATUT:%s\n",
               joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
               joueurs[i].poste, joueurs[i].age, joueurs[i].buts,
               joueurs[i].dateinscription, joueurs[i].statut);
    }
    printf("------------------------------------------------------------\n");
    printf("Merci de Choisir le ID du Joueur Pour Supprimer : ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < nombre_joueur; i++) {
        if (joueurs[i].id == id) {
            for (int j = i; j < nombre_joueur - 1; j++) {
                joueurs[j] = joueurs[j + 1];
            }
            nombre_joueur--;
            found = 1;
            printf("------------------------------------------------------------\n");
            printf(">>> Joueur avec ID %d supprimé avec succès !\n", id);
            printf("------------------------------------------------------------\n");
            break;
        }
    }

    if (!found) {
        printf(">>> Aucun joueur avec cet ID !\n");
    }
}

void recherche_joueur()
{
    int id;
    printf("------------------------------------------------------------\n");
    printf("Entrer ID du joueur : ");
    scanf("%d",&id);


}
int main() {
    int choix;
    printf("======> Gestion Equipe de Football <======\n");

    do {
        printf("\n==== MENU ====\n");
        printf("1- Ajouter un joueur\n");
        printf("2- Afficher la liste des joueurs\n");
        printf("3- Modifier un joueur\n");
        printf("4- Suuprimer un joueur\n");
        printf("7- Exit\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
               ajouter_joueur(); 
               break;
            case 2: 
               afficher_joueur(); 
               break;
            case 3:
               mod_joueurs();
               break;
            case 4:
               supprimer_joueur();
               break;
            case 5:
            //    rechercher_joueur();
            //    break;
            case 6:
               printf("Exit...\n"); 
               break;
            default: printf("Choix invalide !\n");
        }
    } while (choix != 7);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_PLAYERS 50

struct team{
    int ID;
    char firstname[MAX];
    char lastname[MAX];
    int numeroMaillot;
    char poste[MAX];
    int age;
    int butes;
};

//globale variable
struct team player[MAX_PLAYERS];

int count = 0;
int ids = 1;

//function for display any player
void displayPlayer(struct team p){
    printf("====================================\n");
    printf("ID du joueur       : %d\n", p.ID);
    printf("Nom                : %s %s\n", p.firstname, p.lastname);
    printf("Numéro de maillot  : %d\n", p.numeroMaillot);
    printf("Poste              : %s\n", p.poste);
    printf("Âge                : %d\n", p.age);
    printf("Buts marqués       : %d\n", p.butes);
    printf("====================================\n\n");

}

// Function to find the index of a player by their ID
int findIndexById(int id) {
    for (int i=0; i<count; i++) {
        if (player[i].ID == id) {
            return i;
        }
    }
    return -1; // Return -1 if not found
}

// Function to find the index of a player by their first name
int findIndexByName(const char* name, int* indexes) {
    indexes[MAX_PLAYERS];
    int pos=0;
    for (int i=0; i<count; i++) {
        if (strcasecmp(player[i].firstname, name) == 0) {
            indexes[pos++]=i;
        }
    }
    if(pos!=0){
        return pos; //return the number has the same name
    }else{
        return -1;
    } // Return -1 if not found
}

void displayallplayer(){
    if (count == 0) {
        printf("L'équipe est vide. Aucun joueur à afficher.\n");
        return;
    }

    for(int i=0; i<count; i++){
        displayPlayer(player[i]);
    }
}

void sortPlayers(){
    if (count == 0) {
        printf("L'équipe est vide. Aucun joueur à afficher.\n");
        return;
    }

    int choice;
    printf("Trier par :\n");
    printf("1. Nom\n");
    printf("2. Âge\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    getchar();
    
    switch(choice){
        case 1:// Sort by name if the name are equale we do the lastname
        {
            int sorted = 1;
            for (int i = 0; i<count-1; i++) {
                for (int j=0; j<count-i-1; j++) {
                    if  ((strcasecmp(player[j].firstname, player[j + 1].firstname) > 0)||
                        ((strcasecmp(player[j].firstname, player[j + 1].firstname)==0)&&
                         (strcasecmp(player[j].lastname, player[j + 1].lastname)>0))) {
                        // Swap players
                        struct team temp = player[j];
                        player[j] = player[j + 1];
                        player[j + 1] = temp;
                        sorted = 0;
                    }
                }
                if(sorted!=0){ //this if the players was sorted just end the loop and desplay them
                    i=count;
                }
            }
            system("cls");
            printf("Joueurs triés par nom:\n");
            displayallplayer();
            break;
        }
        case 2:// sort by age
        {
            int sorted = 1; 
            for (int i=0; i<count-1; i++) {
                for (int j=0; j<count-i-1; j++) {
                    if (player[j].age > player[j + 1].age) {
                        // Swap players
                        struct team temp = player[j];
                        player[j] = player[j + 1];
                        player[j + 1] = temp;
                        sorted = 0;
                    }
                }
                if(sorted!=0){ //this if the players was sorted just end the loop and desplay them
                    i=count;
                }
            }
            system("cls");
            printf("Joueurs triés par nom age:\n");
            displayallplayer();
            break;
        }
        default:printf("Choix invalide. Veuillez réessayer.\n");
        break;
    }

}

void displayPlayersByPosition(){
    
    system("cls");
    int found = 0;
    
    printf("*****************\n");
    printf("====Gardien====\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(strcmp(player[i].poste,"Gardien")==0){
            displayPlayer(player[i]);
            found =1;
            
        }
    }if(!found){
        printf("Il n'y a aucun Gardien \n");
    }
    found = 0;
    printf("*****************\n");
    printf("====Défenseur====\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(strcmp(player[i].poste,"Défenseur")==0){
            displayPlayer(player[i]);
        }
    }
    if(!found){
        printf("Il n'y a aucun Défenseur \n");
    }

    found=0;
    printf("*****************\n");
    printf("====Milieu====\n");
    printf("*****************\n");;
    for(int i=0; i<count; i++){
        if(strcmp(player[i].poste,"Milieu")==0){
            displayPlayer(player[i]);
        }
    }if(!found){
        printf("Il n'y a aucun Milieu \n");
    }

    found=0;

    printf("*****************\n");
    printf("====Attaquant====\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(strcmp(player[i].poste,"Attaquant")==0){
            displayPlayer(player[i]);
        }
    }
    if(!found){
        printf("Il n'y a aucun Attaquant \n");
    }

}

void sortmenu(){
    if (count == 0) {
        printf("L'équipe est vide. Aucun joueur à afficher.\n");
        return;
    }
    
    int choice;
    do{
        system("cls");
        printf("\n--- Menu Liste des Joueurs ---\n");
        printf("1. Trier les joueurs\n");
        printf("2. Afficher les joueurs par poste\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:sortPlayers();
            break;
            case 2:displayPlayersByPosition();
            break;
            case 0:
            break;
            default:printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
        if (choice != 0) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
        }
    }while(choice!=0);
}

void addplayer(){

    if (count >= MAX_PLAYERS) {
        printf("L'équipe est complète. Impossible d'ajouter d'autres joueurs.\n");
        return;
    }
    
    struct team newplayer;

    newplayer.ID = ids++;

    printf("Entrez le prénom du joueur : ");
    scanf(" %[^\n]", newplayer.firstname);

    printf("Entrez le nom du joueur : ");
    scanf(" %[^\n]", newplayer.lastname);

    printf("Entrez le numéro de maillot : ");
    scanf("%d", &newplayer.numeroMaillot);
    getchar();

    int choice;
    do{
        printf("Choisissez le poste :\n");
        printf("1. Gardien\n");
        printf("2. Défenseur\n");
        printf("3. Milieu\n");
        printf("4. Attaquant\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                strcpy(newplayer.poste, "Gardien");
                break;
            case 2:
                strcpy(newplayer.poste, "Défenseur");
                break;
            case 3:
                strcpy(newplayer.poste, "Milieu");
                break;
            case 4:
                strcpy(newplayer.poste, "Attaquant");
                break;
            default:
                printf("Invalid choice. Please choose a number from 1 to 4.\n");
        }

    }while(choice < 1 || choice > 4);

    printf("Entrez l'âge : ");
    scanf("%d", &newplayer.age);
    getchar();

    printf("Entrez le nombre de buts :  ");
    scanf("%d", &newplayer.butes);
    getchar();

    player[count++] = newplayer;
    printf("Player %s %s (ID: %d) added successfully!\n", newplayer.firstname, newplayer.lastname, newplayer.ID);

    printf("\nAppuyez sur Entrée pour continuer...");
    getchar();

}

void addmultipleplayer(){
    int n;
    printf("Combien de joueurs voulez-vous ajouter ? ");
    scanf("%d", &n);
    getchar();

    
    for (int i = 0; i < n; i++) {
        system("cls");
        printf("=== ajouter le joueur %d===\n",i+1);
        addplayer();
    }

}

void addplayerMenu(){

    int choice;
    do{
        system("cls");
        printf("\n--- Menu d'Ajout de Joueur ---\n");
        printf("1. Ajouter un seul joueur\n");
        printf("2. Ajouter plusieurs joueurs\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
            addplayer();
            break;
            case 2:
            addmultipleplayer();
            break;
            case 0:
            break;
            default:printf("Choix invalide. Veuillez réessayer.\n");
        }   
    }while(choice !=0);

}

void editPlayer(){
    int id;
    printf("Entrez l'ID du joueur à modifier :");
    scanf("%d", &id);
    getchar();

    int index = findIndexById(id);
    if (index == -1) {
        printf("Player not found.\n");
        return;
    }

    int choice;
    printf("Que voulez-vous modifier pour %s %s?\n", player[index].firstname, player[index].lastname);
    printf("1. post\n");
    printf("2. age\n");
    printf("3. butes\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    getchar();

    switch(choice){
        case 1:
            int postechoice;
            do{
                printf("Choisissez le nouveau poste :\n");
                printf("1. Gardien\n");
                printf("2. Défenseur\n");
                printf("3. Milieu\n");
                printf("4. Attaquant\n");
                printf("Votre choix : ");
                scanf("%d", &postechoice);
                getchar();
                if (postechoice<1 || postechoice>4) {
                    printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
                }
            }while(postechoice<1 || postechoice>4);
            switch (postechoice){
                case 1:strcpy(player[index].poste, "Gardien");break;
                case 2:strcpy(player[index].poste, "Défenseur");break;
                case 3:strcpy(player[index].poste, "Milieu");break;
                case 4:strcpy(player[index].poste, "Attaquant");break;
            }
        break;
        case 2:
            printf("Entrez le nouvel âge : ");
            scanf("%d", &player[index].age);
            getchar(); 
        break;
        case 3: 
            printf("Entrez le nouveau nombre de buts : ");
            scanf("%d", &player[index].butes);
            getchar();
        break;
        default:printf("Choix invalide. Veuillez réessayer.\n");
        break;

    }
}

void deletePlayer(){
    if (count == 0) {
        printf("L'équipe est vide. Aucun joueur à afficher.\n");
        return;
    }
    int id;
    printf("Entrez l'ID du joueur à supprimer : ");
    scanf("%d", &id);
    getchar();

    int index = findIndexById(id);
    if (index == -1) {
        printf("Joueur non trouvé.\n");
        return;
    }

    printf("Voulez-vous vraiment supprimer ce joueur ? ....\n");
    printf("(O/N) O pour OUI, N pour NON : ");
    char confermation;
    scanf(" %c",confermation);
    getchar();

    if(confermation == 'o' || confermation== 'O'){
        printf("l'opération de suppression a été annulée");
        return;
    }
    // just copy the last one to the one you want to delete and decrease the number of players
    player[index] = player [count-1]; 
    count--;
    printf("Joueur supprimé avec succès !\n");
}

void searchPlayer(){
    int choice;
    printf("Rechercher par :\n");
    printf("1. ID  :\n");
    printf("2. Nom :\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    getchar();

    switch(choice){
        case 1:{
            int id;
            printf("Entrez l'ID du joueur à rechercher : ");
            scanf("%d", &id);
            getchar();

            int index = findIndexById(id);
            if (index != -1) {
                printf("Joueur trouvé:\n");
                displayPlayer(player[index]);
            } else {
                printf("Joueur non trouvé.\n");
            }
        break;
        }
        case 2:{
        int index_players[MAX_PLAYERS];
        char searshing[MAX];
        printf("Entrez le nom du joueur à rechercher : ");
        scanf(" %[^\n]", searshing);
        getchar();
        int players_same_name = findIndexByName(searshing, index_players);

        if (players_same_name != -1) {
            printf("Joueurs trouvé:\n");
            for(int i=0; i<players_same_name; i++){
                displayPlayer(player[index_players[i]]);
            }
        } else {
            printf("Joueur non trouvé.\n");
        }
        break;
        }
        default:
            printf("Choix invalide\n");
            break;
        
    }

}

void actionsmenu(){
    int choice;
    do{
        system("cls");
        printf("\n--- Menu Actions Joueur ---\n");
        printf("1. Modifier un joueur\n");
        printf("2. Supprimer un joueur\n");
        printf("3. Rechercher un joueur\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:editPlayer();
            break;
            case 2:deletePlayer();
            break;
            case 3:searchPlayer();
            break;
            case 0:
            break;
            default:printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
        if (choice != 0) {
                printf("\nAppuyez sur Entrée pour continuer...");
                getchar();
        }
}while(choice!=0);
}

void statistic(){
    if (count == 0) {
        printf("L'équipe est vide. Aucun joueur à afficher.\n");
        return;
    }
    printf("--- Statistiques de l'équipe ---\n");

    // Total number of players
    printf("====Nombre total de joueurs : %d====\n",count);

    // Average age
    printf("====Âge moyen des joueurs====\n");
    float totalAge = 0;
    for (int i = 0; i < count; i++) {
        totalAge += player[i].age;
    }
    float averageAge = totalAge / count;
    printf("Âge moyen des joueurs: %.2f years\n", averageAge);

    // Youngest and oldest player
    if (count > 0) {
        int youngestIndex = 0;
        int oldestIndex = 0;
        for (int i = 1; i<count; i++) {
            if (player[i].age < player[youngestIndex].age) {
                youngestIndex = i;
            }
            if (player[i].age > player[oldestIndex].age) {
                oldestIndex = i;
            }
        }
        printf("====Joueur le plus jeune====\n");
        displayPlayer(player[youngestIndex]);
        printf("====Joueur le plus âgé====\n");
        displayPlayer(player[oldestIndex]);
    }

    // Top goal scorer
    int topScorerIndex = -1;
    int maxGoals = -1;
    for (int i = 0; i < count; i++) {
        if (player[i].butes > maxGoals) {
            maxGoals = player[i].butes;
            topScorerIndex = i;
        }
    }
    if (topScorerIndex != -1) {
        printf("====Meilleur buteur de l'équipe====\n");
        displayPlayer(player[topScorerIndex]);
    }
    // Players with more than X goals

    int numbgoal;
    printf("Entrez le nombre minimum de buts pour afficher les joueurs : ");
    scanf("%d",&numbgoal);
    getchar();

    int found = 0;
    printf("Joueurs ayant marqué plus de %d buts\n", numbgoal);
    for (int i = 0; i < count; i++) {
        if (player[i].butes > numbgoal) {
            displayPlayer(player[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No players have scored more than %d goals.\n", numbgoal);
    }
}

void addDefaultPlayers(){
    struct team defaultPlayers[10] ={
        {0, "Hakim", "Ziyech", 22, "Milieu", 30, 7},
        {0, "Achraf", "Hakimi", 2, "Défenseur", 25, 15},
        {0, "Youssef", "En-Nesyri", 9, "Attaquant", 26, 20},
        {0, "Romain", "Saïss", 4, "Défenseur", 34, 2},
        {0, "Sofiane", "Boufal", 11, "Milieu", 28, 6},
        {0, "Munir", "El Haddadi", 19, "Attaquant", 27, 4},
        {0, "Noussair", "Mazraoui", 12, "Défenseur", 25, 41},
        {0, "Yassine", "Bounou", 1, "Gardien", 32, 0},
        {0, "Selim", "Amallah", 14, "Milieu", 28, 3},
        {0, "Abdelhamid", "Sabiri", 17, "Milieu", 27, 2}
    };
    for(int i=0; i<10; i++){
        defaultPlayers[i].ID= ids++;
        player[i]=defaultPlayers[i];
        count++;
    }

}

int main(){



    system("cls");
    int start;
    printf("Voulez-vous démarrer le programme avec :\n");
    printf("1. Joueurs par défaut\n");
    printf("2. Sans joueurs par défaut\n");
    printf("Votre choix : ");
    scanf("%d",&start);
    getchar();
    
    if(start==1){
        printf("Le programme va démarrer avec 10 joueurs par défaut.\n");
        addDefaultPlayers();
        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();
    }else{
        printf("Le programme va démarrer sans aucun joueur.");
        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();
    }
    

    int choice;
    do{
        system("cls");

        printf("---Gestion d'une equipe de Football---\n");
        printf("1. Ajouter un ou plusieurs joueurs\n");
        printf("2. Voir la liste des joueurs\n");
        printf("3. Actions du joueur (Modifier, Supprimer, Rechercher)\n");
        printf("4. Afficher les statistiques de l'equipe\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
            addplayerMenu();
            break;
            case 2:
            sortmenu();
            break;
            case 3:
            actionsmenu();
            break;
            case 4:
            statistic();
            break;
            case 0:
            printf("Merci d'avoir utilisé notre application. Au revoir !\n");
            break;
            default:printf("Choix invalide. Veuillez réessayer.\n");
            break;

        }
        if (choice != 0) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
        }
        
    }while(choice != 0);
    return 0;
}

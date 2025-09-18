# ⚽ Gestion d'une Équipe de Football  
**Langage : C**  
**Type : Projet Final d’Examen**

## 📖 Description
Ce projet est une application en **C** qui permet de gérer une équipe de football à partir du terminal.  
L’utilisateur peut ajouter, afficher, modifier, supprimer et rechercher des joueurs tout en obtenant des **statistiques** sur l’équipe.  

C’est un programme interactif qui fonctionne uniquement en **ligne de commande** et utilise des **structures C** pour stocker les données des joueurs.

## ✨ Fonctionnalités

✅ **Ajout de joueurs**  
- Ajouter un ou plusieurs joueurs manuellement.  
- Démarrer le programme avec **10 joueurs par défaut** (exemple d’équipe marocaine).  

✅ **Affichage de la liste des joueurs**  
- Afficher tous les joueurs.  
- Trier par **nom** ou **âge**.  
- Afficher les joueurs par **poste** (Gardien, Défenseur, Milieu, Attaquant).  

✅ **Actions sur un joueur**  
- **Modifier** le poste, l’âge ou le nombre de buts d’un joueur.  
- **Supprimer** un joueur par son **ID**.  
- **Rechercher** un joueur par **ID** ou **prénom**.  

✅ **Statistiques de l’équipe**  
- Nombre total de joueurs.  
- Âge moyen.  
- Joueur le plus jeune et le plus âgé.  
- Meilleur buteur.  
- Liste des joueurs ayant marqué plus d’un nombre de buts donné.

## 🏗️ Structure des Données

Chaque joueur est représenté par une **structure C** :

```c
struct team {
    int ID;
    char firstname[100];
    char lastname[100];
    int numeroMaillot;
    char poste[100];
    int age;
    int butes;
};
```

- **ID** : identifiant unique (généré automatiquement).  
- **firstname** / **lastname** : prénom et nom.  
- **numeroMaillot** : numéro de maillot.  
- **poste** : Gardien, Défenseur, Milieu ou Attaquant.  
- **age** : âge du joueur.  
- **butes** : nombre de buts marqués.

## 💻 Compilation et Exécution

### 1️⃣ Compilation  
Dans un terminal, exécuter :  
```bash
gcc main.c -o football
```

### 2️⃣ Lancement du programme  
```bash
./football
```

### 3️⃣ Sur Windows (Code::Blocks ou MinGW)
```bash
gcc main.c -o football.exe
football.exe
```

## 📋 Menu Principal

Lorsque vous exécutez le programme, vous verrez :  
```
--- Gestion d'une equipe de Football ---
1. Ajouter un ou plusieurs joueurs
2. Voir la liste des joueurs
3. Actions du joueur (Modifier, Supprimer, Rechercher)
4. Afficher les statistiques de l'equipe
0. Quitter
```

🔹 **1** → Menu d’ajout de joueurs.  
🔹 **2** → Affichage et tri des joueurs.  
🔹 **3** → Modifier, supprimer ou rechercher un joueur.  
🔹 **4** → Afficher les statistiques de l’équipe.  
🔹 **0** → Quitter le programme.

## 🚀 Fonctionnement de l’ID
- Chaque joueur reçoit un **ID unique** automatiquement.  
- Lorsqu’un joueur est supprimé, l’ID **n’est pas réattribué** pour éviter les doublons.  

## ⚠️ Limitations
- Maximum de **50 joueurs**.  
- L’application utilise `system("cls")` pour Windows.  
  - Sous Linux/Mac, remplacez par `system("clear")` si nécessaire.  
- Entrée utilisateur sensible (une saisie incorrecte peut provoquer des erreurs mineures).

## 🏆 Exemple d’Utilisation
1. Démarrer avec 10 joueurs par défaut.  
2. Afficher la liste des joueurs triés par âge.  
3. Rechercher un joueur par prénom.  
4. Modifier son poste ou ses buts.  
5. Consulter les statistiques pour voir le meilleur buteur.

## 📚 Objectifs Pédagogiques
Ce projet met en pratique :  
- **Structures (`struct`)**  
- **Tableaux**  
- **Boucles** et **conditions**  
- **Fonctions en C**  
- Gestion des **entrées utilisateur**  
- Manipulation de **chaînes de caractères**

## 👨‍💻 Auteur
Projet développé par **OUSSMA EL AIMAR**  
Dans le cadre de l’**examen final** du module **Langage C**.

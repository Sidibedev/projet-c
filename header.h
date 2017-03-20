#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"


#endif // HEADER_H_INCLUDED
#define clrscr() printf("\e[1;1H\e[2J");

void authentification (){
            char login[50];
            char mdp[50];
            char car;
            int j=0;

            printf("---------------------------ASSOCIATION ANCIENS ETUDIANTS ESP ----------------------------------\n\n") ;

            printf("------------------------------------ AUTHENTIFIER VOUS --------------------------------------------\n\n\n") ;

            printf("Entrer votre login  svp : \n ");
            scanf("%s",login);

            printf("Entrer votre mot de passe  svp : \n ");
             //scanf("%s",mdp);



            do{
            car = getchar();
            printf("*");
            if(car != 13)
            {
            mdp[j] = car;
            j++;
            }
            }while(car != 13);
            mdp[j] = '\0';


        }


void menu_principal() {
	clrscr();
	int nb_elements_menu = 5, i;
	char elements_menu[8][30] = {"Ajouter un membre", "Modifier un membre", "afficher liste des membres", "Recherche par numero", "Supprimer"};
	int choix;

	for (i=0; i<nb_elements_menu; i++) {
		printf("%d. %s\n", i+1, elements_menu[i]);
	}

	do {
		scanf("%d", &choix);
		getc(stdin); // Consumer le retour a la ligne
	} while (choix > nb_elements_menu);

	switch(choix) {
		case 1:
			ajouter_membre_menu();
			break;
		case 2:
			modifier_membre_menu();
			break;
		case 3:
			liste_membre_menu();
			break;
		case 4:
		    recherche_id_membre_menu();
			break;


		case 5:
			supprimer_membre_menu();
			break;

	}
}

int confirmer() {
	char confirmation;
	confirmation = 'o';
	puts("Confirmer ? (o/n)");
	scanf("%c", &confirmation);
	getc(stdin);
	if (confirmation == 'o' || confirmation == 'O') {
		return 1;
	} else {
		return 0;
	}
}

Membre lire_membre() {
	Membre membre;
	printf("Entrez les informations du membre.");
	printf("Prenom du membre: ");
	fgets(membre.prenom, sizeof(membre.prenom), stdin);
	printf("Nom du membre: ");
	fgets(membre.nom, sizeof(membre.nom), stdin);
	printf("Adresse du membre: ");
	fgets(membre.adresse, sizeof(membre.adresse), stdin);

	printf("Date de naissance du membre (jj/mm/aaaa):");
	scanf("%d/%d/%d", &membre.ddn.jour, &membre.ddn.mois, &membre.ddn.annee);
	getc(stdin);

	// fgets lit les retours a la ligne, on les remplace par des caracteres nuls
	strtok(membre.nom, "\n");
	strtok(membre.prenom, "\n");
	strtok(membre.adresse, "\n");

	return membre;
}



void ajouter_membre_menu() {
	Membre membre;
	membre = lire_membre();

	printf("%s, %s, %s, %d/%d/%d\n", membre.nom, membre.prenom, membre.adresse,
			membre.ddn.jour, membre.ddn.mois, membre.ddn.annee);
	puts("Confirmer ? (O/n)");

	char confirmation;
	confirmation = 'o';
	scanf("%c", &confirmation);
	getc(stdin);
	if (confirmation == 'o' || confirmation == 'O') {
		membre_ajouter(membre);
	}

	menu_principal();
}




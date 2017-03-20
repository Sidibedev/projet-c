#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED



#endif // STRUCTURE_H_INCLUDED


  // les structures qu'on aura a utiliser seront definit ici

  typedef struct {
	int jour ;
	int mois ;
	int annee;
} Date;

  typedef struct {
	int numero;
	char nom[30];
	char prenom[100];
	char adresse[200];
	char classe[100];
	Date ddn;

} Membre;

typedef struct {
	int code;
	char intitule[30];
	char annee[100];

} Formation ;


struct listechaine {
Membre membre ;
struct listechaine *suivant ;
};
typedef struct listechaine MAILLON , *Membreliste;

//               		 UNE IDEE D'ALGO               		  //
// 		  Parce que ca aide vachement d'ecrire ses idees 	  //


// ---- Il s'agit ici de l'algo principal, qui ne sera lance qu'apres ----//
// ----	           verification totale du fichier d'entree            ----//
// ----                  contenant les tertriminos                    ----//


/*

Le fichier prend en parametre le tableau de tableau contenant les
tetriminos donnes au programme. Voici son deroulement dans les grandes
lignes.

char **squaresize(int x, int y)
{
	cree un table de taille x et y remplis de '.', et le retourne.
		// Le fait que le tableau soit remplis de points va faciliter le 
		\\ placement des tetraminos, puisque ceux ci ignorent ce 
		// caractere.
}

char **fillit(char **tab)
{
	char **finaltab;
	static int x = 2;
	static int y = 2;

	finaltab = squaresize
	place les tetriminos dans l'ordre du fichier, dans le tab cree
		// Le tab correspond au carre et est de 2 x 2 a l'entree du programme.
	if (ca marche)
		return (finaltab)
			// la fonction se termine.
	if (ca marche pas)
	{
		x++;
		y++;
		rapelle la fonction, avec la nouvelle taille de carre.
			// Puisaue x et y sont des static, ils vont garder leur 
			\\ valeur. ainsi, le programme essaie avec le plus 
			// petit carre et, des qu'il trouve la reponse, il la retourne.
			\\ Dans le cas inverse, il aggrandis le carre et reessaie.
	}
}

Nous pouvons aussi separer ca en plus de fonctions (pour la norme) : 

- Une qui cree le tableaux a la bonne taille et le remplis de '.'.
- Une deuxieme qui replis le carre et retourne simplement si elle y est arrive ou non.
- Une derniere qui reagis en fonction du resultat du placement des tetriminos, et qui 
	va relancer la seconde fonctions jusau'a ce qu'elle trouve le bon resultat.

Un probleme : Placer les tetriminos dans l'ordre du fichier. Le sujet dis bien les 
	placer dans l'ordre, mais dans les exemples, les tetriminos sont places 
	dans le desordre par rapport au fichier.
	Si on doit changer l'ordre des tetriminos, une fonction en plus devra etre cree, 
	et qui aura seulement cette utilisation ! Elle sera lance dans le cas ou le
	placement marche pas.

Mais cela cree un second probleme : Aggrandir le carre uniquement quqnd tous les ordres
	de tetriminos possible ont ete traites.
	Il faudrait conditionner l'aggrandissement du carre, c'est sur. Mais quelle serait
	cette condition ? Comment calculer le nombre maximum de possibilite ?


Bon c'est un peu confus, mais c'est ce au'il se passe dans ma tete ! Et puis c'est de l'itteratif ca, y a surement plus optimise, j'attend de voir comment tu vois ca de ton cote !
J'espere que tu regrettes pas de t'etre mis en groupe avec moi mdrr. Kiss !
*/

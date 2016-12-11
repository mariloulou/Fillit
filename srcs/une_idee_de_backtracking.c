/* ----- UNE IDEE DE BACKTRACKING ----- */

/*

void	fonction_qui_retire_tetriminos_faux(char **map, int block, char c) // Char c est la lettre aui correspond au tetriminos en question
{
	utilise l'int laisse par place_tetriminos, qui correspond au nombre de tetriminos au'elle a pu poser. 
	Parcours le tableau et retire tous les lettres correspondant au char C, et s'arrete lorsau'elle a retire autant de lettres que block
}

int 	is tetri L-shape(char *tetri)
{
 	si tetri[0] = '.';
		return 1
	else return 0;
}

void	fonction aui retrouve les positions du tetriminos precedent(char **map, int *i, int *j, char c, char *tetri)
{
	int x,
	int y,
	int block
	
	while (block < 4)
	{
		parcours le tableau a partir de la fin, en incrementant block a chaque fois au'il rencontre le un bloc du tetri.
	}
	block est egal a 4 : x et y sont a la position de depart du premier tetri.
	if is tetri L shape == 0  // comme place tetri igore le premier point des tetri en L inverse das leur placement, x et y seront deja 
	places au carre suivant, dans le cas ou le tetriminos commence bien par un block, il faut les incrementer pour aller au carre suivant.
		x++;
		y++;
	&i = x;
	&j = y;
}

int	fonction qui place les tetris une case plus loin(char **map, char *tetri)
{
	static int i = 0,
	static int j = 0,

	if (on a reussi a poser le dernier tetri)
		return la map remplie. // Yay.
	lance place_tetriminos au positions [i][j], avec le tetri actuel.
	if (place return faux)
	{
		if (on est a la derniere case du tableau)
		{
			if (on a le premier tetri en parametre)
			{
				lance fonction qui efface le tetri.
				i = 0;
				j = 0;
				lance fonction aui aggrandis la map;
				se rapelle.
			}
			else
			{
				lance fonction de recup de position du tetri precedent; // Elle replace bien i et j une case plus loin aue la 
																position initale.
				lance fonction qui retire tetriminos avec le current, et celui d'avant.
				prends le tetri d'avant en parametre.
				se rapelle.
			}
		}
		lance fonction qui efface le tetri;
		i++;
		j++;
		se rapelle.
	}
	if (place return vrai)
	{
		prends un nouveau tetri en parametre;
		i++;
		j++;
		se rapelle.
	}
}


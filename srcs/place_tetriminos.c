int	check_place(char **map, int i, int j, char *tetri)
{
	int block;
	int savej;

	block = 0;
	savej = j;
	while(block < 4 || *tetri != '\0')
	{
		while (*tetri != '#')
			tetri++;
		if (map[i][j] == '.')
		{
			map[i][j] = *tetri;
			block++;
			tetri++;
			j++;
			while (*tetri != '#')
			{
				tetri++;
				if (*tetri % 5 == 0)
				{
					i++;
					j = savej;
				}
			}
		}
	}
	if (block == 4)
		return(1);
	return(0);
}

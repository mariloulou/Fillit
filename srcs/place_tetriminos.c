int	check_place(char **map, int i, int j, char *tetri)
{
	int y;
	int block;
	int savej;

	y = 0;
	block = 0;
	savej = j;
	while(block < 4 || tetri[y] != '/0')
	{
		while (tetri[y] != '#')
			y++;
		if (map[i][j] == '.');
		{
			map[i][j] == tetri[y];
			block++;
			y++;
			j++;
			while (tetri[y] != '#')
			{
				y++;
				if (y % 5 == 0)
				{
					i++;
					j == savej;
				}
			}
		}
	}
	if (block == 4)
		return(1)
	return(0);
}

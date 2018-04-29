#include "fdf.h"

void	win_init_var(t_mlx *list, int argc, char **argv)
{
	LA = list->gapx * PTNB + list->gapy * ROWNB + 30;
	HA = list->gapx * ROWNB + list->gapy * PTNB + 50;
	if (argc >= 4 && ft_atoi(argv[2]) > 79 && ft_atoi(argv[3]) > 79
		&& ft_atoi(argv[2]) < 2001 && ft_atoi(argv[3]) < 2001)
	{
		LA = ft_atoi(argv[2]);
		HA = ft_atoi(argv[3]);
		list->custom_size = 1;
	}
	if (!(MLX_PTR = mlx_init()))
		ft_fail("Error: Connection failed.", NULL);
}

int		set_origins(t_mlx *list)
{
	MVX = (list->gapy * ROWNB) % LA;
	MVY = list->gapy;
	return (0);
}

void	minandmax(t_mlx *list)
{
	unsigned int	select;
	unsigned int	s2;

	select = -1;
	MINV = TAB[0][0];
	MAXV = MINV;
	while (++select < ROWNB)
	{
		s2 = 0;
		while (++s2 <= PTNB)
		{
			if (TAB[select][s2 - 1] > MAXV)
				MAXV = TAB[select][s2 - 1];
			else if (TAB[select][s2 - 1] < MINV)
				MINV = TAB[select][s2 - 1];
		}
	}
}

int		set_window_size(t_mlx *list, int argc, char **argv)
{
	list->gapx = 20;
	list->gapy = list->gapx / 5;
	if (list->gapy <= 0)
		list->gapy = 1;
	win_init_var(list, argc, argv);
	if (list->custom_size == 0)
	{
		while ((LA > 1800 || HA > 1200) && list->gapx > 1)
		{
			list->gapx -= 1;
			list->gapy = list->gapx / 5;
			if (list->gapy <= 0)
				list->gapy = 1;
			LA = (list->gapx * PTNB) + (list->gapy * ROWNB) + 30;
			HA = (list->gapx * ROWNB) + (list->gapy * PTNB) + 50;
		}
	}
	if (LA > 1800 || HA > 1200)
	{
		LA = LA > 2000 ? 1999 : LA;
		HA = HA > 2000 ? 1999 : HA;
	}
	if (!(WIN_PTR = mlx_new_window(MLX_PTR, LA, HA, argv[1])))
		ft_fail("Error: Unable to create window.", NULL);
	return (set_origins(list));
}

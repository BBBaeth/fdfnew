/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:12:11 by ceugene           #+#    #+#             */
/*   Updated: 2018/03/12 14:12:12 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**tab_alloc(t_mlx *list)
{
	int		s;

	s = 0;
	if (!(TAB = (int **)malloc(sizeof(int *) * ROWNB + 1)))
		ft_fail("Error: Could not allocate memory.", list);
	while (s < (int)ROWNB)
	{
		if (!(TAB[s] = (int *)malloc(sizeof(int) * PTNB + 1)))
			ft_fail("Error: Could not allocate memory.", list);
		s++;
	}
	return (TAB);
}

void	ft_free_map(char **map)
{
	int		select;

	select = 0;
	while (map[select])
	{
		ft_bzero(map[select], ft_strlen(map[select]));
		free(map[select]);
		map[select] = NULL;
		select++;
	}
	free(map);
	map = NULL;
}

void	ft_free_int(t_mlx *list)
{
	unsigned int	select;

	select = 0;
	while (select < ROWNB)
	{
		free(TAB[select]);
		TAB[select] = NULL;
		select++;
	}
	free(TAB);
	TAB = NULL;
}

void	key_displayer(t_mlx *list)
{
	void	*a;

	a = MLX_PTR;
	if (KD == 1)
	{
		mlx_string_put(a, WIN_PTR, 10, 10, 0xFFFFFFF, "K: hide keys\n");
		mlx_string_put(a, WIN_PTR, 10, 25, 0xFFFFFFF, "A/D/W/X: move\n");
		mlx_string_put(a, WIN_PTR, 10, 40, 0xFFFFFFF, "S: reset\n");
		mlx_string_put(a, WIN_PTR, 10, 55, 0xFFFFFFF, "E/C: modify ratio");
		mlx_string_put(a, WIN_PTR, 10, 70, 0xFFFFFFF, "UP/DOWN: zoom in/out");
	}
}

int		**split_to_int(char **map, t_mlx *list)
{
	int		s;
	int		s2;
	int		s3;

	s = 0;
	tab_alloc(list);
	while (map[s][0])
	{
		s3 = -1;
		s2 = 0;
		while (s3 < (int)PTNB)
		{
			if (((ft_isdigit(map[s][s2]) && (s2 == 0
				|| ft_isspace(map[s][s2 - 1]))) || map[s][s2] == '-'))
				TAB[s][++s3] = ft_atoi(map[s] + s2);
			if (ft_atoi(map[s] + s2) * COEFF * 4 > 200000000
				|| ft_atoi(map[s] + s2) * COEFF * 4 < -2000000000)
				ft_fail("Error: A value was too big.", list);
			s2++;
		}
		s++;
	}
	ft_free_map(map);
	return (TAB);
}

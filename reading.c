/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:12:05 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/21 17:03:16 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_dist(char *line, t_mlx *list, int argc, char **argv)
{
	int		point_nb;
	int		select;

	select = 0;
	point_nb = 0;
	while (line[select])
	{
		if ((select == 0 && ft_isdigit(line[select]))
			|| (ft_isdigit(line[select]) && (ft_isspace(line[select - 1])
				|| line[select - 1] == '-')))
			point_nb++;
		select++;
	}
	PTNB = point_nb;
	set_window_size(list, argc, argv);
	DIST = 1;
	while (DIST * DIST * (PTNB / 2) <= LA)
		DIST++;
	while (DIST * DIST * (ROWNB / 2) <= LA)
		DIST++;
	if (PTNB * ROWNB > 2500)
		DIST = 1;
	else if (DIST <= 10)
		DIST = DIST * 2;
}

int		verif_line(char *line)
{
	int		select;
	int		length;

	select = 0;
	length = 0;
	while (line[select])
	{
		if ((line[select] != ' ' && !(ft_isalpha(line[select]))
			&& line[select] != ',' && line[select] != '-'
				&& !(ft_isdigit(line[select]))))
		{
			ft_putstr_fd("Error: Invalid character '", 2);
			ft_putchar(line[select]);
			ft_fail("' found.", NULL);
		}
		if (line[select] == '-' && !(ft_isdigit(line[select + 1])))
			ft_fail("Error: Invalid character '-' found.", NULL);
		if ((ft_isdigit(line[select]) && (select == 0
			|| ft_isspace(line[select - 1]))) || line[select] == '-')
			length++;
		select++;
	}
	return (length);
}

int		verif_map(char **map, t_mlx *list, int argc, char **argv)
{
	int		s;
	int		line_size;
	int		length;

	s = 0;
	line_size = 0;
	while (map[s][0])
	{
		length = verif_line(map[s]);
		if (s == 0)
			line_size = length;
		if (line_size != length && map[s][0] != '\0')
			ft_fail("Error: Different line length found.", list);
		if (line_size < 1 || length == 1)
			ft_fail("Error: Cannot make a map with this file.", list);
		s++;
	}
	if (s <= 1)
		ft_fail("Error: Cannot make a map with this file.", list);
	ROWNB = s;
	calc_dist(map[0], list, argc, argv);
	return (0);
}

int		**start_reading(char *str, t_mlx *list, int argc, char **argv)
{
	char					**map;
	unsigned int			y_size;
	int						ret;

	if (!(map = malloc(sizeof(char *) * 2048)))
		ft_fail("Error: Couldn't allocate memory", list);
	y_size = 0;
	FD = open(str, O_RDONLY);
	if (FD < 0)
	{
		ft_putstr_fd("Error: No file '", 2);
		ft_putstr_fd(str, 2);
		ft_fail("' found.", list);
	}
	while ((ret = get_next_line(FD, &map[y_size])) > 0 && y_size < 2048)
		y_size++;
	if (y_size == 2048 || ret == -1)
		ft_fail("Error: File is too big. Directories are not supported.", list);
	if (y_size <= 0)
		ft_fail("Error: No data found.", list);
	verif_map(map, list, argc, argv);
	COEFF = PTNB * ROWNB > 4000 ? COEFF / 5 : COEFF * 6;
	return (split_to_int(map, list));
}

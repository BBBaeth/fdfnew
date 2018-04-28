/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:12:16 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/16 12:51:25 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	tab_color(long value, t_mlx *list)
{
	if (value > MINV + 150)
		return (0x61236C);
	if (value > MINV + 94)
		return (0x8D2984);
	if (value > MINV + 48)
		return (0xA52259);
	if (value > MAXV - MINV)
		return (0xC65353);
	else if (value > MINV + 19)
		return (0xFFAA10);
	else if (value > MINV + 15)
		return (0xFFDD23);
	else if (value > MINV + 7)
		return (0xDDEE44);
	else if (value > MINV)
		return (0x5965C);
	return (0x6699CC);
}

int		key_pressed(int key, t_mlx *list)
{
	if (key == 126 || key == 125)
		zoomin(list, key);
	else if (key == 14 || key == 8)
		coeff_change(list, key);
	else if (key == 1 || key == 0 || key == 13 || key == 2 || key == 7)
		move_image(key, list);
	return (0);
}

t_mlx	*mlx_new(void)
{
	t_mlx	*new;

	if (!(new = (t_mlx *)malloc(sizeof(t_mlx) * 1)))
		ft_fail("Error: Could not allocate memory.", NULL);
	new->mlx_ptr = NULL;
	new->win_ptr = NULL;
	new->img_ptr = NULL;
	new->img_data = NULL;
	new->tableau = NULL;
	new->read_this = NULL;
	return (new);
}

void	tuto_keys(t_mlx *list)
{
	if (KD == 1)
	{
		KD = 0;
		mlx_clear_window(MLX_PTR, WIN_PTR);
		image_replacer(list);
	}
	else if (KD == 0)
	{
		KD = 1;
		image_replacer(list);
	}
}

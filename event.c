/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:59:41 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/16 12:52:27 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coeff_change(t_mlx *list, int key)
{
	float		changer;
	int			limit;

	changer = 2.5;
	if ((key == 14 || key == 8) && PTNB * ROWNB >= 2500)
		changer = 0.02;
	limit = PTNB * ROWNB < 2500 ? 40 : 8;
	if (MAXV == MINV)
		ft_putstr_fd("State: Map is flat. No ratio to change.\n", 2);
	else
	{
		if (key == 14 && COEFF >= limit)
			ft_putstr_fd("State: Values ratio is already at its maximum.\n", 2);
		if (key == 14 && COEFF <= limit)
			COEFF += changer;
		if (key == 8 && COEFF <= limit * -1)
			ft_putstr_fd("State: Values ratio is already at its minimum.\n", 2);
		if (COEFF >= limit * -1 && key == 8)
			COEFF -= changer;
		if (COEFF < limit && COEFF > limit * -1)
			image_replacer(list);
	}
}

int		zoomin(t_mlx *list, int key)
{
	if (key == 126 && DIST < 100)
		list->gapx = list->gapx * 2;
	else if (key == 125 && DIST / 2 >= 1)
		list->gapx = list->gapx / 2;
	if (key == 126 && DIST < 100)
		DIST = DIST * 2;
	else if (DIST / 2 < 1)
	{
		ft_putstr_fd("State: Cannot zoom out more.\n", 2);
		return (0);
	}
	else if (key == 125)
		DIST = DIST / 2;
	else if (key == 126 && DIST >= 100)
	{
		ft_putstr_fd("State: Cannot zoom in more.\n", 2);
		return (0);
	}
	COEFF = key == 126 ? COEFF * 2 : COEFF / 2;
	if (DIST < 1)
		DIST = 1;
	image_replacer(list);
	return (1);
}

void	move_image(int key, t_mlx *list)
{
	if (key == 0)
		MVX -= 10;
	else if (key == 2)
		MVX += 10;
	else if (key == 13)
		MVY -= 10;
	else if (key == 7)
		MVY += 10;
	else if (key == 1)
	{
		MVX = ROWNB * list->gapy + 30;
		MVY = 50;
	}
	image_replacer(list);
}

int		key_manager(int key, void *list)
{
	if (key == 53 || key == 12)
		window_closed(list);
	else if (key == 40)
		tuto_keys(list);
	return (0);
}

int		window_closed(t_mlx *list)
{
	if (list != NULL)
	{
		close(FD);
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		if (TAB != NULL)
			ft_free_int(list);
		if (IMG_DATA != NULL)
			free(IMG_DATA);
		free(list);
		list = NULL;
	}
	ft_putstr_fd("State: fdf is now quitting properly.\n", 2);
	exit(0);
	return (0);
}

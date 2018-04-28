/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:11:56 by ceugene           #+#    #+#             */
/*   Updated: 2018/03/12 14:11:58 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		blue(long color)
{
	if (color == 0x61236C)
		return (97);
	else if (color == 0x8D2984)
		return (132);
	else if (color == 0xA52259)
		return (89);
	else if (color == 0xC65353)
		return (83);
	else if (color == 0xFFAA10)
		return (85);
	else if (color == 0xFFDD23)
		return (73);
	else if (color == 0xDDEE44)
		return (85);
	else if (color == 0x5965C)
		return (80);
	else if (color == 0xFFFFDD)
		return (255);
	return (204);
}

int		green(long color)
{
	if (color == 0x61236C)
		return (35);
	else if (color == 0x8D2984)
		return (41);
	else if (color == 0xA52259)
		return (34);
	else if (color == 0xC65353)
		return (83);
	else if (color == 0xFFAA10)
		return (153);
	else if (color == 0xFFDD23)
		return (187);
	else if (color == 0xDDEE44)
		return (238);
	else if (color == 0x5965C)
		return (200);
	else if (color == 0xFFFFDD)
		return (255);
	return (153);
}

int		red(long color)
{
	if (color == 0x61236C)
		return (108);
	else if (color == 0x8D2984)
		return (141);
	else if (color == 0xA52259)
		return (165);
	else if (color == 0xC65353)
		return (198);
	else if (color == 0xFFAA10)
		return (255);
	else if (color == 0xFFDD23)
		return (238);
	else if (color == 0xDDEE44)
		return (238);
	else if (color == 0x5965C)
		return (106);
	else if (color == 0xFFFFDD)
		return (230);
	return (102);
}

void	image_drawing(int x, int y, long color, t_mlx *list)
{
	int		pos;

	pos = (x * BPP) + (y * S_L);
	if (((unsigned int)x < LA) && (unsigned int)y < HA)
	{
		if (((unsigned int)x > 0 && (unsigned int)x <= LA)
			&& ((unsigned int)y > 0 && (unsigned int)y <= HA))
		{
			IMG_DATA[pos + 0] = (char)blue(color);
			IMG_DATA[pos + 1] = (char)green(color);
			IMG_DATA[pos + 2] = (char)red(color);
		}
	}
}

void	image_replacer(t_mlx *list)
{
	mlx_destroy_image(MLX_PTR, IMG_PTR);
	IMG_PTR = mlx_new_image(MLX_PTR, LA, HA);
	IMG_DATA = mlx_get_data_addr(IMG_PTR, &BPP, &S_L, &END);
	BPP /= 8;
	pt_generating(list);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	if (KD == 1)
		key_displayer(list);
}

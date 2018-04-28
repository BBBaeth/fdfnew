/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:11:12 by ceugene           #+#    #+#             */
/*   Updated: 2018/03/12 14:11:15 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_send_to_display(t_mlx *list, t_pt point1, t_pt point2)
{
	ft_receive_line(list, point1, point2);
}

void	*image_generating(void *mlx_ptr, int x, int y, void *win_ptr)
{
	void	*image_ptr;

	image_ptr = mlx_new_image(mlx_ptr, x, y);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 0, 0);
	mlx_clear_window(mlx_ptr, win_ptr);
	return (image_ptr);
}

int		reload_pic(t_mlx *list)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	if (KD == 1)
		key_displayer(list);
	return (0);
}

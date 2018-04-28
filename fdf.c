/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:00:14 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/21 18:38:01 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	let_mlx_loop(t_mlx *list)
{
	mlx_key_hook(WIN_PTR, &key_manager, list);
	mlx_hook(WIN_PTR, 17, 1L << 17, &window_closed, list);
	mlx_hook(WIN_PTR, 2, 1L << 0, &key_pressed, list);
	mlx_expose_hook(WIN_PTR, &reload_pic, list);
	mlx_loop(MLX_PTR);
}

void	ft_fail(char *str, t_mlx *list)
{
	ft_putstr_fd(str, 2);
	write(1, "\n", 1);
	if (list)
		ft_putstr_fd("State: fdf is now quitting properly.\n", 2);
	exit(0);
}

void	ft_init_var2(int argc, char **argv, t_mlx *list)
{
	if (argc >= 5 && ft_atoi(argv[4]) > -21 && ft_atoi(argv[4]) < 21)
		COEFF = ft_atoi(argv[4]);
	else
		COEFF = 0.469;
	MODE = 0;
	if (ft_strcmp(argv[argc - 1], "-NC") == 0)
		MODE = 1;
	KD = 1;
	MVX = 0;
	MVY = 0;
	list->custom_size = 0;
	LA = 0;
	HA = 0;
}

t_mlx	*ft_init_var(int argc, char **argv)
{
	t_mlx		*list;

	list = mlx_new();
	if (argc < 2)
	{
		ft_putstr_fd("Usage: fdf input_file [[[window width] [window", 2);
		ft_putstr_fd(" height]] [values ratio]] [-NC].\n", 2);
		exit(0);
	}
	NAME = argv[1];
	return (list);
}

int		main(int argc, char **argv)
{
	t_mlx		*list;

	list = ft_init_var(argc, argv);
	ft_init_var2(argc, argv, list);
	TAB = start_reading(argv[1], list, argc, argv);
	if (!(IMG_PTR = image_generating(MLX_PTR, LA, HA, WIN_PTR)))
		ft_fail("Error: Unable to generate image.", list);
	if (!(IMG_DATA = mlx_get_data_addr(IMG_PTR, &BPP, &S_L, &END)))
		ft_fail("Error: Unable to access image data.", list);
	BPP = BPP / 8;
	pt_generating(list);
	let_mlx_loop(list);
	return (0);
}

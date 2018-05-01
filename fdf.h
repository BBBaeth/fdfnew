/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:01:14 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/16 12:52:58 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define MLX_PTR list->mlx_ptr
# define WIN_PTR list->win_ptr
# define IMG_PTR list->img_ptr
# define IMG_DATA list->img_data
# define LA list->l
# define HA list->h
# define BPP list->bit_pix
# define S_L list->size_line
# define END list->endian
# define DIST list->distance
# define PTNB list->pt_nb
# define ROWNB list->row_nb
# define COEFF list->coefficient
# define TAB list->tableau
# define XO list->x_orgn
# define YO list->y_orgn
# define MINV list->min_value
# define MAXV list->max_value
# define MODE list->color_mode
# define NAME list->read_this
# define KD list->keys
# define FD list->file_desc
# define MVX list->move_x
# define MVY list->move_y

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	char			*read_this;
	long			l;
	long			h;
	unsigned int	distance;
	unsigned int	pt_nb;
	unsigned int	row_nb;
	int				bit_pix;
	int				size_line;
	int				endian;
	float			coefficient;
	int				**tableau;
	int				x_orgn;
	int				y_orgn;
	int				min_value;
	int				max_value;
	int				color_mode;
	int				keys;
	int				file_desc;
	int				move_x;
	int				move_y;
	int				gapx;
	int				gapy;
	int				custom_size;
}					t_mlx;

typedef struct		s_pt
{
	int				x;
	int				y;
	long			color;
	long			value;
}					t_pt;

void				ft_fail(char *str, t_mlx *list);
int					key_manager(int key, void *list);
void				*image_generating(void *mlxptr, int x, int y, void *winptr);
int					reload_pic(t_mlx *list);
int					**start_reading(char *str, t_mlx *list, int ac, char **av);
int					ft_receive_line(t_mlx *list, t_pt p1, t_pt p2);
int					ft_straight_line(t_mlx *list, t_pt p1, t_pt p2);
int					window_closed(t_mlx *param);
void				ft_send_to_display(t_mlx *list, t_pt p1, t_pt p2);
void				pt_generating(t_mlx *list);
int					**split_to_int(char **map, t_mlx *list);
t_mlx				*mlx_new();
long				ft_get_color(t_pt p1, t_pt p2, t_mlx *list);
void				ft_draw_bigmap(t_pt p1, t_pt p2, t_mlx *list);
void				small_angle(float dy, t_mlx *list, t_pt p1, t_pt p2);
void				large_angle(t_pt p1, t_pt p2, t_mlx *list);
void				sharp_angle(t_pt p1, t_pt p2, t_mlx *list);
void				ft_free_int(t_mlx *list);
void				image_replacer(t_mlx *list);
long				tab_color(long value, t_mlx *list);
void				get_the_mood(t_mlx *list);
void				image_drawing(int x, int y, long color, t_mlx *list);
void				tuto_keys(t_mlx *list);
void				key_displayer(t_mlx *list);
int					zoomin(t_mlx *list, int key);
void				coeff_change(t_mlx *list, int key);
void				move_image(int key, t_mlx *list);
int					key_pressed(int key, t_mlx *list);
int					set_window_size(t_mlx *list, int argc, char **argv);
void				minandmax(t_mlx *list);

#endif

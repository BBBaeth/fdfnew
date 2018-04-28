/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:12:01 by ceugene           #+#    #+#             */
/*   Updated: 2018/03/12 14:13:00 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	small_angle(float dy, t_mlx *list, t_pt p1, t_pt p2)
{
	float		pente;
	float		stamp;
	float		dx;
	int			growth_y;

	dx = p2.x > p1.x ? (p2.x - p1.x) : (p1.x - p2.x);
	growth_y = p2.y > p1.y ? 1 : -1;
	pente = (-dy) / 2;
	while (p1.x <= p2.x && p1.y != p2.y + growth_y)
	{
		p1.color = ft_get_color(p1, p2, list);
		image_drawing(p1.x, p1.y, p1.color, list);
		stamp = pente;
		if (stamp > -dx)
		{
			p1.x = p1.x + 1;
			pente = pente - dy;
		}
		if (stamp < dy)
		{
			pente = pente + dx;
			p1.y += growth_y;
		}
	}
}

int		ft_draw_line(t_mlx *list, t_pt p1, t_pt p2)
{
	float		dy;

	dy = p2.y > p1.y ? (p2.y - p1.y) : (p1.y - p2.y);
	small_angle(dy, list, p1, p2);
	return (0);
}

int		ft_straight_line(t_mlx *list, t_pt p1, t_pt p2)
{
	if (p1.x == p2.x)
	{
		while (p1.y <= p2.y && p2.x >= p1.x)
		{
			p1.color = ft_get_color(p1, p2, list);
			image_drawing(p1.x, p1.y, p1.color, list);
			p1.y = p1.y + 1;
		}
	}
	else
	{
		while (p1.x <= p2.x && p1.y != p2.y + 1)
		{
			p1.color = ft_get_color(p1, p2, list);
			image_drawing(p1.x, p1.y, p1.color, list);
			p1.x = p1.x + 1;
		}
	}
	return (0);
}

int		ft_receive_line(t_mlx *list, t_pt p1, t_pt p2)
{
	if (p1.x == p2.x)
	{
		if (p1.y <= p2.y)
			return (ft_straight_line(list, p1, p2));
		return (ft_straight_line(list, p2, p1));
	}
	if (p1.y == p2.y)
	{
		if (p1.x <= p2.x)
			return (ft_straight_line(list, p1, p2));
		return (ft_straight_line(list, p2, p1));
	}
	if (p1.x < p2.x)
		return (ft_draw_line(list, p1, p2));
	else
		return (ft_draw_line(list, p2, p1));
}

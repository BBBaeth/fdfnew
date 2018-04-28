/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:58:40 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/21 17:02:31 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	ft_get_color(t_pt p1, t_pt p2, t_mlx *list)
{
	int		factor;

	factor = 1;
	if (MAXV == MINV)
		return (0x6699CC);
	if (MAXV < 30)
		factor = 2;
	if (MODE == 1)
		return (0xFFFFDD);
	if (p1.value == p2.value)
		return (tab_color(p1.value * factor, list));
	else if (p1.value > p2.value)
		return (tab_color(p1.value * factor, list));
	else if (p2.value > p1.value)
		return (tab_color(p2.value * factor, list));
	return (tab_color(p1.value, list));
}

void	pt_placing(t_mlx *list, t_pt p1)
{
	t_pt			p2;
	t_pt			p3;

	p2.x = XO + (p1.x * list->gapx);
	p2.y = (YO + (p1.x * list->gapy)) - (TAB[p1.y][p1.x] * COEFF);
	p2.value = TAB[p1.y][p1.x];
	if (p1.y != 0)
	{
		p3.x = (XO + list->gapy) + (p1.x * list->gapx);
		p3.y = (YO - list->gapx) + (p1.x * list->gapy)
			- (TAB[p1.y - 1][p1.x] * COEFF);
		p3.value = TAB[p1.y - 1][p1.x];
		ft_send_to_display(list, p2, p3);
	}
	if ((unsigned int)(p1.x + 1) != PTNB)
	{
		p3.x = XO + ((p1.x + 1) * list->gapx);
		p3.y = YO + ((p1.x + 1) * list->gapy) - (TAB[p1.y][p1.x + 1] * COEFF);
		p3.value = TAB[p1.y][p1.x + 1];
		ft_send_to_display(list, p2, p3);
	}
}

void	pt_generating(t_mlx *list)
{
	t_pt				p1;

	minandmax(list);
	XO = MVX;
	YO = MVY;
	p1.y = 0;
	while ((unsigned int)p1.y < ROWNB)
	{
		p1.x = 0;
		while ((unsigned int)p1.x < PTNB)
		{
			pt_placing(list, p1);
			p1.x++;
		}
		p1.y++;
		XO -= list->gapy;
		YO += list->gapx;
	}
}

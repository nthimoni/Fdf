/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:02:56 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/13 06:00:01 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "img.h"
#include "colors.h"
#include "libft.h"
#include <math.h>

void	swap_p(t_2point *p1, t_2point *p2)
{
	t_2point	temp;

	temp.x = p1->x;
	temp.y = p1->y;
	p1->x = p2->x;
	p1->y = p2->y;
	p2->x = temp.x;
	p2->y = temp.y;
}

void	oct37(t_2point p1, t_2point p2, t_2point d, t_img *img)
{
	int	e;

	if (d.x < 0)
		swap_p(&p1, &p2);
	e = p2.x - p1.x;
	d.x = e * 2;
	d.y = (p2.y - p1.y) * 2;
	while (p1.x <= p2.x)
	{
		pix_put_img(p1.x, p1.y, GREEN, img);
		ft_printf(" %d %d \n", p1.x, p1.y);
		p1.x++;
		e -= d.y;
		if (e <= 0)
		{
			p1.y++;
			e += d.x;
		}
	}
	pix_put_img(p2.x, p2.y, WHITE, img);
}

void	draw_line(t_2point p1, t_2point p2, t_img *img)
{
	int	dx;
	int	dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if ((dx > 0 && dy >= 0) || (dx < 0 && dy <= 0))
	{
		if (abs(dx) >= abs(dy))
			oct37(p1, p2, (t_2point){p2.x - p1.x, p2.y - p1.y}, img);
		else
			ft_printf("");
	}
	else
	{
		if (abs(dy) > abs(dx))
			ft_printf("");
		else
			ft_printf("");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:02:56 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 03:30:50 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "img.h"
#include "colors.h"
#include "libft.h"
#include "utils.h"
#include <math.h>

void	oct1458(t_2point p1, t_2point p2, t_2point d, t_img *img)
{
	int	e;

	if (d.y < 0)
		swap_p(&p1, &p2, &d);
	e = d.y / 2;
	while (p1.y <= p2.y)
	{
		pix_put_img(p1.x, p1.y, GREEN, img);
		p1.y++;
		if (d.x > 0)
			e -= d.x;
		else
			e += d.x;
		if (e <= 0)
		{
			if (d.x > 0)
				p1.x++;
			else
				p1.x--;
			e += d.y;
		}
	}
	pix_put_img(p2.x, p2.y, GREEN, img);
}

void	oct2367(t_2point p1, t_2point p2, t_2point d, t_img *img)
{
	int	e;

	if (d.x < 0)
		swap_p(&p1, &p2, &d);
	e = d.x / 2;
	while (p1.x <= p2.x)
	{
		pix_put_img(p1.x, p1.y, GREEN, img);
		p1.x++;
		if (d.y > 0)
			e -= d.y;
		else
			e += d.y;
		if (e <= 0)
		{
			if (d.y > 0)
				p1.y++;
			else
				p1.y--;
			e += d.x;
		}
	}
	pix_put_img(p2.x, p2.y, GREEN, img);
}

void	draw_line(t_2point p1, t_2point p2, t_img *img)
{
	int	dx;
	int	dy;

	dx = (p2.x - p1.x) * 2;
	dy = (p2.y - p1.y) * 2;
	if ((dx > 0 && dy >= 0) || (dx < 0 && dy <= 0))
	{
		if (vabs(dx) >= vabs(dy))
			oct2367(p1, p2, (t_2point){dx, dy}, img);
		else
			oct1458(p1, p2, (t_2point){dx, dy}, img);
	}
	else
	{
		if (vabs(dy) > vabs(dx))
			oct1458(p1, p2, (t_2point){dx, dy}, img);
		else
			oct2367(p1, p2, (t_2point){dx, dy}, img);
	}
}

/*
void	oct15(t_2point p1, t_2point p2, t_2point d, t_img *img)
{
	int	e;

	if (d.y < 0)
		swap_p(&p1, &p2, &d);
	e = d.y / 2;
	while (p1.y <= p2.y)
	{
		pix_put_img(p1.x, p1.y, GREEN, img);
		p1.y++;
		e += d.x;
		if (e <= 0)
		{
			p1.x--;
			e += d.y;
		}
	}
	pix_put_img(p2.x, p2.y, GREEN, img);
}

void	oct26(t_2point p1, t_2point p2, t_2point d, t_img *img)
{
	int	e;

	if (d.x < 0)
		swap_p(&p1, &p2, &d);
	e = d.x / 2;
	while (p1.x <= p2.x)
	{
		pix_put_img(p1.x, p1.y, GREEN, img);
		p1.x++;
		e += d.y;
		if (e <= 0)
		{
			p1.y--;
			e += d.x;
		}
	}
	pix_put_img(p2.x, p2.y, GREEN, img);
}
*/

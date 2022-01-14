/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:34:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 08:27:07 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "img.h"
#include "fdf.h"
#include "error.h"
#include "constantes.h"

int	new_img(t_img *img, t_win *win)
{
	img->img = mlx_new_image(win->mlx, win->w, win->h);
	if (!img->img)
		return (error_msg(BAD_ALLOC));
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	img->w = win->w;
	img->h = win->h;
	return (1);
}

void	pix_put_img(int x, int y, int color, t_img *img)
{
	char	*dst;

	x += W_WIDTH / 2;
	y += W_HEIGHT / 2;
	if (x < 0 || x >= (int)img->w || y < 0 || y >= (int)img->h)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

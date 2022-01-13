/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:29:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/13 01:24:01 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

#include "fdf.h"

int		new_img(t_img *img, t_win *win);
void	pix_put_img(int x, int y, int color, t_img *img);

#endif

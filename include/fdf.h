/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:07:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 03:23:20 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_2point
{
	int	x;
	int	y;
}	t_2point;

typedef struct s_map
{
	t_point	**map;
	t_point	max;
	char	*path;
}	t_map;

typedef struct s_line
{
	t_2point	p1;
	t_2point	p2;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	size_t	w;
	size_t	h;
}	t_img;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	size_t	w;
	size_t	h;
}	t_win;

typedef struct s_prog
{
	t_map	map;
	t_win	win;
	t_img	*img;
	t_img	*buf;
}	t_prog;

#endif

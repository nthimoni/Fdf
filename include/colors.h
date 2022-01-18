/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:28:17 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 02:18:57 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define STD_COLOR 0x6DCBD0

# ifdef FR_S // MAP FRANCE BLEU / ROUGE
#  define GROUND_C 0x002389DA
#  define GROUND_MAX 0
#  define LVL_1_C 0x00F9A1A1
#  define LVL_1_MAX 50
#  define LVL_2_C 0x00AE2525
# elif defined M_42 // PURPLE / ORANGE
#  define GROUND_C 0x00581845
#  define GROUND_MAX 0
#  define LVL_1_C 0x00FF5733
#  define LVL_1_MAX 50
#  define LVL_2_C 0x00FF5733
# endif

# include "fdf.h"

int				mkcolor(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t(int color);
unsigned char	get_r(int color);
unsigned char	get_g(int color);
unsigned char	get_b(int color);
void			set_color(t_map *map);
int				mix_color(int c1, int c2);
void			fill_point(t_point *pnt, char *line, int i, int u);

#endif

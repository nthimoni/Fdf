/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:28:17 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 23:46:14 by nthimoni         ###   ########.fr       */
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
#  define GROUND_H 0
#  define LVL_1_C 0x00F5d3d3
#  define LVL_2_H 70
#  define LVL_2_C 0x00D92323
#  define LVL_3_C 0x00C71818
#  define LVL_4_C 0x00300101
# elif defined M_42 // PURPLE / ORANGE
#  define GROUND_C 0x00581845
#  define GROUND_H 0
#  define LVL_1_C 0x00FF5733
#  define LVL_2_H 50
#  define LVL_2_C 0x00FF5733
#  define LVL_3_C 0x00FF5733
#  define LVL_4_C 0x00690404
# endif

# include "fdf.h"

int				mkcolor(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t(int color);
unsigned char	get_r(int color);
unsigned char	get_g(int color);
unsigned char	get_b(int color);
int				mix_color(int c1, int c2, float f);
void			fill_point(t_map *map, char *line, int i, int u);

#endif

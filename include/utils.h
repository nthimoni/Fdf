/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:31:09 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 23:17:45 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_2point	pt(int x, int y);
int			vabs(int a);
void		swap_p(t_2point *p1, t_2point *p2, t_2point *d);
void		get_max_z(t_map *map, char *line);

#endif

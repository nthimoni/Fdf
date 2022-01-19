/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:25:42 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/19 15:53:38 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_2point	pt(int x, int y)
{
	return ((t_2point){x, y});
}

int	vabs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	swap_p(t_2point *p1, t_2point *p2, t_2point *d)
{
	int	temp;

	temp = p1->x;
	p1->x = p2->x;
	p2->x = temp;
	temp = p1->y;
	p1->y = p2->y;
	p2->y = temp;
	d->x = -d->x;
	d->y = -d->y;
}

void	get_max_z(t_map *map, char *line)
{
	char	**words;
	int		i;

	i = 0;
	words = ft_split(line, ' ');
	if (!words)
		return ;
	while (words[i])
	{
		if (map->max.z < ft_atoi(words[i]))
			map->max.z = ft_atoi(words[i]);
		free(words[i++]);
	}
	free(words);
}

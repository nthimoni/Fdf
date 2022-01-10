/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:14:48 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/10 20:57:08 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"


static int get_map_size(t_map *map, char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 0;
	while (line[i])
		if (line[i++] == ' ')
			map->max.x++;
	i++;
	while (line)
	{
		map->max.y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static int map_alloc(t_map *map)
{
	int	i;
	map->map = malloc(sizeof(t_point *) * map->max.y);
	if (!map->map)
		return (0);
	i = 0;
	while (i < map->max.y)
	{
		map->map[i] = malloc(sizeof(t_point *) * map->max.x);
		if (map->max.
	}
}

int	fill_map(t_map *map, char *file)
{
	
}

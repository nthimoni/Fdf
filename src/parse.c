/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:14:48 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/10 07:09:30 by nthimoni         ###   ########.fr       */
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
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line[i])
		if (line[i++] == ' ')
			map->max.x++;
	i++;
	while (line)
	{
		map->map.y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int map_alloc(t_map *map)
{

}

int	fill_map(t_map *map, char *file)
{
	
}

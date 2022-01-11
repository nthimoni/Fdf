/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:14:48 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/11 06:30:16 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

static int	get_map_size(t_map *map, char *file)
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
	{
		if (line[i] == ' ' && (i == 0 || line[i - 1] != ' '))
			map->max.x++;
		i++;
	}
	map->max.x++;
	while (line)
	{
		map->max.y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static int	free_part_map(t_map *map, int i)
{
	while (--i >= 0)
		free(map->map[i]);
	free(map->map);
	return (0);
}	

static int	map_alloc(t_map *map)
{
	int	i;

	map->map = malloc(sizeof(t_point *) * map->max.y);
	if (!map->map)
		return (0);
	i = 0;
	while (i < map->max.y)
	{
		map->map[i] = malloc(sizeof(t_point) * map->max.x);
		if (!map->map[i])
			return (free_part_map(map, i));
		i++;
	}
	return (1);
}

static void	fill_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	**words;
	int		i;
	int		u;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	u = 0;
	while (line)
	{
		i = 0;
		words = ft_split(line, ' ');
		while (words[i])
		{
			map->map[u][i].x = i;
			map->map[u][i].y = u;
			map->map[u][i].z = ft_atoi(words[i]);
			i++;
		}
		line = get_next_line(fd);
		u++;
	}
	close(fd);
}

int	parse_map(t_map *map, char *file)
{
	if (!get_map_size(map, file))
		return (0);
	if (!map_alloc(map))
		return (0);
	fill_map(map, file);
	return (1);
}

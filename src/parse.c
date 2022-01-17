/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:14:48 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/17 22:53:50 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"
#include "constantes.h"

static int	get_map_size(t_map *map, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (MAP_FORMAT);
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
		free(line);
		map->max.y++;
		line = get_next_line(fd);
	}
	return (0);
}

static int	free_part_map(t_map *map, int i)
{
	while (--i >= 0)
		free(map->map[i]);
	free(map->map);
	return (BAD_ALLOC);
}	

static int	map_alloc(t_map *map)
{
	int	i;

	map->map = malloc(sizeof(t_point *) * map->max.y);
	if (!map->map)
		return (BAD_ALLOC);
	i = 0;
	while (i < map->max.y)
	{
		map->map[i] = malloc(sizeof(t_point) * map->max.x);
		if (!map->map[i])
			return (free_part_map(map, i));
		i++;
	}
	return (0);
}

int	fill_map(t_map *map, int fd, int u)
{
	char	*line;
	char	**words;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		words = ft_split(line, ' ');
		free(line);
		if (!words)
			return (BAD_ALLOC);
		while (words[i])
		{
			map->map[u][i].x = (float)(i * X_SC);
			map->map[u][i].y = (float)(u * Y_SC);
			map->map[u][i].z = (float)(ft_atoi(words[i]) * Z_SC);
			free(words[i++]);
		}
		free(words);
		line = get_next_line(fd);
		u++;
	}
	return (0);
}

int	parse_map(t_map *map, char *file)
{
	int	error;
	int	fd;

	map->max.x = 0;
	map->max.y = 0;
	map->path = file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (INV_ARG);
	error = get_map_size(map, fd);
	close(fd);
	if (error)
		return (error);
	error = map_alloc(map);
	if (error)
		return (error);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (INV_ARG);
	error = fill_map(map, fd, 0);
	close(fd);
	if (error)
		return (error);
	return (0);
}

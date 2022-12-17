/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:40:03 by yongmipa          #+#    #+#             */
/*   Updated: 2022/12/17 17:40:05 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	parse_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	map->str = get_next_line(fd);
	if (!map->str)
		error("Failed to read file");
	map->width = ft_strlen(map->str);
	map->height = 1;
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map->str;
		map->str = ft_strjoin(map->str, line);
		if (!map->str)
			error("Failed to read file");
		free(line);
		free(temp);
		(map->height)++;
	}
	close(fd);
}

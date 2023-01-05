/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:48:44 by yongmipa          #+#    #+#             */
/*   Updated: 2023/01/05 15:29:06 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	**make_visited(t_map *map)
{
	int		**ret;
	size_t	i;

	ret = malloc(sizeof(int *) * map->height + 1);
	i = -1;
	while (++i < map->height)
		ret[i] = ft_calloc(sizeof(int), map->width);
	ret[i] = NULL;
	return (ret);
}

char	**make_mapstr(t_map *map)
{
	char	**ret;
	size_t	i;

	ret = malloc(map->height + 1);
	i = -1;
	while (++i < map->height)
		ret[i] = ft_substr(map->str + i * map->width, 0, map->width);
	ret[i] = NULL;
	return (ret);
}

int	*get_player_pos(t_map *map, char **map_str)
{
	int	x;
	int	y;
	int	*ret;

	ret = malloc(8);
	y = -1;
	while (++y < (int)map->height)
	{
		x = -1;
		while (++x < (int)map->width)
		{
			if (map_str[y][x] == 'P')
			{
				ret[0] = x;
				ret[1] = y;
				return (ret);
			}
		}
	}
	return (ret);
}

int	is_check_target(char c)
{
	if (c == 'E' || c == 'C')
		return (TRUE);
	return (FALSE);
}

void	dfs(t_dfs *dfs_struct, int x, int y)
{
	if (dfs_struct->map[y][x] == '1' || dfs_struct->visited[y][x] == 1)
		return ;
	dfs_struct->visited[y][x] = 1;
	if (is_check_target(dfs_struct->map[y][x]))
		dfs_struct->table[(unsigned char)dfs_struct->map[y][x]]++;
	dfs(dfs_struct, x + 1, y);
	dfs(dfs_struct, x - 1, y);
	dfs(dfs_struct, x, y + 1);
	dfs(dfs_struct, x, y - 1);
}

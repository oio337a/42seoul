/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:41:00 by yongmipa          #+#    #+#             */
/*   Updated: 2022/12/17 17:41:01 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangle(t_map *map)
{
	if (map->width * map->height != ft_strlen(map->str))
		return (FALSE);
	return (TRUE);
}

static int	is_walls_surrounded(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->str[i] != '\0')
	{
		if (i < map->width)
		{
			if (map->str[i] != '1')
				return (FALSE);
		}
		else if (i % map->width == 0 || i % map->width == map->width - 1)
		{
			if (map->str[i] != '1')
				return (FALSE);
		}
		else if (i > ft_strlen(map->str) - map->width)
		{
			if (map->str[i] != '1')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	is_all_char_valid(t_map *map, int cnt[])
{
	size_t	sum;

	sum = cnt['P'] + cnt['E'] + cnt['C'] + cnt['1'] + cnt['0'];
	if (ft_strlen(map->str) != sum)
		return (FALSE);
	if (cnt['P'] != 1 || cnt['E'] == 0 || cnt['C'] == 0)
		return (FALSE);
	return (TRUE);
}

int	is_arguments_valid(int argc, char *filename)
{
	size_t	len;

	if (argc != 2)
		return (FALSE);
	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (FALSE);
	return (TRUE);
}

int	is_map_valid(t_map *map)
{
	int		cnt[256];
	size_t	i;

	if (!is_rectangle(map))
		return (FALSE);
	if (!is_walls_surrounded(map))
		return (FALSE);
	i = 0;
	while (i < 256)
		cnt[i++] = 0;
	i = -1;
	while (map->str[++i] != '\0')
	{
		if (map->str[i] == 'P')
			map->p_pos = i;
		cnt[(unsigned char) map->str[i]]++;
	}
	map->coll_sum = cnt['C'];
	if (!is_all_char_valid(map, cnt))
		return (FALSE);
	return (TRUE);
}

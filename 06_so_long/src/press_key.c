/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:40:31 by yongmipa          #+#    #+#             */
/*   Updated: 2022/12/28 16:37:59 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	clear_game(t_game *game)
{
	game->move_cnt++;
	printf("%zu \n", game->move_cnt);
	printf("game clear!\n");
	exit(0);
}

static size_t	find_move_position(t_map *map, int keycode)
{
	size_t	i;

	if (keycode == KEY_W)
		i = map->p_pos - map->width;
	else if (keycode == KEY_A)
		i = map->p_pos - 1;
	else if (keycode == KEY_S)
		i = map->p_pos + map->width;
	else if (keycode == KEY_D)
		i = map->p_pos + 1;
	else
		i = INVALID_KEYCODE;
	return (i);
}

int	press_key(int keycode, t_game *game)
{
	t_map	*map;
	size_t	i;

	if (keycode == KEY_ESC)
		exit_game(game);
	map = game->map;
	i = find_move_position(map, keycode);
	if (i == INVALID_KEYCODE)
		return (0);
	if (map->str[i] == 'C')
		game->coll_cnt++;
	if (map->str[i] == 'E' && map->coll_sum == game->coll_cnt)
		clear_game(game);
	else if (map->str[i] != '1' && map->str[i] != 'E')
	{
		map->str[map->p_pos] = '0';
		map->str[i] = 'P';
		map->p_pos = i;
		game->move_cnt++;
		printf("%zu \n", game->move_cnt);
		draw_map(game->map, game->img, game->mlx, game->win);
	}
	return (0);
}

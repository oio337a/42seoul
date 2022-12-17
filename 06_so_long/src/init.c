/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:39:15 by yongmipa          #+#    #+#             */
/*   Updated: 2022/12/17 17:39:20 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

t_game	*game_init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error("Memory allocation failed");
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		error("Memory allocation failed");
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		error("Memory allocation failed");
	game->move_cnt = 0;
	game->coll_cnt = 0;
	return (game);
}

void	img_init(t_img *img, void *mlx)
{
	int	w;
	int	h;

	img->wall = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &w, &h);
	img->land = mlx_xpm_file_to_image(mlx, "./imgs/land.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(mlx, "./imgs/exit.xpm", &w, &h);
	img->cha = mlx_xpm_file_to_image(mlx, "./imgs/character.xpm", &w, &h);
	img->coll = mlx_xpm_file_to_image(mlx, "./imgs/collect.xpm", &w, &h);
}

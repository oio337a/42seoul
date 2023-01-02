/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:24:51 by yongmipa          #+#    #+#             */
/*   Updated: 2023/01/02 18:30:18 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

static void	*new_window(void *mlx, size_t width, size_t height)
{
	void	*win;

	win = mlx_new_window(mlx, width * 64, height * 64, "./so_long");
	return (win);
}

static int	is_arguments_valid(int argc, char *filename)
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

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (!is_arguments_valid(argc, argv[1]))
		exit(print_error("bad arguments"));
	game = game_init();
	parse_map(game->map, argv[1]);
	if (!is_map_valid(game->map))
		exit(print_error("Invalid map"));
	game->mlx = mlx_init();
	game->win = new_window(game->mlx, game->map->width, game->map->height);
	img_init(game->img, game->mlx);
	draw_map(game->map, game->img, game->mlx, game->win);
	mlx_hook(game->win, KEY_PRESS, 0, press_key, game);
	mlx_hook(game->win, DESTROY_NOTIFY, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

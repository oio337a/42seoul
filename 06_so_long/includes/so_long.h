/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:58:08 by yongmipa          #+#    #+#             */
/*   Updated: 2022/12/17 18:01:32 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stddef.h>
# include <mlx.h>

# define KEY_PRESS			2
# define DESTROY_NOTIFY		17

# define INVALID_KEYCODE	0

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define TRUE	1
# define FALSE	0

# define IMG_ARRAY_SIZE	81

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	*str;
	size_t	p_pos;
	size_t	coll_sum;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*land;
	void	*exit;
	void	*pac;
	void	*coll;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	size_t	move_cnt;
	size_t	coll_cnt;
}	t_game;

t_game	*game_init(void);
void	img_init(t_img *img, void *mlx_ptr);
int		is_map_valid(t_map *map);
int		is_arguments_valid(int argc, char *filename);
void	parse_map(t_map *map, char *filename);
void	draw_map(t_map *map, t_img *img, void *m, void *w);
int		press_key(int keycode, t_game *game);
int		exit_game(t_game *game);
int		clear_game(t_game *game);
void	error(char *msg);

#endif

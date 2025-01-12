/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:12:01 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/11 15:44:43 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_image_pos(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"images/player_up.xpm", &x, &y);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"images/player_down.xpm", &x, &y);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"images/player_right.xpm", &x, &y);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"images/player_left.xpm", &x, &y);
}

int	load_image(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->map)
		return (-1);
	x = 64;
	y = 64;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &x,
			&y);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "images/empty.xpm", &x,
			&y);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/gate.xpm", &x,
			&y);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"images/collectible.xpm", &x, &y);
	player_image_pos(game);
	if (!game->img_wall || !game->img_floor || !game->img_exit
		|| !game->img_collectible)
	{
		ft_printf("Error in images\n");
		return (-1);
	}
	return (1);
}

int	put_img_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game || !game->map)
		return (-1);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_images_win(game, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

void	put_images_win(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall, j
			* 64, i * 64);
	if (game->map[i][j] == '0' || game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, j
			* 64, i * 64);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_exit, j
			* 64, i * 64);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player_up, j
			* 64, i * 64);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_collectible,
			j * 64, i * 64);
}
